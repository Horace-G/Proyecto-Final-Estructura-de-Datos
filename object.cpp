#include "object.h"
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;
// Constructor por Defecto de Object
Object::Object(){
}
// Destructor de Object, necesario colocarlo para "definir" que los
// destructores de esta "Familia" de clases serán virtuales
Object::~Object(){
}
// Método de Impresión por defecto.
void Object::print()const{
    cout << "Object@" << this << endl;
}
// Metodo para devolver una cadena
string Object::toString()const{
	stringstream ss;
	ss << this;
	return ss.str();
}
// Método de Comparación por defecto, sólo compara las Direcciones.
bool Object::equals(Object* other)const{
    return this == other;
}



