/*
 * Property.cpp
 * Class 'Property' definition
 *
 * PROI, project 3
 * Tutor: Wiktor Kusmirek
 * Version: 06.06.2018, Kamil Zacharczuk
 * Based on work by Przemyslaw Stawczyk
 */
#include "Property.hpp"

//Constructors
Property::Property()
	: name("unnamed"), owner(nullptr) {}

Property::Property(string p_name, Owner* p_owner = nullptr)
	: name(p_name), owner(p_owner) {}

Property::~Property() {}

//Modifying methods
string Property::set_name(string p_name)
	{ return name=p_name; }


int Property::set_size(int p_size)
{
	c_size->set_data(p_size);
	return p_size;
}
int Property::set_size(Data_Object<int, Property> * p_size)
{
	c_size = p_size;
	return c_size->get_data();
}


int Property::set_price(int p_price)
{
	price->set_data(p_price);
	return p_price;
}
int Property::set_price(Data_Object<int, Property> * p_price)
{
	price = p_price;
	return price->get_data();
}


Owner* Property::set_owner(Owner* p_owner=nullptr)
	{ return owner=p_owner; }


string Property::set_address(string p_address)
{
	address->set_data(p_address);
	return p_address;
}

string Property::set_address(Data_Object<string, Property> * p_address)
{
	address = p_address;
	return address->get_data();
}


//Showing methods
string Property::show_name() const
	{ return name; }

int Property::show_size() const
	{ return c_size->get_data(); }

int Property::show_price() const
	{ return price->get_data(); }

string Property::show_address() const
	{ return address->get_data(); }


//Operators
bool Property::operator<(Property& comp)
	{ return comp.price > this->price; }
