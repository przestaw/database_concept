/*
 * House.cpp
 * Class 'House' definition
 *
 * PROI, project 3
 * Tutor: Wiktor Kusmirek
 * Version: 06.06.18, Kamil Zacharczuk
 */
#include "House.hpp"

House::House () {}

House::House(string p_name="unnamed", Owner* p_owner=nullptr)
	: Property(p_name, p_owner) {}

House::~House() {}


int House::set_floors(int p_floors)
	{ return floors=p_floors; }
int House::show_floors() const
	{ return floors; }


void House::print() const
{
	int s_price = price->get_data();
	int s_size = c_size->get_data();
	string s_address = address->get_data();

	std::cout << "\n\t\tHOUSE\n\t\t"<< name;

	if (s_price<0) { throw 1;}
	else { std::cout << "\n\t\tprice : " << s_price << " EUR"; }

      if (s_size<0) { throw 2; }
      else { std::cout << "\n\t\tsize : " << s_size << " m^2"; }

	if (floors<0) { throw 3; }
	else { std::cout << "\n\t\tfloors : " << floors; }

      std::cout << "\n\t\taddress : " << s_address << '\n';
}
