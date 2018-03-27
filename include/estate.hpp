/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef ESTATE_AGENCY_HPP
#define ESTATE_AGENCY_HPP

#include "../include/database.hpp"
//#include <string>
//#include <vector>
//#define string std::basic_string<char>

//#define NULL nullptr


class Estate;
class Owner;
class House;


class Estate
{
public:
	string name;
	Estate() :name("empty") {};
	explicit Estate(string &name_c) :name(name_c) {};
	int get_size(); //UNIMPLEMENTED
	void add(Owner * owner_a);
private:
	vector<Owner> owners;
	// more
	Data<int> size_c;
	Data<int> price_c;
	Data<string> adress;
	Data<Owner> owners_c;
	Data<House> houses_c;
};


class Owner
{
public:
	string name;
	int telephone;
	Owner() :name("empty"), telephone(0), mine(NULL){};
	explicit Owner(Estate *estate_c) :Owner(), mine(estate_c) {};
	int get_size(); //UNIMPLEMENTED
	void add(House * house_a);
private:
	Estate * mine;
	vector<House> houses;
};


class House
{
public:
	string name;
	enum attribute{price=0, size, adress};
	House() :name("empty"), mine(NULL) {} ;
	explicit House(Owner *owner_c) :House(), mine(owner_c) {};
	void add(int &value, attribute attr);
	void add(string &value, attribute attr);
private:
	Owner * mine;
	Data_Object<int> * price_c;
	Data_Object<int> * size_C;
	Data_Object<string> * adress_Cd;
};


#endif //ESTATE_AGENCY_HPP
