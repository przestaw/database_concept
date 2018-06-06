/*
 * main.cpp
 * The estate agency test
 *
 * PROI, project 3
 * Tutor: Wiktor Kusmirek
 * Version: 06.06.2018, Kamil Zacharczuk
 * Based on work by Przemyslaw Stawczyk
 */

#include <iostream>
#define string std::basic_string<char>
#include "database.hpp"
#include "Estate.hpp"

int main()
{
	Estate database("A good estate company");
	database.add_owner(986721937,"Joanna Jankowska");
	database.add_owner(941533980, "Stefania Wieczorek");
	database.add_land(-215,335000, "landowa", 2, "dzialeczka zabudowana", database.show_owner(986721937), true);
	database.add_flat(115,-1335000, "osiedlowa", 24, 6, "mieszkanko", database.show_owner(986721937));
	database.add_flat(115,1335000, "osiedlowa", 27, 13, "mieszkanko2", database.show_owner(986721937));
	database.add_house(120,10005000, "domkowa", 5, "domek o 7 pietrach", database.show_owner(986721937), -7);
	database.add_land(1200,19995000,"puste landy", 2, "dzialeczka pusta", database.show_owner(941533980), false);
	database.add_flat(360,5000,"xd", 24, 5, "sasiad mieszkanka", database.show_owner(941533980));
	std::cout << database << "\nPress any key to continue\n";
	std::cin.get();
	return 0;
}
