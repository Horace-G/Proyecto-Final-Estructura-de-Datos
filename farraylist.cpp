#include "farraylist.h"
#include "object.h"
#include "tdalist.h"
#include <sstream>

FArrayList::FArrayList(int c){
capacity = c;
data = new Object*[capacity];
}

FArrayList::~FArrayList() {
delete[] data;
}

Object* FArrayList::remove(unsigned int p) {
if (isEmpty())
return NULL;
if (!(p >= 0 && p < size()))
return NULL;

Object* retval = data[p];

if (p == size() - 1)
data[p] = NULL;
else {
for (int i = p; i < size() - 1; i++)
data[i] = data[i + 1];

data[size() - 1] = NULL;
}

ssize--;
return retval;
}

Object* FArrayList::first() const {
if (isEmpty())
return NULL;

return data[0];
}

Object* FArrayList::last() const {
if (isEmpty())
return NULL;

return data[size() - 1];
}

int FArrayList::getCapacity() const {
return capacity;
}

bool FArrayList::isFull() const {
return ssize == capacity;
}

void FArrayList::clear() {
delete[] data;

data = new Object*[capacity];
ssize = 0;
}

int FArrayList::indexOf(Object* E) const {
for (int i = 0; i < size(); i++) {
if(data[i]->equals(E))
return i;
}

return -1;
}

Object* FArrayList::get(unsigned int p) const {
if(isEmpty())
return NULL;
if(!(p >= 0 && p < size()))
return NULL;

return data[p];
}

bool FArrayList::insert(Object *e, int p) { // inserta un objeto en la posición p del arreglo
      if ( isFull() )
        return false;
      if ( !((p >= 0) && (p <= size())) )
        return false;
      if ( isEmpty() )
        data[p] = e;
      else {
        if ( p == size() )
          data[p] = e;
        else {
          for (int i = size() - 1; i >= p; i--)
            data[i + 1] = data[i];
          data[p]=e;
        }
      }
      ssize++;
      return true;
    } // fin del Insert

    int FArrayList::prev(int p) const{
     return (p-1);
    }

    int FArrayList::next(int p) const{
     return p+1;
    }

    void FArrayList::print()const{
for(int i=0;i<size();i++)
data[i]->print();
}