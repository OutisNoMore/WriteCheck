#ifndef CHECK_H
#define CHECK_H

#include <string>
#include <map>

typedef std::map<int, std::string> MyMap;

// Tens places
static const MyMap TENS = {
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
static const MyMap TEN = {
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
static const MyMap ONES = {
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
static const MyMap PLACES = { 
  {1, "Thousand "}, 
  {3, "Billion "},
  {4, "Trillion "},
  {5, "Quadrillion "}
};

class WriteCheck{
  private:
    /*
    static const MyMap TENS;   // Map of numerical Tens to words
    static const MyMap TEN;    // Map of numerical 10-19 to words
    static const MyMap ONES;   // Map of numerical ones to words
    static const MyMap PLACES; // Map of all places
    */
    static std::string intToWord(int money);
  public:
    // Convert given money amount to words
    static std::string processCheck(double money);
};
#endif // CHECK_H
