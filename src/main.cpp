#include <iostream>
#include <chrono>

#include "WriteCheck.hpp"

bool tester(double input, std::string compare){
  std::cout << "INPUT: " << input << std::endl;
  std::cout << "Expected " << compare << ": ";
  std::string output = WriteCheck::processCheck(input);
  if(output == compare){
    std::cout << "SUCCESS" << std::endl;
    return true;
  } else{
    std::cout << "FAILED" << std::endl;
    std::cout << output << " returned instead" << std::endl;
    return false;
  }
}

int main(int argc, char *argv[]){
  try{
    if(argc > 1){
      std::cout << WriteCheck::processCheck(std::stod(argv[1])) << std::endl;
    }
    int totalTests = 10;
    int numberPassed = 0;
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "-----------------Starting Testing------------------" << std::endl;
    if(tester(123.45, "One Hundred Twenty Three Dollars and Forty Five Cents")) {numberPassed++;}
    std::cout << std::endl;
    if(tester(0.12, "Zero Dollars and Twelve Cents")) {numberPassed++;}
    std::cout << std::endl;
    if(tester(123456.78, "One Hundred Twenty Three Thousand Four Hundred Fifty Six Dollars and Seventy Eight Cents")) {numberPassed++;}
    std::cout << std::endl;
    if(tester(12.34, "Twelve Dollars and Thirty Four Cents")) {numberPassed++;}
    std::cout << std::endl;
    if(tester(0.00, "Zero Dollars and Zero Cents")) {numberPassed++;}
    std::cout << std::endl;
    if(tester(25.00, "Twenty Five Dollars and Zero Cents")) {numberPassed++;}
    std::cout << std::endl;
    //if(tester(1000000, "One Million Dollars and One Cents")) {numberPassed++;}
    if(tester(999999.99, "Nine Hundred Ninety Nine Thousand Nine Hundred Ninety Nine Dollars and Ninety Nine Cents")) {numberPassed++;}
    std::cout << std::endl;
    if(tester(1.0, "One Dollars and Zero Cent")) {numberPassed++;}
    std::cout << std::endl;
    if(tester(571.26, "Five Hundred Seventy One Dollars and Twenty Six Cents")) {numberPassed++;}
    std::cout << std::endl;
    if(tester(5.01, "Five Dollars and One Cents")) {numberPassed++;}
    std::cout << std::endl;
    std::chrono::duration<double, std::milli> timeElapsed = (std::chrono::high_resolution_clock::now() - t1);
    std::cout << "-------------------Tests Concluded-----------------" << std::endl;
    std::cout << std::endl;
    std::cout << "***************Statistics***************" << std::endl;
    std::cout << "Total Time Elapsed: " << timeElapsed.count() << " ms" << std::endl;
    std::cout << numberPassed << " out of " << totalTests << " tests passed successfully!" << std::endl;
    std::cout << "****************************************" << std::endl;
  }
  catch(const std::exception& e){
    std::cerr << "ERROR: " << e.what() << std::endl;
  }
  return 0;
}
