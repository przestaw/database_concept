/*
 * Estate.cpp
 * Class 'Estate' definition
 *
 * PROI, project 3
 * Tutor: Wiktor Kusmirek
 * Version: 06.06.2018, Kamil Zacharczuk
 * Based on work by Przemyslaw Stawczyk
 */
#include <sstream>

#include "Estate.hpp"

//Cons&des
Estate::Estate() : name("unnamed") {}

Estate::Estate(string p_name) : name(p_name) {}

Estate::~Estate()
{
  for(auto &i : owners) {
    delete i;}
}


//Modifying methods

Owner * Estate::add_owner(int p_telephone, string p_name)
{
	Owner * ptr = new Owner(p_name, p_telephone, this);
	owners.push_back(ptr);
	return owners.back();
}

Flat * Estate::add_flat(int p_size, int p_price, string p_street, int p_house_nr, int p_flat_nr, string p_name, Owner * p_owner)
{
	Flat* ptr = new Flat(p_name, p_owner);

	ptr->set_price(this->price.add(p_price, ptr));

      std::ostringstream ss1, ss2;
      ss1 << p_house_nr;
      ss2 << p_flat_nr;

      string t_address = "ul. " + p_street + " " + ss1.str() + " m. " + ss2.str();
	ptr->set_address(this->addresses.add(t_address, ptr));

	ptr->set_size(this->e_size.add(p_size, ptr));

	p_owner->add_flat(ptr);

	return ptr;
}

House * Estate::add_house(int p_size, int p_price, string p_street, int p_house_nr, string p_name, Owner * p_owner, int p_floors)
{
	House* ptr = new House(p_name, p_owner);

	ptr->set_price(this->price.add(p_price, ptr));

     std::ostringstream ss1;
      ss1 << p_house_nr;

      string t_address = "ul. " + p_street + " " + ss1.str();
	ptr->set_address(this->addresses.add(t_address, ptr));

	ptr->set_size(this->e_size.add(p_size, ptr));

	ptr->set_floors(p_floors);

	p_owner->add_house(ptr);

	return ptr;
}

Land * Estate::add_land(int p_size, int p_price, string p_street, int p_house_nr, string p_name, Owner * p_owner, bool p_built_up)
{
	Land* ptr = new Land(p_name, p_owner);

	ptr->set_price(this->price.add(p_price, ptr));

      std::ostringstream ss1;
      ss1 << p_house_nr;

      string t_address = "ul. " + p_street + " " + ss1.str();
	ptr->set_address(this->addresses.add(t_address, ptr));

	ptr->set_size(this->e_size.add(p_size, ptr));

	ptr->set_built_up(p_built_up);

	p_owner->add_land(ptr);

	return ptr;
}


//Showing methods

int Estate::show_size() const
{
  int count = 0;
  for(auto i : owners)
  {
    count += i->show_size();
  }
  return count;
}

Owner * Estate::show_owner(string p_name) const
{
  for(auto &i : owners)
  {
    if(i->show_name() == p_name)
      return i;
  }
  return nullptr;
}

Owner * Estate::show_owner(int p_telephone) const
{
  for(auto &i : owners)
  {
    if(i->show_telephone() == p_telephone)
      return i;
  }
  return nullptr;
}


//Operators

bool Estate::operator<(Estate &comp)
{
		return comp.name>this->name;
}

std::ostream& operator<<(std::ostream& os, const Estate& est)
{
  os << "ESTATE AGENCY\n" << est.name <<'\n';
  for(auto i : est.owners)
  {
	  try{
	   os << *i;
	  }
	  catch(int error_no)
	  {
		  os << "\n\t\tError no. " << error_no << ": ";
              switch (error_no){
              case 0:
                  os << "negative phone nr!" << '\n';
                  break;
              default:
                  os << "it's actually impossible you are seeing this!" << '\n';
                  break;
              }
	  }
  }
  return os;
}
