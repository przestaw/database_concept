/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "declaration.hpp"
#include "database.hpp"
#include "owner.hpp"
#include <string>
#include <iostream>

#define string std::basic_string<char>

class House
{
public:
	House();
	explicit House(Owner *owner_c);
	House(string name_c, Owner *owner_c);

  string get_name();
  void set_name(string name_s);
  Owner * get_owner();
  void set_owner(Owner * owner_s);

  int get_price();
  void set_price(int price_s);
  void set_price(Data_Object<int, House> * price_s);
  int get_size();
  void set_size(int size_s);
  void set_size(Data_Object<int, House> * size_s);
  string get_adress();
  void set_adress(string adress_s);
  void set_adress(Data_Object<string, House> * adress_s);

	friend std::ostream& operator<<(std::ostream& os, const House& hou);
	bool operator<(House &comp);
private:
  string name;
	Owner * mine;
	Data_Object<int, House> * price_c;
	Data_Object<int, House> * size_c;
	Data_Object<string, House> * adress_c;
};

#endif //HOUSE_HPP
