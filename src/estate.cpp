/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class definition
 */

#include "estate.hpp"
#include <algorithm>
//Estate class

ostream& operator<<(ostream& os, const Estate& est)
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
	ptr->price_c = this->price_c.add(price, ptr);
	ptr->adress_c = this->adresses_c.add(adress, ptr);
	ptr->size_c = this->size_c.add(size, ptr);
	owner_c->add(ptr);
	return ptr;
}

Owner * Estate::get_owner(string name_s)
{
  for(auto &i : owners)
  {
    if(i.name == name_s)
      return &i;
  }
  return nullptr;
}

Owner * Estate::get_owner(int telephone_s)
{
  for(auto &i : owners)
  {
    if(i.telephone == telephone_s)
      return &i;
  }
  return nullptr;
}

Owner * Estate::get_owner(House * house)
{
  for(auto &i : owners)
  {
    //if(std::find(houses.begin(), houses.end(), house) != houses.end())
    for(int j = i.houses.size(); j != 0; --j)
    {
      if(i.houses[j-1] == house)
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
    for(auto &j : i.houses)
    {
      if(j->name == name_s)
        return j;
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
//Owner class

ostream& operator<<(ostream& os, const Owner& own)
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

void Owner::add(House * house_a)
{
  houses.push_back(house_a);
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
// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -
//House class

ostream& operator<<(ostream& os, const House& hou)
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
