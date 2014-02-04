#ifndef OBJECT_H
#define OBJECT_H

#include <string>
using std::string;

/****************************************************************************
* Esta es la clase padre de casi todas las clases que se utilizan en        *
* esta muestra. Es importante tener una Súper-Clase para poder utilizar     *
* este tipo base en los elementos (tipo_dato del libro de Aho) de todos los *
* TDA's que se implementen.                                                 *
*****************************************************************************/

class Object
{
  public:
    Object();
    virtual ~Object();
    virtual void print()const;
    virtual string toString()const;
    virtual bool equals(Object*)const;
};
#endif
