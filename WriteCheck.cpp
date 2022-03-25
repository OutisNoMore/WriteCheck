#include "WriteCheck.hpp"

// Tens places
MyMap const WriteCheck::TENS = {
  {0, ""},
  {2, "Twenty "},
  {3, "Thirty "},
  {4, "Forty "},
  {5, "Fifty "},
  {6, "Sixty "},
  {7, "Seventy "},
  {8, "Eighty "},
  {9, "Ninety "}
};

// 10 - 19 have different name convention
MyMap const WriteCheck::TEN = {
  {10, "Ten "},
  {11, "Eleven "},
  {12, "Twelve "},
  {13, "Thirteen "},
  {14, "Fourteen "},
  {15, "Fifteen "},
  {16, "Sixteen "},
  {17, "Seventeen "},
  {18, "Eighteen "},
  {19, "Nineteen "}
};

// Ones places
MyMap const WriteCheck::ONES = {
  {0, ""},
  {1, "One "},
  {2, "Two "},
  {3, "Three "},
  {4, "Four "},
  {5, "Five "},
  {6, "Six "},
  {7, "Seven "},
  {8, "Eight "},
  {9, "Nine "}
};

// Places 
MyMap const WriteCheck::PLACES = { 
  {1, "Thousand "}, 
  {3, "Billion "},
  {4, "Trillion "},
  {5, "Quadrillion "}
};

// Convert given integer to word form
std::string WriteCheck::intToWord(int money){
  if(money == 0){
    // Return Zero if none
    return "Zero ";
  }
  std::string output = ""; // Output number as words
  int place = 0;  // Keep track of places
  int chunk = 0; // Chunks to process in
  while(money != 0){
    if(place!= 0){
      // Add places
      output = PLACES.at(place) + output;
    }
    chunk = money % 1000; // process in chunks of 3 digits
    if(chunk%100 < 20 && chunk%100 > 9){
      // From 10 to 19
      output = TEN.at(chunk%100) + output;
    }
    else{
      // Process as normal tens place
      output = ONES.at(chunk%10) + output;
      output = TENS.at((chunk%100)/10) + output;
    }
    if(chunk > 99){
      // Add hundred places
      output = ONES.at(chunk/100) + "Hundred " + output;
    }
    money = money/1000; // move on to next chunk 
    place++;            // next decimal place } return output; 
  }
  return output;
}

std::string WriteCheck::processCheck(double money){
  int cent = (int)(money * 100) % 100; // Get cent amount from money
  int dollar = (int)money;             // Get dollar amount from money
  // Convert from numbers to words
  std::string dollars = intToWord(dollar); // Dollars Converted
  std::string cents = intToWord(cent);     // Cents converted
  std::string output = dollars + "Dollars and " + cents + "Cents"; // Combine output with units
  return output;
}

