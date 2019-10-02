#include <iostream>
#include "Postre.h"
using namespace std;
Postre::Postre() {
}

Postre::Postre(string nombre) {
    this->nombre = nombre;
}

string Postre::getNombre() {
    return this->nombre;
}

