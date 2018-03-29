/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class definition
 */

#include "owner.hpp"
//Owner class
Owner::Owner()
  :name("unnamed"), telephone(0), mine(nullptr)
{}

Owner::Owner(Estate *estate_c)
  :name("unnamed"), telephone(0), mine(estate_c)
{}

Owner::Owner(string name_c, Estate *estate_c)
  :name(name_c), telephone(0), mine(estate_c)
{}

Owner::Owner(string name_c, int &telephone_c, Estate *estate_c)
  :name(name_c), telephone(telephone_c), mine(estate_c)
{}

std::ostream& operator<<(std::ostream& os, const Owner& own)
{
  os << "\n\tOWNER\n\t" << own.name << "\n\ttel : " << own.telephone << '\n' ;
  for(auto i : own.houses)
  {
    os << *i;
  }
  return os;
}

int Owner::get_size()
{
  return houses.size();
}

string Owner::get_name()
{
  return name;
}

void Owner::set_name(string name_c)
{
  name = name_c;
}

int Owner::get_telephone()
{
  return telephone;
}

void Owner::set_telephone(int telephone_c)
{
  telephone = telephone_c;
}

void Owner::add(House * house_a)
{
  houses.push_back(house_a);
}

House * Owner::get_house(int poz)
{
  return this->houses[poz];
}

bool Owner::operator<(Owner &comp)
{
	if(comp.name > this->name)
	{
		return true;
	}else
	{
		return false;
	}
}
