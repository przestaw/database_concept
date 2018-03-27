/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class Record definition
 */

 #include "../include/database.hpp"

Record::Record(string &name_c, Record *belonging)
		:name(name_c)
{
	add_belonging(belonging);
}

void Record::add_belonging(Record *belonging)
{
	belongings.push_back(belonging);
}
