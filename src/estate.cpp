/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class definition
 */

#include "estate.hpp"

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
