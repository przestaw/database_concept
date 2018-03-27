/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef DATABASE_CONCEPT_DATABASE_HPP
#define DATABASE_CONCEPT_DATABASE_HPP

#include <vector>
#include <string>

#define string std::basic_string<char>
using std::vector;

class Record;

template <class T, class O = void>
class Data_Object
{
	//friend Data<T,O>;
public:
	T data;
	Data_Object *prev;
	Data_Object *next;
	void add_owner(O * owner);
	explicit Data_Object(T &data_c);
	~Data_Object();
	vector<Record*> mine;
};


template <class T, class O = void>
class Data
{
public:
	explicit Data() {}; // for future ideas
	Data<T,O>(const Data<T,O> &old){throw ("Copy constructor for Data Class is not yet implemented"); };
	Data_Object<T,O> * add(T &data_a, O * owner);
	Data_Object<T,O> * search(T &data);
private:
	Data_Object<T,O> * begin;
	Data_Object<T,O> * end;
	Data_Object<T,O> * search_poz(T &data);
};

class Record //deprecated
{
public:
	string name;
	explicit Record(string &name_c)
			:name(name_c)  {};
	Record(string &name_c, Record *belonging);
	//void add_attribute(); //unimplemented
	void add_belonging(Record *belonging);
private:
	//vector<void*> attributes{};
	vector<Record*> belongings{};
};

// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -

template <class T, class O>
Data_Object<T,O>::Data_Object (T &data_c)
		:data(data_c), prev(0), next(0)
{}

template <class T, class O>
Data_Object<T,O>::~Data_Object<T,O>()
{
	if(this->next != NULL || this->prev != NULL)
	{
		if(this->next != NULL && this->prev != NULL)
		{
			this->next->prev = this->prev;
			this->prev->next = this->next;
		}
		if (this->next == NULL)
		{
			this->prev->next = this->next;
		}
		if (this->prev == NULL)
		{
			this->next->prev = this->prev;
		}
	}
}

template <class T, class O>
void Data_Object<T,O>::add_owner(O *owner)
{
	mine.push_back(owner);
}

// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -

//template <class T, class O>
//Data::Data()

template <class T, class O>
Data_Object<T,O> * Data<T,O>::search_poz(T &data)
{
	Data_Object<T,O> * ptr;
	for(ptr = begin; ptr != end; ptr=ptr->next)
	{
		if(ptr->data == data)
		{
			return ptr;
		}
		if(ptr->data > data)
		{
			return ptr->prev;
		}
	}
	return NULL;			//consider adding variant for 1 element list
}

template <class T, class O>
Data_Object<T,O> * Data<T,O>::search(T &data)
{
	Data_Object<T,O> * ptr;
	if( (ptr = search_poz(&data))->data == data)
	{
		return ptr;
	}else
	{
		return NULL;
	}
}

template <class T, class O>
Data_Object<T,O> * Data<T,O>::add(T &data_a,O * owner)
{
	Data_Object<T,O> * ptr;
	if(begin == NULL)
	{
		ptr = new Data_Object<T,O>(&data_a);
		end = ptr;
		end = begin;
	}else
	{
		if(begin == end)
		{
			if(begin->data == data_a)
			{
				begin->add_owner(owner);
				return begin; //remember about this return
			}else
			{
				ptr = new Data_Object<T,O>(&data_a);
				ptr->next->add_owner(owner);
				if(begin->data < ptr->data)
				{
					end = ptr;
				}else
				{
					begin = ptr;
				}
			}
		}else
		{
			ptr = search_poz(&data_a);
			if(ptr->data == data_a)
			{
				ptr->mine.push_back(owner);
			}else
			{
				Data_Object<T,O> * tmp = ptr->next;
				ptr->next = new Data_Object<T,O>(&data_a);
				ptr->next->add_owner(owner);
				ptr->next->prev = ptr;
				ptr=ptr->next;
				ptr->next = tmp;
				ptr->next->prev = ptr;
			}
		}
	}
	return ptr;
}

// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -



#endif //DATABASE_CONCEPT_DATABASE_HPP
