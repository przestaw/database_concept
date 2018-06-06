/*
 *  Przemyslaw Stawczyk 293153
 *  Wiktor Kusmirek
 *  Second exercise for PROI course
 *	class declaration
 */

#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include <string>
#include <iostream>

#define string std::basic_string<char>

template <class T, class O>
class Data_Object;
template <class T, class O>
class Data;


enum direction {forward, reverse};


template <class T, class O>
std::ostream& operator<<(std::ostream& os, const Data<T,O> &obj_ptr);

template <class T, class O>
std::ostream& operator<<(std::ostream& os, const Data_Object<T,O>  &obj_ptr);


template <class T, class O>
class Data_Object
{
public:
	T get_data();
	T set_data(T data_s);
	void add_owner(O * owner);
	Data_Object<T,O> * move(direction dir);
	void set(direction dir, Data_Object * ptr);
	explicit Data_Object(T data_c);
	~Data_Object();
private:
	T data;
	Data_Object *prev;
	Data_Object *next;
	std::vector<O*> mine;
	friend std::ostream& operator<<<>(std::ostream& os, const Data_Object<T,O>  &obj_ptr);
};

template <class T, class O>
class Data
{
public:
	Data() :begin(nullptr), end(nullptr){};
	~Data();
	Data<T,O>(const Data<T,O> &old){throw ("Copy constructor for Data Class is not yet implemented"); };
	Data_Object<T,O> * add(T data_a, O * owner);
	//Data_Object<T,O> * search(T &data); //deprecated
	Data_Object<T,O> * get_end() {return end;};
	Data_Object<T,O> * get_begin() {return begin;};
	int get_size();
	friend std::ostream& operator<<<>(std::ostream& os, const Data<T,O> &obj_ptr);
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
T Data_Object<T,O>::get_data()
{
	return data;
}

template <class T, class O>
T Data_Object<T,O>::set_data(T data_s)
{
	data = data_s;
	return data;
}

template <class T, class O>
std::ostream& operator<<(std::ostream& os, const Data_Object<T,O>  &obj_ptr)
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
template <class T, class O>
void Data_Object<T,O>::set(direction dir, Data_Object * ptr)
{
	if(dir == forward)
	{
		next = ptr;
	}else
	{
		prev = ptr;
	}
}

// _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ - _ -

//template <class T, class O>
//Data::Data()
template <class T, class O>
Data<T,O>::~Data<T,O>()
{
	delete this->begin;
}

template <class T, class O>
Data_Object<T,O> * Data<T,O>::search_poz(T &data)
{
	Data_Object<T,O> * ptr = begin;
	if(ptr){
		if(ptr->get_data() == data)
		{
			return ptr;
		}
		do{
			ptr=ptr->move(forward);
			if(ptr->get_data() == data)
			{
				return ptr;
			}
		}while(ptr != end);
	}
	return nullptr;
}
/*			// - - Deprecated - -  - - Deprecated - - - - Deprecated - -
template <class T, class O>
Data_Object<T,O> * Data<T,O>::search(T &data)
{
	Data_Object<T,O> * ptr;
	if( (ptr = search_poz(&data))->get_data() == data)
	{
		return ptr;
	}else
	{
		return nullptr;
	}
}
*/		// - - Deprecated - -  - - Deprecated - - - - Deprecated - -
template <class T, class O>
int Data<T,O>::get_size()
{
	Data_Object<T,O> * ptr = begin;
	int i=0;
	if(ptr){
		do{
			ptr=ptr->move(forward);
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
			if(begin->get_data() == data_a)
			{
				begin->add_owner(owner);
				return begin; //remember about this return
			}else
			{
				ptr = new Data_Object<T,O>(data_a);
				(ptr->move(forward))->add_owner(owner);
				if(begin->get_data() < ptr->get_data())
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
			if(ptr->get_data() == data_a)
			{
				ptr->add_owner(owner);
			}else
			{
				Data_Object<T,O> * tmp = ptr->move(forward);
				ptr->set(forward,new Data_Object<T,O>(data_a));// = new Data_Object<T,O>(data_a);
				ptr->move(forward)->add_owner(owner);
				ptr->move(forward)->set(reverse, ptr);
				ptr=ptr->move(forward);
				ptr->set(forward, tmp);
				ptr->move(forward)->set(reverse, ptr);
			}
		}
	}
	return ptr;
}

template <class T, class O>
std::ostream& operator<<(std::ostream& os, const Data<T,O> &obj_ptr)
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
#endif //DATABASE_HPP
