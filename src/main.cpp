/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	main file for class tests
 */

#include <iostream>

int main()
{
	int state = 0;//represents number of exceptions cached
	try
	{
		//place for test initialization
	}
	catch(const char *exept)
	{
		std::cerr << "Warning : " << exept << "\n";
		++state;
	}
	std::cin.ignore();
	std::cout << "Program will stop after pushing any button";
	std::cin.get();
	return state; // returns number of exceptions cached
}