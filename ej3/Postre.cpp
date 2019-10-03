#include <iostream>
#include "Postre.h"
#include "ListaIngrediente.h"
using namespace std;
Postre::Postre() {
}

Postre::Postre(string nombre) {
    this->nombre = nombre;
}

string Postre::getNombre() {
    return this->nombre;
}

ListaIngrediente Postre::getLista() {
    return this->listaIngrediente;
}

ListaIngrediente Postre::setLista(ListaIngrediente listaIngrediente) {
	this->listaIngrediente = listaIngrediente;
}
