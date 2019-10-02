#include <iostream>
#include "Ingrediente.h"
using namespace std;
Ingrediente::Ingrediente() {
}

Ingrediente::Ingrediente(string nombre) {
    this->nombre = nombre;
}

string Ingrediente::getNombre() {
    return this->nombre;
}
