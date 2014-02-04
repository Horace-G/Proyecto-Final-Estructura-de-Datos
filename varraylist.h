#ifndef VARRAYLIST_H
#define VARRAYLIST_H
#include "object.h"
#include "tdalist.h"

class VArrayList : public TDAList
{
public:
VArrayList(int,int);
virtual ~VArrayList();
virtual bool insert(Object*,int);/////////
virtual Object* remove(unsigned int);/////////
virtual Object* first() const;/////////
virtual Object* last() const;/////////
virtual int getCapacity() const;
virtual bool isFull() const;/////////
virtual void clear();/////////
virtual int indexOf(Object*) const;/////////
virtual Object* get(unsigned int) const;/////////
virtual int prev(int) const;
virtual int next(int) const;
virtual void print()const;
//prev
//next

private:
unsigned int capacity;
double increment;
Object** data;
bool makebigger();
};

#endif