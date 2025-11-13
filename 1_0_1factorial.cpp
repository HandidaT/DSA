#include <iostream>

int factorial_recursive(int num){
	if(num==0) return 1;
	return num * factorial_recursive(num-1);
}

int factorial_iterative(int num){
	
}

int main(){
	
}





















































/*
int factorial_recursive(int num){
	if(num==0) return 1;
	return num * factorial_recursive(num-1);
}

int factorial_iterative(int num){
	int factorial,temp1=1;
	if(num==0) factorial=1;
	else{
		factorial=num;
		while(temp1<num){
			factorial=factorial*(num-temp1);
			temp1++;
		}
	}
	return factorial;
}

int main(){
	int num;
	std::cin>>num;
	std::cout<<factorial_iterative(num)<<" This is iterative factorial\n";
	std::cout<<factorial_recursive(num)<<"This is recursive factorial\n";
}
*/
