/*
 * Land.cpp
 * Class 'Land' definition
 *
 * PROI, project 3
 * Tutor: Wiktor Kusmirek
 * Version: 06.06.18, Kamil Zacharczuk
 */
#include "Land.hpp"

Land::Land() {}

Land::Land(string p_name="unnamed", Owner* p_owner=nullptr)
	: Property(p_name, p_owner) {}

Land::~Land() {}


bool Land::set_built_up (bool p_built_up)
	{ return built_up=p_built_up; }
bool Land::show_built_up () const
	{ return built_up; }


void Land::print() const
{
	int s_price = price->get_data();
	int s_size = c_size->get_data();
	string s_address = address->get_data();

	std::cout << "\n\t\tLAND\n\t\t"<< name;

	if (s_price<0) { throw 1;}
	else { std::cout << "\n\t\tprice : " << s_price << " EUR"; }

      if (s_size<0) { throw 2; }
      else { std::cout << "\n\t\tsize : " << s_size << " m^2"; }

      std::cout << "\n\t\taddress : " << s_address << '\n';
}
