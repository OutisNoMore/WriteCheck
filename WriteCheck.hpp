#ifndef CHECK_H
#define CHECK_H

#include <string>
#include <map>

#define MyMap std::map<int, std::string> 

class WriteCheck{
  private:
    static const MyMap TENS;   // Map of numerical Tens to words
    static const MyMap TEN;    // Map of numerical 10-19 to words
    static const MyMap ONES;   // Map of numerical ones to words
    static const MyMap PLACES; // Map of all places
    static std::string intToWord(int money);
  public:
    // Convert given money amount to words
    static std::string processCheck(double money);
};
#endif // CHECK_H
