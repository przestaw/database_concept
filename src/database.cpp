/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class Record definition
 */

 #include "../include/database.hpp"

Record::Record(string &name_c, Record *belonging)
  :Record(name_c)
{
  //va_list belo;
  //va_start(belo, attribute);
   belongings.push_back(belonging);
  //va_end(belo);
}

void Record::add_belonging(Record *belonging)
{
  belongings.push_back(belonging);
}
