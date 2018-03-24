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

using std::string;
using std::vector;

template <class T>
class Data<T>;

class Record;

class Record
{
  friend Data;
public:
  string name;
  explicit Record(string &name_c); //unimplemented
    :name(name_c)
  {}
  Record(string &name_c, Data::Data_Object *attribute, ...); //unimplemented
  Record(string &name_c, Record *belonging, ...); //unimplemented
  void add_attribute(); //unimplemented
  void add_belonging(); //unimplemented
private:
  vector<Data*> attributes{};
	vector<Record*> belongings{};
};


template <class T>
class Data<T>
{
  friend Record;
  class Data_Object
  {
    friend Data;
    T data;
    Data_Object *prev;
    Data_Object *next;
    vector<Record> mine;
    Data_Object(T &data_c, Record * owner);
    ~Data_Object();
  };
public:
  string name;
  Data_Object * add(T &data_c, Record * owner);
  Data_Object * search(T &data); //unimplemented
  Data(string &name_c);
  Data(string &name_c, T &data, Record * whose); //unimplemented
  Data(&Data old);
    { throw ("Copy constructor for Data Class is not yet implemented"); }
  ~Data(); //unimplemented
private:
  Data_Object * begin;
  Data_Object * end;
  Data_Object * search_poz(T &data); //unimplemented
};

template<class T>
Data::Data(string &name_c)
  :name(name_c) :end(0) :begin(0)
{}

template<class T>
Data<T>::Data_Object::Data_Object(T &data_c, Data::Data_Object * prev_n, Record * owner)
  :data(data_c) //applying data
{
  mine.push_back(owner); //setting ownership
	return new_n;
}

template<class T>
Data<T>::Data_Object::~Data_Object()
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

template<class T>
Data::Data_Object * Data::Data_Object::add(T &data_c, Record * owner)
{
  Data::Data_Object * ptr;
  if(begin == NULL)
  {
    ptr = new Data_Object(T &data_c, Record * owner);
    end = ptr;
    end = begin;
  }else
  {
    if(begin == end)
    {
      if(begin->data == data)
      {
        begin.mine.push_back(owner);
        return begin; //remember about this return
      }else
      {
        ptr = new Data_Object(T &data_c, Record * owner);
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
      ptr = search_poz(T &data_c);
      if(ptr->data == data)
      {
        ptr.mine.push_back(owner);
      }else
      {
        Data::Data_Object * tmp = ptr->next;
        ptr->next = new Data::Data_Object(T &data_c, Record * owner);
        ptr->next->prev = ptr;
        ptr=ptr->next;
        ptr->next = tmp;
        ptr->next->prev = ptr;
      }
    }
  }
  return ptr;
}

#endif //DATABASE_CONCEPT_DATABASE_HPP
