#include <iostream>
#include <cstdlib>
#include "tdalist.h"
#include "varraylist.h" //Arreglos de tamaño variable
#include "farraylist.h" //Arreglos de tamaño fijo
#include "slinkedlist.h" //Lista Enlazada Sencilla
#include "linkedlist.h" //Lista Doblemente Enlazada
#include "dlcursorlist.h" //Cursor de Tamaño Fijo simulando lista doblemente enlazada

#include "integer.h"

using namespace std;

/*
Programa Principal Proyecto I Estructura de Datos
*************************************************
*********** N O M O D I F I C A R ************
*************************************************

Usar nombres de encabezados que aparecen en los
#include arriba:
varraylist.h y varraylist.cpp
farraylist.h y farraylist.cpp
slinkedlist.h y slinkedlist.cpp
dlcursorlist.h y dlcursorlist.cpp

*/



void testTDA(TDAList*);

int main(int argc, char *argv[])
{

TDAList* list;

list = new VArrayList(10, 5);
testTDA(list);
delete list;


list = new FArrayList(25);
testTDA(list);
delete list;
   
list = new SLinkedList();
testTDA(list);
delete list;
   
   
list = new LinkedList();
testTDA(list);
delete list;
   
   
list = new DLCursorList();
testTDA(list);
delete list;
    
    return 0;
}


void testTDA(TDAList* list){
// Insert 20 numbers
for (int i=0; i<20; i++)
list->insert(new Integer(i*2), i);

// Print list
for (int i=0; i<list->size(); i++)
cout << list->get(i)->toString() << endl;

// Remove three Elements
Object* t = NULL;
t = list->remove(0);
delete t;
t = list->remove(10);
delete t;
t = list->remove(5);
delete t;

// Print list
for (int i=0; i<list->size(); i++)
cout << list->get(i)->toString() << endl;

cout << "First = " << list->first() << endl;
cout << "Last = " << list->last() << endl;

// indexOf
for (int i=0; i<20; i++){
cout << "list->indexOf(" << i << ") = " << list->indexOf( new Integer(i) ) << endl;
}

list->clear();
cout << "Size = " << list->size() << endl;

}