#include <iostream>
//#include <bits/stdc++.h>
#include <sstream>
#include <vector>
#include <string>

//using namespace std;


int main(){
   std::string a[]={"bat","gta","mega","atmel"},temp;
    int n = (sizeof(a)/sizeof(a[0])) -1;
    std::cout << "Array length is: " << n+1<<"\n";
    for(int i=0;i<n;i++){
      for(int j=0;j<n-i;j++){
         if(a[j]>a[j+1]){
           temp=a[j];
           a[j]=a[j+1];
           a[j+1]=temp;
         }
      }
    }
    for(int i=0;i<=n;i++){
       std::cout<<a[i]<<" ";
    }
}
