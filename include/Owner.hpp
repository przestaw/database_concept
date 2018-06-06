/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef OWNER_HPP
#define OWNER_HPP

#include "Flat.hpp"
#include "House.hpp"
#include "Land.hpp"

class Estate; //class Owner is using the Estate type

class Owner
{
	public:
		//Cons&des
		Owner();
		Owner(string, int, Estate*);
		~Owner();

		//Modifying methods
		string set_name(string);
		int set_telephone(int);
		Estate* set_estate(Estate*);

		void add_flat(Flat*);
		void add_house(House*);
		void add_land(Land*);

		//Showing methods
		string show_name() const;
		int show_telephone() const;
		Estate* show_estate() const;
		int show_size() const;

		//Operators
		bool operator<(Owner&);
		friend std::ostream& operator<<(std::ostream&, const Owner&);

	private:
		string name;
		int telephone; //phone number
		Estate * mine; //estate in which the owner has their houses
		std::vector<Flat*> flats;
		std::vector<House*> houses;
		std::vector<Land*> lands;

};



#endif //OWNER_HPP
