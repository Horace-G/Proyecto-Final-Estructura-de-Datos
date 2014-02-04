#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "object.h"
#include "tdalist.h"
#include "dllnode.h"
/*
* Declaración de la Clase LinkedList, que es una implementación del TDAList
* utilizando listas doblemente enlazadas. Nótese la herencia en esta clase.
* Nótese así mismo, que están todas las operaciones virtuales puras de la
* clase TDAList, pues acá se tendrán que definir cada una de estas.
* El único miembro que tiene esta clase es head, que representa la cabeza de
* la lista, no es necesario tener size, pues lo heredamos de la clase base.
*/
class LinkedList : public TDAList{
  protected:
    DLLNode* head;
  public:
    LinkedList();
    virtual ~LinkedList();
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned)const ;
    virtual Object* remove(unsigned) ;
    virtual int prev(int) const ;
    virtual int next(int) const ;
    virtual void clear();
    virtual Object* first()const ;
    virtual Object* last()const ;
    virtual void print()const ;
    virtual bool isFull()const;
};

#endif