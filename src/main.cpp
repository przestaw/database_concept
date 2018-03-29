/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	main
 */

#include <iostream>
#define string std::basic_string<char>
#include "database.hpp"
#include "estate.hpp"

int main()
{
	Estate database("A good estate company");
	database.add_owner(986721937,"Joanna Jankowska");
	database.add_owner(941533980, "Stefania Wieczorek");
	database.add_house(215,335000,"ul malinowy dzem 16b", "malinowy zakatek", database.get_owner(986721937));
	database.add_house(115,1335000,"ul elkowa 13", "nieszczesliwa eleczka", database.get_owner(986721937));
	database.add_house(120,10005000,"pl politechniki 1", "gmach chemii", database.get_owner(986721937));
	database.add_house(1200,19995000,"al Jerozolimskie 200", "cala kamienica mosciskich", database.get_owner(941533980));
	database.add_house(360,5000,"ul trzeciej rzeszy 3", "Bunkry przeciwlotnicze", database.get_owner(941533980));
	std::cout << database << "\nPress any key to continue\n";
	std::cin.get();
	return 0;
}
