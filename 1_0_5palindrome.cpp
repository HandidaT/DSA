#include <iostream>


std::string isPalindrome(std::string s){
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) return "false";
	}
	return "true";
}

int main(){
	std::string s;
	std::cin>>s;
	std::cout<<isPalindrome(s);
}
