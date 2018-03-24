/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef DATABASE_CONCEPT_DATABASE_H
#define DATABASE_CONCEPT_DATABASE_H

#include <vector>
#include <string>
#include <cstddef>

using std::string;
using std::vector;

template <class T>
class Data_Object<T>;
class Record;

template <class T>
class Data_Object<T>
{
	friend Record;

private:
	class List
	{
	public:
		T data;
		List *next;
		List *prev;
		vector<Record> mine;
		~List();
	};
	List * end;
	List * begin;

	List * create_node(T data_n, List *prev_n);
public:
	Data_Object()
		:end(NULL), begin(NULL)
	{}
	Data_Object(T data_c);
	Data_Object(Data_Object old);
	~Data_Object();
	int size();
	void add(T data_a);
};

template<class T>
Data_Object<T>::List::~List()
{
	if(mine.size() == 0)
	{
		delete this;
	}else
	{

	}
}





template<class T>
Data_Object<T>::Data_Object(Data_Object old) {
	throw ("Copy constructor for Data_Object Class is not yet implemented");
}

template<class T>
Data_Object<T>::Data_Object(T data_c) {
	begin=new List;
	begin->data=data_c;
	end=begin;
}

template<class T>
Data_Object<T>::~Data_Object() {
	for(List* i=begin;begin != end; i=i->next)
	{
		delete(i);
	}
}

template<class T>
Data_Object<T>::List *Data_Object<T>::create_node(T data_n, Data_Object<T>::List *prev_n) {
	List * next_n, * new_n;
	next_n = prev_n->next;
	new_n = new List;
	new_n->data = data_n; //apllying data
	new_n->prev = prev_n;
	new_n->next = next_n;
	next_n->prev = new_n;
	return new_n;
}

template<class T>
int Data_Object<T>::size() {
	int size = 0;
	for(List* i=begin;begin != end; i=i->next)
	{
		++size;
	}
	return size;
}

template<class T>
void Data_Object<T>::add(T data_a) {
	for(List* i=begin;begin != end; i=i->next)
	{
		if(data_a>= i->data)
		{
			create_node(data_a,i);
		}
	}
}


/*
 * End of Data_Object
 * 														// Mark
 * Begin of Record
*/

class Record
{
	friend Data_Object;
public:
	string name;
	explicit Record(string &name_c)
		:name(name_c)
	{}
	Record(string &name_c, Data_Object.List * attribute_c)
		:name(name_c)
	{
		attributes.push_back(attribute_c);
	}
	Record(string &name_c, Record * belonging)
		:name(name_c)
	{
		belongings.push_back(belonging);
	}
	void add_belonging(Record * belonging);
	void add_attribute(Data_Object * attribute);
private:
	vector<Data_Object*> attributes{};
	vector<Record*> belongings{};

};
#endif //DATABASE_CONCEPT_DATABASE_H
