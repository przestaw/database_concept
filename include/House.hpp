#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "Property.hpp"

class House : public Property
{
	public:
		House();
		House(string, Owner*);
		~House();

		//Methods for managing floors
		int set_floors(int);
		int show_floors() const;

		//Pure virtual method
		void print() const;

	private:
		int floors; //floors quantity
};

#endif //HOUSE_HPP
