#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

void tokens_stream(string s){
   stringstream ss(s);
   string word;
   while(ss>>word){
      cout<<word<<endl;
   }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
/*
    string a;
    getline(cin,a);
    cout<<a<<"--";
    cout<<a[a.length()-1]<<"--\n";
    cout<<strtoq(a, "-");*/

   //string b="hello world hi!";
   //tokens_stream(b);
int main()
{
    int n, q,i;
    cin>>n>>q;
    string temp;
    vector<string> hrml;
    vector<string> quer;
    cin.ignore();

    for(i=0;i<n;i++)
    {
        getline(cin,temp);
        hrml.push_back(temp);
    }
    for(i=0;i<q;i++)
    {
        getline(cin,temp);
        quer.push_back(temp);
    }

    map<string, string> m;
    vector<string> tag;

    for(i=0;i<n;i++)
    {
        temp=hrml[i];
        temp.erase(remove(temp.begin(), temp.end(), '\"' ),temp.end());
        temp.erase(remove(temp.begin(), temp.end(), '>' ),temp.end());

        if(temp.substr(0,2)=="</")
        {
            tag.pop_back();
        }
        else
        {
            stringstream ss;
            ss.str("");
            ss<<temp;
            string t1,p1,v1;
            char ch;
            ss>>ch>>t1>>p1>>ch>>v1;
            string temp1="";
            if(tag.size()>0)
            {
                temp1=*tag.rbegin();
                temp1=temp1+"."+t1;
            }
            else
            {
                temp1=t1;
            }
            tag.push_back(temp1);
            m[*tag.rbegin()+"~"+p1]=v1;
            while(ss)
            {
                ss>>p1>>ch>>v1;
                m[*tag.rbegin()+"~"+p1]=v1;
            }
        }

    }

    for(i=0;i<q;i++)
    {
        if (m.find(quer[i]) == m.end())
        {
            cout << "Not Found!\n";
        }
        else
        {
            cout<<m[quer[i]]<<endl;
        }
    }
    return 0;
}
/*
    int N,Q;
    cin>>N>>Q;
    vector<string> a[N];
    string del=" ";
    for(int i=0;i<=N;i++){
       cout<<i<<endl;
       string temp;
       getline(cin,temp);
       //a[i].push_back(temp);

       int start = 0;
       int end = temp.find(del);
       while (end != -1) {
        string temp2= temp.substr(start, end - start);
        cout << temp2<<endl;
        a[i].push_back(temp2);
        start = end + del.size();
        end = temp.find(del, start);
       }
    cout << temp.substr(start, end - start)<<"---";
    }
    int r,k;
    for(k = 0; k < Q; k++){
        cin>>r;
        //cout << a[1][1] << endl;
    }*/

/*
  std::string name;

  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,name);
  std::cout << "Hello, " << name << "!\n";*/
   return 0;
}
