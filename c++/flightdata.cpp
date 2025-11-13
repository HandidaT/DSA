#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "mysql_connection.h"
#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <nlohmann/json.hpp>
//using json = nlohmann::json;
using json = nlohmann::ordered_json;

//g++ flightdata.cpp -lmysqlcppconn

class FlightData{
public:
	int hr,min,sec;
	std::string am_pm;
	std::string  Time;
	std::string  Latitude;
	std::string  Longitude;
	std::string Course;
	std::string  kts;
	std::string  mph;
	std::string  AltitudeFeet;
	std::string Reporting_Facility;
	
	void hr_min_sec(){
		std::stringstream ss1(Time),ss2(Time);
		std::string str;
		getline(ss1,str,':');
		hr=stoi(str);
		getline(ss1,str,':');
		min=stoi(str);
		getline(ss1,str,':');
		sec=stoi(str);
		getline(ss2,am_pm,' ');
		getline(ss2,am_pm,' ');
	}
};

void insert(std::vector<FlightData>& data, std::fstream& fptr){
     std::string line;
     getline(fptr,line,'\n');//reading and discarding header row
     while(fptr.good()){//std::cout<<"\n";
     	getline(fptr,line,'\n');
     	std::stringstream ss(line);
		FlightData dataobj;
		getline(ss,dataobj.Time,',');
		getline(ss,dataobj.Latitude,',');
		getline(ss,dataobj.Longitude,',');
		getline(ss,dataobj.Course,',');
		getline(ss,dataobj.kts,',');
		getline(ss,dataobj.mph,',');
		getline(ss,dataobj.AltitudeFeet,',');
		getline(ss,dataobj.Reporting_Facility,',');
		dataobj.hr_min_sec();
		data.push_back(dataobj);
     }
}

bool compare(const FlightData& d1, const FlightData& d2){
	if (d1.am_pm  < d2.am_pm) return true;
	if (d1.am_pm == d2.am_pm && d1.hr  < d2.hr) return true;
	if (d1.am_pm == d2.am_pm && d1.hr == d2.hr && d1.min<d2.min) return true;
	if (d1.am_pm == d2.am_pm && d1.hr == d2.hr && d1.min==d2.min && d1.sec<d2.sec) return true;
	return false;
}

void writeto_json(std::vector<FlightData>& data,int size){
	json jdata;
	for (int i=0; i < size; i++){
		if(i<(size-2))
			jdata[data[i].Time]={{{"type","point"},{"coordinates",{data[i].Latitude,data[i].Longitude}}}
							,{{"type","linestring"},{"coordinates",{data[i].Latitude,data[i].Longitude,data[i+1].Latitude,data[i+1].Longitude}}}
							,{"Reporting facility",data[i].Reporting_Facility}};
		else
			jdata[data[i].Time]={{{"type","point"},{"coordinates",{data[i].Latitude,data[i].Longitude}}}
							,{{"type","linestring"},{"coordinates",{data[i].Latitude,data[i].Longitude,"NA","NA"}}}
							,{"Reporting facility",data[i].Reporting_Facility}};
		
	}
	std::ofstream o("geojson.json");
	o << std::setw(4) << jdata << std::endl;
	o.close();
}

void writeto_mysql(std::vector<FlightData>& data){
	sql::mysql::MySQL_Driver *driver;
	sql::Connection *connect;
	sql::PreparedStatement *pstmt;
	try {     
		driver = sql::mysql::get_driver_instance();
		connect=driver->connect("tcp://127.0.0.1:3306", "root", "grsUYM1$#4");
		connect->setSchema("NZ5_flightdata");
		pstmt = connect->prepareStatement("INSERT INTO data1(time,latitude,longitude,course,kts,mph,altitudefeet,reportingfacility) VALUES (?,?,?,?,?,?,?,?)");
		for (int i = 0; i < data.size(); i++) {
			pstmt->setString(1, data[i].Time);
			pstmt->setString(2, data[i].Latitude);
			pstmt->setString(3, data[i].Longitude);
			pstmt->setString(4, data[i].Course);
			pstmt->setString(5, data[i].kts);
			pstmt->setString(6, data[i].mph);
			pstmt->setString(7, data[i].AltitudeFeet);
			pstmt->setString(8, data[i].Reporting_Facility);
			pstmt->executeUpdate();
		}
		delete pstmt;
		delete connect;
	}catch (sql::SQLException &e) {
		  std::cout << "# ERR: SQLException in " << __FILE__;
		  std::cout << "(" << __FUNCTION__ << ") on line "<< __LINE__ << std::endl;
		  std::cout << "# ERR: " << e.what();
		  std::cout << " (MySQL error code: " << e.getErrorCode();
		  std::cout << ", SQLState: " << e.getSQLState() <<" )" << std::endl;
	}
}

int main(){
     std::fstream fptr("Programming Assignment - 1 - NZ5_flightdatar.csv",std::ios::in );
     if(!fptr.is_open()) std::cout<<"Error opening file!\n";
     std::vector<FlightData> data;
     insert(data,fptr);
     fptr.close();
     int size=data.size();
	std::cout<<size;
     
     std::sort(data.begin(),data.end(),compare);
     
	writeto_json(data,size);
	writeto_mysql(data);
}
