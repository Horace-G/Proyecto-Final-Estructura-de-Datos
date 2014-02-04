#ifndef INTEGER_H
#define INTEGER_H

#include "object.h"

/*
* Esta clase sirve para representar un número entero.
* Es necesario "envolver" el entero dentro de una clase para poder insertarlo
* en nuestros TDA's pues los mismos aceptan elementos de tipo Object.
* Es por esa razón que Integer es descendiente de Object, para poder ser
* utilizado en nuestros TDA's
* Para que funcionen las operaciones (métodos) de búsqueda, es necesario
* que esté correctamente implementado el método equals de esta clase.
* Si se quiere tener un método de impresión personalizado, se deberá también
* definir el método print.
*/

class Integer : public Object{
    int value;
  public:
    Integer(int=0);
    virtual ~Integer();
    virtual void print()const;
    virtual string toString()const;
    virtual bool equals(Object*)const;
    void setValue(int);
    int getValue()const;  
};

#endif
