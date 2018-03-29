/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class definition
 */

#include "house.hpp"

 //House class
House::House()
 :name("unnamed"), mine(nullptr)
{}

House::House(string name_c, Owner *owner_c)
  :name(name_c),  mine(owner_c)
{}

explicit House::House(Owner *owner_c)
  :name("unnamed"),  mine(owner_c)
{}

string House::get_name()
{
  return name;
}

void House::set_name(string name_s)
{
  name = name_s;
}

Owner * House::get_owner()
{
  return mine;
}

void House::set_owner(Owner * owner_s)
{
  mine = owner_s;
}

int House::get_price()
{
  return price_c->get_data();
}

void House::set_price(int price_s)
{
  price_c.set_data(price_s);
}

void House::set_price(Data_Object<int, House> * price_s)
{
  price_c = price_s;
}

int House::get_size()
{
  return size_c->get_data();
}

void House::set_size(int size_s)
{
  size_c->set_data(size_s);
}

void House::set_size(Data_Object<int, House> * size_s)
{
  size_c = size_s;
}

string House::get_adress()
{
  return adress_c->get_data();
}

void House::set_adress(string adress_s)
{
  adress_c->set_data(adress_s);
}

void House::set_adress(Data_Object<string, House> * adress_s)
{
  adress_c = adress_s;
}

std::ostream& operator<<(std::ostream& os, const House& hou)
{
 os << "\n\t\tHOUSE\n\t\t"<< hou.name
   << "\n\t\tprice : " << hou.price_c->data << " EUR"
   << "\n\t\tsize : " << hou.size_c->data << " m^2"
   << "\n\t\tadress : " << hou.adress_c->data << '\n';
   return os;
}

bool House::operator<(House &comp)
{
  if(comp.price_c->data > this->price_c->data)
  {
 	  return true;
	}else
 	{
 	  return false;
	}
}
