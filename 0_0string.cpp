#include <iostream>
#include <sstream>
#include <algorithm>

void tokenize(const std::string& str, const char delimeter){
    std::stringstream ss(str);
    
	std::string token;
	while(std::getline(ss, token, delimeter)){
		std::cout << token << std::endl;
	}
}

void reverseWords(std::string& str){
	//Step1: Reverse the entire string. 
	std::reverse(str.begin(), str.end());//Step2:Reverse each individual word within the reversed string.
	size_t start = 0;
	for (size_t end = 0; end < str.size(); ++end) {
		if (str[end] == ' ') {
			std::reverse(str.begin() + start, str.begin() + end);
			start = end + 1;
		}
	}// Reverse the last word (or the only word if there's just one)
	std::reverse(str.begin() + start, str.end());
}

int no_of_words(const std::string& str){
    int count=0;
	std::stringstream ss(str);
    std::string word;
	while(ss >> word){
		count++;
	}

	return count;
}

int main(){
	std::string str;
	std::getline(std::cin, str);

    // std::cout << no_of_words(str);
	tokenize(str, 't');

}

// void tokenize(std::string s, std::string del = " "){
//   int start, end = -1*del.size();
//   do{
//     start = end + del.size();
//     end = s.find(del, start);
//     std::cout << s.substr(start, end-start) << std::endl;
//   }while(end != std::string::npos);
// }

// int splitstring(std::string s){
// 	int count=0;
// 	std::stringstream ss(s);
// 	std::string word;
// 	while(ss>>word){
// 		count++;
// 	}
// 	return count;
// }

// int main(){
// 	std::string str;
// 	std::getline(std::cin,str);
// 	std::cout<<"number of words are: "<<splitstring(str)<<std::endl;
	
// 	//split with any delimeter
// 	std::string str2 = "How$%do$%you$%do$%!!!";
// 	tokenize(str2, "$%");
// 	std::cout << std::endl;

//   // std::string a="PM",b="AM";
//   // if(a<b) std::cout<<"less";
//   // else std::cout<<"greater";
// }
