// unordered_map::find
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<int,std::string> mymap = {
     {2,"mom"},
     {3,"dad"},
     {6,"bro"} };

  int input=2;

  std::unordered_map<int,std::string>::const_iterator got = mymap.find (input);

  if ( got == mymap.end() )
    std::cout << "not found";
  else
    std::cout << got->first << " is " << got->second;

  std::cout << std::endl;

  return 0;
}
