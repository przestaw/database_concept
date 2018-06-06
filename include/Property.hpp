/*
 * Property.hpp
 * Declaration AND definition of a class 'Property'
 * This class is the superclass for the classes representing different types of properties
 *
 * PROI, project 3
 * Tutor: Wiktor Kusmirek
 * Version: 22.05.18, Kamil Zacharczuk
 */

#ifndef PROPERTY_HPP
#define PROPERTY_HPP

#include "database.hpp"

class Owner;

class Property
{
	public:
		//Cons&des
		//Constructors can initialize all fields but address, form of which varies in subclasses
		Property();

		Property(string, Owner*);

		virtual ~Property();

		//Setting methods
		string set_name(string);

		int set_size(int);
        int set_size(Data_Object<int, Property> *);

		int set_price(int);
        int set_price(Data_Object<int, Property> *);

		Owner* set_owner(Owner*);

		string set_address(string);
		string set_address(Data_Object<string, Property> *);

		//Showing methods
		string show_name() const;
		int show_size() const;
		int show_price() const;
		string show_address() const;

		virtual void print() const = 0; //pure virtual method printing all the info

		//Operators
		bool operator<(Property&);

	protected:
		string name;
		Data_Object<int, Property> * price;
		Data_Object<int, Property> * c_size;
		Data_Object<string, Property> * address; //form of the address will vary depending on the property type (derived classes)
		Owner* owner;
};

#endif //PROPERTY_HPP
