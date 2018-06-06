/*
 * Flat.hpp
 * Class 'Flat' declaration
 *
 * PROI, project 3
 * Tutor: Wiktor Kusmirek
 * Version: 22.05.18, Kamil Zacharczuk
 */
#ifndef FLAT_HPP
#define FLAT_HPP

#include "Property.hpp"

class Flat : public Property
{
	public:
		//Cons&des
		Flat();
		Flat(string, Owner*);
		~Flat();

		//Pure virtual method
		void print() const;
		
    private:
		int flat_nr;
};

#endif //FLAT_HPP
