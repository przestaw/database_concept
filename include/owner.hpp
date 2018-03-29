/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef OWNER_HPP
#define OWNER_HPP

#include "declaration.hpp"
#include "estate.hpp"
#include "house.hpp"
#include <iostream>
#include <string>
#include <vector>

#define string std::basic_string<char>

class Owner
{
public:
  Owner();
  explicit Owner(Estate *estate_c);
  Owner(string name_c, Estate *estate_c);
  Owner(string name_c, int &telephone_c, Estate *estate_c);
  string get_name();
  void set_name(string name_c);
  int get_telephone();
  void set_telephone(int telephone_c);
  House * get_house(int poz);
  int get_size();
  void add(House * house_a);
  friend std::ostream& operator<<(std::ostream& os, const Owner& own);
  bool operator<(Owner &comp);
private:
  string name;
  int telephone;
  Estate * mine;
  std::vector<House*> houses;
};

#endif //OWNER_HPP
