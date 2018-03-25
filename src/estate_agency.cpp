/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class definition
 */

#include "../include/estate_agency.hpp"

Database::Database()
{
  cout << "Utworzono baze \n";
}

void Database::add_Owner(string &name_c, int &phone_c, string &adress)
{
  Data<string> * ptr_name = Owner_Name.add(name_c, NULL);
}



Owner::Owner(Data::Data_Object *name_c, Data::Data_Object *phone_c, Data::Data_Object *adress_c)
 :Record("Owner")
{
 add_attribute(name_c);
 add_attribute(phone_c);
 add_attribute(adress_c);
}

void Owner::add_attribute(attributes_e poz, Data::Data_Object *attribute);
{
 attributes[static_cast<int> poz] = attribute;
}

void House::add_attribute(attributes_e poz, Data::Data_Object *attribute);
{
 attributes[static_cast<int> poz] = attribute;
}
