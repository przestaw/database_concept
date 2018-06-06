/*
 * Owner.cpp
 * Class 'Owner' definition
 *
 * PROI, project 3
 * Tutor: Wiktor Kusmirek
 * Version: 06.06.2018, Kamil Zacharczuk
 * Based on work by Przemyslaw Stawczyk
 */

#include "Owner.hpp"

//Constructors
Owner::Owner()
	: name("unnamed"), telephone(0), mine(nullptr) {}

Owner::Owner(string p_name="unnamed", int p_telephone=0, Estate* p_mine=nullptr)
	: name(p_name), telephone(p_telephone), mine(p_mine) {}

Owner::~Owner() {}


//Modifying methods
string Owner::set_name(string p_name)
	{ return name=p_name; }

int Owner::set_telephone(int p_telephone)
	{ return telephone=p_telephone; }

Estate* Owner::set_estate(Estate* p_mine)
	{ return mine=p_mine; }

void Owner::add_flat(Flat* new_flat)
	{ flats.push_back(new_flat); }

void Owner::add_house(House* new_house)
	{ houses.push_back(new_house); }

void Owner::add_land(Land* new_land)
	{ lands.push_back(new_land); }


//Showing methods
string Owner::show_name() const
	{ return name; }

int Owner::show_telephone() const
	{ return telephone; }

Estate* Owner::show_estate() const
	{ return mine; }

int Owner::show_size() const
	{ return (lands.size()+houses.size()+flats.size()); }


//Operators
bool Owner::operator<(Owner &comp)
	{ return comp.name>this->name; }

std::ostream& operator<<(std::ostream& os, const Owner& own) //friend operator
{
	os << "\n\tOWNER\n\t" << own.name;

	if (own.telephone<0) { throw 0; } //exception
	os << "\n\ttel : " << own.telephone << '\n' ;

	os << "\n\t\tFLATS:\n\t";
	for(Flat* i : own.flats){
            try{
                  i->print();
            }
             catch(int error_no)
              {
                    os << "\n\t\tError no. " << error_no << ": ";
                    switch (error_no){
                    case 1:
                        os << "negative price!" << '\n';
                        break;
                    case 2:
                        os << "negative size!" << '\n';
                        break;
                    default:
                        os << "it's actually impossible you are seeing this!" << '\n';
                        break;
                    }
              }
      }

      os << "\n\t\tHOUSES:\n\t";
	for(House* i : own.houses){
		try{
		      i->print();
            }
             catch(int error_no)
              {
                    os << "\n\t\tError no. " << error_no << ": ";
                    switch (error_no){
                    case 1:
                        os << "negative price!" << '\n';
                        break;
                    case 2:
                        os << "negative size!" << '\n';
                        break;
                    case 3:
                        os << "negative floors quantity!" << '\n';
                        break;
                    default:
                        os << "it's actually impossible you are seeing this!" << '\n';
                        break;
                    }
              }
	}

      os << "\n\t\tLANDS:\n\t";
	for(Land* i : own.lands){
		try{
                  i->print();
            }
             catch(int error_no)
              {
                    os << "\n\t\tError no. " << error_no << ": ";
                    switch (error_no){
                    case 1:
                        os << "negative price!" << '\n';
                        break;
                    case 2:
                        os << "negative size!" << '\n';
                        break;
                    default:
                        os << "it's actually impossible you are seeing this!" << '\n';
                        break;
                    }
              }
	}

	return os;
}


