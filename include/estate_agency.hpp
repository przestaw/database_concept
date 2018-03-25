/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef ESTATE_AGENCY_HPP
#define ESTATE_AGENCY_HPP

#include "database.hpp"

using std::string;
using std::vector;

//#define House Record
//#define Owner Record
class Database;
class Owner;
class House;

class Database
  :public Record
{
private:
	Data<Owner>(Owner_d);
	Data<string>(Owner_Name);
	Data<int>(Owner_Phone);
	Data<string>(Owner_Adress);
	Data<House>(House_d);
	Data<double>(House_Price);
	Data<double>(House_Size);
	Data<string>(House_Adress);
public:
	Database();
	add_Owner(string &name_c, int &phone_c, string &adress);
}

class Owner
	:public Record
{
private:

public:
	enum attributes_e {name=0, phone, adress};
	Owner(Data::Data_Object *name_c, Data::Data_Object *phone_c, Data::Data_Object *adress_c);
	void add_attribute(attributes_e poz, Data::Data_Object *attribute);
	{
		attributes[static_cast<int> poz] = attribute;
	}
};

class House
	:public Record
{
private:

public:
	enum attributes_e {price, size, adress};
	House(Data::Data_Object * price_c, Data::Data_Object * size_c, Data::Data_Object * adress_c)
	{
		add_attribute(price_c);
		add_attribute(size_c);
		add_attribute(adress_c);
	}
	void add_attribute(attributes_e poz, Data::Data_Object *attribute);
	{
		attributes[static_cast<int> poz] = attribute;
	}
};

#endif //ESTATE_AGENCY_HPP
