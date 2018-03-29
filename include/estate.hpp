/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef ESTATE_HPP
#define ESTATE_HPP

#include "declaration.hpp"
#include "database.hpp"
#include "owner.hpp"
#include "house.hpp"
#include <string>
#include <vector>
#include <iostream>

#define string std::basic_string<char>

class Estate
{
public:
	Estate();
	~Estate();
	explicit Estate(string name_c);
	int get_size();
	Owner * add_owner(int telephone_c, string name_c);
	Owner * add_owner(int telephone_c, string &ame_c, House * house_c); //UNIMPLEMENTED
	House * add_house(int size, int price, string adress, string name); //UNIMPLEMENTED
	House * add_house(int size, int price, string adress, string name_c, Owner * owner_c);
	Owner * get_owner(string name_S);
	Owner * get_owner(int telephone_s);
	Owner * get_owner(House * house);
	House * get_house(string name_s);
	//void show(int mode);//UNIMPLEMENTED
	bool operator<(Estate &comp);
	friend std::ostream& operator<<(std::ostream& os, const Estate& est);
private:
	string name;
	std::vector<Owner*> owners;
	Data<int, House> size_c;
	Data<int, House> price_c;
	Data<string, House> adresses_c;
	//Data<Owner*, Estate> owners_c;
	//Data<House*, Owner> houses_c;
};

#endif //ESTATE_HPP
