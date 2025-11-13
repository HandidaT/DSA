#include <iostream>

int main(){
	std::cout<<10/(4)<<"\n";
}

/*
int reverse(int input){
   int rev=0;
   while(input!=0){//if the input has zero at either ends, this is not working
                  //ex 2340, 03287,etc.
      rev=(rev*10)+(input%10);
      input=input/10;//returns int if both numaretor and denominator is int, even if result should be flaot
   }
   return rev;
}

int main(){
   int input;
   std::cin>>input;
   std::cout<<reverse(input);
}*/
