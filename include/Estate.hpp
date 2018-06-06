/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef ESTATE_HPP
#define ESTATE_HPP

#include "database.hpp"
#include "Owner.hpp"
#include "Flat.hpp"
#include "House.hpp"
#include "Land.hpp"

class Estate
{
	public:
		//Cons&des
		Estate();
		explicit Estate(string);
		~Estate();

		//Modifying methods
		Owner* add_owner(int, string);
		Flat* add_flat(int, int, string, int, int, string, Owner*);
		House* add_house(int, int, string, int, string, Owner*, int);
		Land* add_land(int, int, string, int, string, Owner*, bool);

		//Showing methods
		int show_size() const; //how many properties in the estate
		Owner * show_owner(string) const;
		Owner * show_owner(int) const;

		//Operators
		bool operator<(Estate&);
		friend std::ostream& operator<<(std::ostream&, const Estate&);

	private:
		string name;
		std::vector<Owner*> owners;
		Data<int, Property> e_size;
		Data<int, Property> price;
		Data<string, Property> addresses;
};

#endif //ESTATE_HPP
