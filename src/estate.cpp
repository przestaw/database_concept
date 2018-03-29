/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class definition
 */

#include "estate.hpp"
//Estate class
Estate::Estate()
  :name("unnamed") 
{};

explicit Estate::Estate(string name_c)
  :name(name_c)
{};


std::ostream& operator<<(std::ostream& os, const Estate& est)
{
  os << "ESTATE AGENCY\n" << est.name <<'\n';
  for(auto i : est.owners)
  {
	   os << i;
  }
  return os;
}

int Estate::get_size()
{
  int count = 0;
  for(auto i : owners)
  {
    count = count + i.get_size();
  }
  return count;
}

Owner * Estate::add_owner(int telephone_c, string name_c)
{
	Owner * ptr = new Owner(name_c, telephone_c, this);
	owners.push_back(*ptr);
	return &(owners.back());
}

House * Estate::add_house(int size, int price, string adress, string name, Owner * owner_c)
{
	House * ptr = new House(name, owner_c);
	ptr->set_price(this->price_c.add(price, ptr));
	ptr->set_adress(this->adresses_c.add(adress, ptr));
	ptr->set_size(this->size_c.add(size, ptr));
	owner_c->add(ptr);
	return ptr;
}

Owner * Estate::get_owner(string name_s)
{
  for(auto &i : owners)
  {
    if(i.get_name() == name_s)
      return &i;
  }
  return nullptr;
}

Owner * Estate::get_owner(int telephone_s)
{
  for(auto &i : owners)
  {
    if(i.get_telephone() == telephone_s)
      return &i;
  }
  return nullptr;
}

Owner * Estate::get_owner(House * house)
{
  for(auto &i : owners)
  {
    //if(std::find(houses.begin(), houses.end(), house) != houses.end())
    for(int j = i.size(); j != 0; --j)
    {
      if(i.get_house(j-1) == house)
      {
        return &i;
      }
    }
  }
  return nullptr;
}

House * Estate::get_house(string name_s)
{
  for(auto &i : owners)
  {
    for(int j = i.size(); j != 0; --j)
    {
      if(i.get_house(j-1)->get_name() == name_s)
      {
        return j;
      }
    }
  }
  return nullptr;
}

bool Estate::operator<(Estate &comp)
{
	if(comp.name > this->name)
	{
		return true;
	}else
	{
		return false;
	}
}

// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -

// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -
