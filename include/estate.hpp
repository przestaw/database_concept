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
using std::ostream;

class Estate
{
public:
	string name;
	Estate() :name("unnamed") {};
	explicit Estate(string name_c) :name(name_c) {};
	int get_size();
	void add_owner(int &telephone, string &name_c); //UNIMPLEMENTED
	void add_owner(int &telephone, string &name_c, House * house_c); //UNIMPLEMENTED
	void add_house(int size_c, int price_c, string adress, string &name); //UNIMPLEMENTED
	void add_house(int &size_c, int &price_c, string &adress, string &name_c, Owner * owner_c); //UNIMPLEMENTED

	Owner * get_owner(string name); //UNIMPLEMENTED
	Owner * get_owner(int &telephone); //UNIMPLEMENTED
	Owner * get_owner(House * house); //UNIMPLEMENTED

	House * get_house(string name); //UNIMPLEMENTED

	void show(int mode);//UNIMPLEMENTED
	friend ostream& operator<<(ostream& os, const Estate& est);
private:
	vector<Owner> owners;
	// more
	Data<int, House> size_c;
	Data<int, House> price_c;
	Data<string, House> adresses_c;
	Data<Owner, Estate> owners_c;
	Data<House, Owner> houses_c;
};


class Owner
{
public:
	string name;
	int telephone;
	Owner() :name("unnamed"), telephone(0), mine(nullptr){};
	explicit Owner(Estate *estate_c) :name("unnamed"), telephone(0), mine(estate_c) {};
	explicit Owner(string name_c, Estate *estate_c) :name(name_c), telephone(0), mine(estate_c) {};
	int get_size();
	void add(House * house_a);
	friend ostream& operator<<(ostream& os, const Owner& own);
private:
	Estate * mine;
	vector<House*> houses;
};


class House
{
friend Estate;
friend Owner;
public:
	string name;
	House() :name("unnamed"), mine(nullptr) {};
	explicit House(Owner *owner_c) :name("unnamed"),  mine(owner_c) {};
	explicit House(string name_c, Owner *owner_c) :name(name_c),  mine(owner_c) {};
	friend ostream& operator<<(ostream& os, const House& hou);
private:
	Owner * mine;
	Data_Object<int, House> * price_c;
	Data_Object<int, House> * size_c;
	Data_Object<string, House> * adress_c;
};


#endif //ESTATE_AGENCY_HPP
