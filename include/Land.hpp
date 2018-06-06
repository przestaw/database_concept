#ifndef LAND_HPP
#define LAND_HPP

#include <iostream>
#include "Property.hpp"

class Land : public Property
{
	public:
		//Cons&des
		Land();
		Land(string, Owner*);
		~Land();
		
		//Methods for managing being built-up of the land
		bool set_built_up (bool);
		bool show_built_up () const;
		
		//Pure virtual method
		void print() const;

	private:
		bool built_up; //is the land built-up?
};

#endif //LAND_HPP
