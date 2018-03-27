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




class Estate;
class Owner;
class House;


class Estate
{
public:
	string name;
	Estate() :name("unnamed") {};
	explicit Estate(string &name_c) :name(name_c) {};
	int get_size(); //UNIMPLEMENTED
	void add_owner(int &telephone, string &name_c); //UNIMPLEMENTED
	void add_owner(int &telephone, string &name_c, House * house_c); //UNIMPLEMENTED
	void add_house(int size_c, int price_c, string adress, string &name); //UNIMPLEMENTED
	void add_house(int &size_c, int &price_c, string &adress, string &name_c, Owner * owner_c); //UNIMPLEMENTED

	Owner * get_owner(string &name); //UNIMPLEMENTED
	Owner * get_owner(int &telephone); //UNIMPLEMENTED
	Owner * get_owner(House * house); //UNIMPLEMENTED

	House * get_house(string &name); //UNIMPLEMENTED

	void show(int mode); //only working for 1 //UNIMPLEMENTED
	void show(House * house); //UNIMPLEMENTED
	void show(Owner * owner); //UNIMPLEMENTED
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
	Owner() :name("unnamed"), telephone(0), mine(nullptr){};
	explicit Owner(Estate *estate_c) :Owner(), mine(estate_c) {};
	int get_size(); //UNIMPLEMENTED
	void add(House * house_a); //UNIMPLEMENTED
private:
	Estate * mine;
	vector<House> houses;
};


class House
{
public:
	string name;
	enum attribute{price=0, size, adress};
	House() :name("unnamed"), mine(nullptr) {} ;
	explicit House(Owner *owner_c) :House(), mine(owner_c) {};
	void add(int &value, attribute attr); //UNIMPLEMENTED
	void add(string &value, attribute attr); //UNIMPLEMENTED
private:
	Owner * mine;
	Data_Object<int> * price_c;
	Data_Object<int> * size_C;
	Data_Object<string> * adress_Cd;
};


#endif //ESTATE_AGENCY_HPP
