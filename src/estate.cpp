/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class definition
 */

#include "estate.hpp"
//#include <algorithm>
//Estate class

ostream& operator<<(ostream& os, const Estate& est)
{
  os << "ESTATE AGENCY\n" << est.name <<'\n'<< est.owners_c;
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

Owner * Estate::get_owner(string name_s)
{
  for(auto &i : owners)
  {
    if(i.name == name_s)
      return &i;
  }
  return nullptr;
}

Owner * Estate::get_owner(int &telephone_s)
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
// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -
//House class

ostream& operator<<(ostream& os, const House& hou)
{
  os << "\n\t\tHOUSE\n\t\t"<< hou.name
    << "\n\t\tprive : " << hou.price_c->data << " EUR"
    << "\n\t\tsize : " << hou.size_c->data << " m^2"
    << "\n\t\tadress : " << hou.adress_c->data << '\n';
    return os;
}
