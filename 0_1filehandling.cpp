//a1r28c0
#include <string>
#include <fstream>
#include <iostream>
#include <filesystem>

int main(){
  int check;
  std::string dirname = "geeskforgeeks";

  try{
    std::filesystem::create_directory(dirname);
  }catch(const std::exception& e){
    std::cout << "Exception " << e.what() << "\n";
  }catch(...){
    std::cout << "Unknown exception\n";
  }

  std::string fileName = dirname+"/hi.txt";
  std::fstream outFile(fileName.c_str(), std::ios::out | std::ios::trunc);

  if(!outFile.is_open()){
    std::cout << "Couldn't open file\n";
    return 1;
  }


  outFile << "hi gigity there";
  outFile.close();

  return 0;
}
