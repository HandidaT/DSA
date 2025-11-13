#include <iostream>
#include <string>
#include <set>
#include <vector>

int main(){
    std::vector<std::string> chars();
    std::vector<int> countarr();
    std::string:: iterator it1;
    
    std::string b="balloon";
    std::cout<<b.size();
    std::cout<<"\n\n";
    std::set<char> s1;
    s1.insert('e');
    for (it1 = b.begin() ; it1 != b.end() ; it1++ ) 
    {
        std::cout << *it1<<" ";
        char temp=*it1;//.data();
        s1.insert(temp);
    }
    
    std::cout<<"\n\n\n";

    //Iterate through set
    std::set<char>::iterator it2;
    for (it2 = s1.begin() ; it2 != s1.end() ; it2++ ) 
    {
        std::cout << *it2<<" ";
    }

    std::string t="e";
}