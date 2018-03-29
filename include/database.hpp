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
#include <iostream>

#define string std::basic_string<char>
//using std::string;
using std::vector;
using std::ostream;

template <class T, class O = void>
class Data_Object;
template <class T, class O = void>
class Data;

enum direction {forward, reverse};

template <class T, class O>
ostream& operator<<(ostream& os, const Data<T,O> &obj_ptr);

template <class T, class O>
class Data_Object
{
	friend Data<T,O>;
public:
	T data;
	void add_owner(O * owner);
	Data_Object<T,O> * move(direction dir);
	explicit Data_Object(T data_c);
	~Data_Object();
private:
	Data_Object *prev;
	Data_Object *next;
	vector<O*> mine;
	//friend ostream& operator<< <>(ostream& os, const Data_Object<T,O>  &obj_ptr);
};


template <class T, class O>
class Data
{
public:
	explicit Data() :begin(nullptr), end(nullptr){};
	~Data();
	Data<T,O>(const Data<T,O> &old){throw ("Copy constructor for Data Class is not yet implemented"); };
	Data_Object<T,O> * add(T data_a, O * owner);
	//Data_Object<T,O> * search(T &data); //deprecated
	Data_Object<T,O> * get_end() {return end;};
	Data_Object<T,O> * get_begin() {return begin;};
	int get_size();
	friend ostream& operator<<<>(ostream& os, const Data<T,O> &obj_ptr);
private:
	Data_Object<T,O> * begin;
	Data_Object<T,O> * end;
	Data_Object<T,O> * search_poz(T &data);
};

// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -

template <class T, class O>
Data_Object<T,O>::Data_Object (T data_c)
		:data(data_c), prev(0), next(0)
{}

template <class T, class O>
Data_Object<T,O>::~Data_Object<T,O>()
{
	if(this->next != nullptr || this->prev != nullptr)
	{
		if(this->next != nullptr && this->prev != nullptr)
		{
			this->next->prev = this->prev;
			this->prev->next = this->next;
		}
		if (this->next == nullptr)
		{
			this->prev->next = this->next;
		}
		if (this->prev == nullptr)
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

template <class T, class O>
ostream& operator<<(ostream& os, const Data_Object<T,O>  &obj_ptr)
{
	os << obj_ptr.data;
	return os;
}

template <class T, class O>
Data_Object<T,O> * Data_Object<T,O>::move(direction dir)
{
	if(dir == forward)
	{
		return next;
	}else
	{
		return prev;
	}
}

// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -

//template <class T, class O>
//Data::Data()

Data::~Data();
{
	delete this->begin;
}
template <class T, class O>
Data_Object<T,O> * Data<T,O>::search_poz(T &data)
{
	Data_Object<T,O> * ptr = begin;
	if(ptr){
		if(ptr->data == data)
		{
			return ptr;
		}
		do{
			ptr=ptr->next;
			if(ptr->data == data)
			{
				return ptr;
			}
		}while(ptr != end);
	}
/*
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
*/
	return nullptr;
}
/*			// - - Deprecated - -  - - Deprecated - - - - Deprecated - -
template <class T, class O>
Data_Object<T,O> * Data<T,O>::search(T &data)
{
	Data_Object<T,O> * ptr;
	if( (ptr = search_poz(&data))->data == data)
	{
		return ptr;
	}else
	{
		return nullptr;
	}
}
*/		// - - Deprecated - -  - - Deprecated - - - - Deprecated - -
template <class T, class O>
int Data<T,O>::get_size()      return &i;

{
	Data_Object<T,O> * ptr = begin;
	int i=0;
	if(ptr){
		do{
			ptr=ptr->next;
			++i;
		}while(ptr != end);
	}
	return i;
}

template <class T, class O>
Data_Object<T,O> * Data<T,O>::add(T data_a,O * owner)
{
	Data_Object<T,O> * ptr;
	if(begin == nullptr)
	{
		ptr = new Data_Object<T,O>(data_a);
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
				ptr = new Data_Object<T,O>(data_a);
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
			ptr = search_poz(data_a);
			if(ptr->data == data_a)
			{
				ptr->mine.push_back(owner);
			}else
			{
				Data_Object<T,O> * tmp = ptr->next;
				ptr->next = new Data_Object<T,O>(data_a);
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

template <class T, class O>
ostream& operator<<(ostream& os, const Data<T,O> &obj_ptr)
{
	Data_Object<T,O> * ptr;
	Data_Object<T,O> * ptr_e;
	ptr = obj_ptr.begin;
	ptr_e = obj_ptr.end;
	if(ptr){
		os << ptr << '\n';
		do{
			ptr->move(forward);
			os << ptr << '\n';
		}while(ptr != ptr_e);
	}
	return os;
}

// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -
#endif //DATABASE_CONCEPT_DATABASE_HPP
