#include "varraylist.h"
#include "object.h"
//#include "tdalist.h"

VArrayList::VArrayList(int c,int p){
capacity = c;
data=new Object*[capacity];
increment=p/10;
}

VArrayList::~VArrayList(){
delete[] data;
}

 bool VArrayList::makebigger(){ //incrementa el tamaño del arreglo por 50%

      Object** tmp = new Object*[(int)((size()*0.5) + size())]; // Crea un arreglo nuevo con 50% más de tamaño

      if (!tmp) // si no hay memoria para crear el arreglo retorna false

        return false;

      for ( int i=0; i < size(); i++ ) // llena el nuevo arreglo con los elementos del arreglo anterior

        tmp[i] = data[i];

      data = tmp; // se hace que data apunte al nuevo arreglo

      capacity += (size()*0.5)+size(); // se aumenta la variable capacity

      return true; // retorna true que la operación fue realizada con éxito

    } //fin de makebigger

     

     

    bool VArrayList::insert(Object* E,int p){ //añade un elemento a el arreglo.

      if( isFull() ) // Verifica si el arreglo se encuentra lleno

        if( !makebigger() ) // Llama al método makebigger. Si este retorna false, no hay memoria para extender

          return false; // el arreglo y no se puede insertar el nuevo objeto.

      if(!(p >= 0 && p <= size())) // Verifica que p sea un índice valido

        return false;

      if( isEmpty() ) // Verifica si el arreglo está vacío. Si lo está, inserta el objeto en la primera posición

        data[p] = E;

      else{

        if(p == size()) // Si p es igual a la última posición vacía del arreglo, lo inserta allí

          data[p] = E;

        else{

          for(int i = size() - 1; i >= p; i--) // Recorre el arreglo y realiza los corrimientos necesarios de

            data[i + 1] = data[i]; // los índices posteriores a p. Luego asigna e a la posición p.

          data[p] = E;

        }

      }

      ssize++; // Incrementa el tamaño de size
      makebigger();

      return true; // Retorna verdadero que la inserción se realizo con éxito

    } //Fin de insert

     

    Object* VArrayList:: remove (unsigned int p ) { // elimina un elemento en el indice p del arreglo
      if (!(p >= 0 && p < size())) // revisa que p sea un indice valido
        return NULL;
      if ( isEmpty() ) // si el arreglo esta vacio retorna NULL
        return NULL;
      Object* retval = data[p]; // asigna a un temporal el elemento que se va a remover
      if (p == size()-1) // si el elemento esta al final del arreglo, lo elimina
        data[p]=NULL;
      else { // si el elemento no esta al final, hace el corrimiento necesario de los elementos posteriores
        for ( int i = p; i<size()-1; i++ ) // al elemento p
          data[i]=data[i+1];
        data[size()-1]=NULL;
      }
      ssize--; // reduce el tamaño de size
      return retval; // retorna true si el objeto fue eliminado

    } // fin del remove

     

     

    Object* VArrayList::first() const{

      if( isEmpty() )//Si el arreglo se encuentra vacío devuelve un NULL

        return NULL;

      if ( size() >= 1 )//Si el arreglo contiene por lo menos un dato devuelvo el primer Object* que se encuentra en esa posición

        return data[0];

    } // fin de first

     

     

    Object* VArrayList::last() const{

      if( isEmpty() )//Si el arreglo se encuentra vacío devuelve un NULL

        return NULL;

      if ( size() >= 1 )//Si el arreglo contiene por lo menos un dato devuelvo el ultimo Object* que se encuentra en esa posición

        return data[size() - 1];

    } //Fin de last

     

     

    Object* VArrayList::get(unsigned int p) const{

      if( isEmpty() )//si el arreglo esta vacío devuelve NULL

        return NULL;

      if( !(p >= 0) && (p < size()) )// si la posición no se encuentra en el rango correcto entonces devuelve NULL

        return NULL; // de lo contrario retorna el objeto

      return data[p];// retorna el Object* de la posición p

    } //fin de get

    int VArrayList::indexOf(Object* E) const{ // Método que retorna la posición del objeto e en el arreglo

      if( isEmpty() ) // Si el arreglo está vacío, retorna -1

        return -1;

      int posicion = -1;

      for(int i = 0; i < size() ; i++){ // Recorre el arreglo y si encuentra el objeto e en el arreglo

        if(data[i] == E){ // asigna el índice de la iteración a la variable posición si existe e

          posicion = i; // en el arreglo

          break;

        } //Fin del if

      } //Fin del for

      return posicion; // retorna el valor de posición

    } //fin del indexOf

     

     

    bool VArrayList::isFull() const{ // Método que retorna el estado del arreglo

      if( size() == capacity ) // Si el tamaño del arreglo es igual a la capacidad, retorna true

        return true;

      return false;

    } //Fin isFull

     

     

    void VArrayList::clear(){ // limpia todos los elementos del arreglo

      delete[] data; // libera la memoria del arreglo

      data = new Object*[capacity]; // genera un nuevo arreglo en memoria y lo asigna a data
      ssize = 0;

    } //Fin de clear

    int VArrayList::prev(int p) const{
     return (p-1);
    }

    int VArrayList::next(int p) const{
     return p+1;
    }

    void VArrayList::print()const{
for(int i=0;i<size();i++)
data[i]->print();
}

int VArrayList::getCapacity() const{
return capacity;
} 

