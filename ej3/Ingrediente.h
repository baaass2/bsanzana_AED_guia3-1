#include <iostream>

using namespace std;
#ifndef Ingrediente_H
#define Ingrediente_H

class Ingrediente{
    private:
        string nombre = "\0";
    public:
		Ingrediente();
        Ingrediente(string nombre);
        string getNombre();
};
#endif
