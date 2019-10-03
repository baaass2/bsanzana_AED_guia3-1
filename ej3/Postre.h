#include <iostream>
#include "ListaIngrediente.h"
using namespace std;
#ifndef POSTRE_H
#define POSTRE_H

class Postre{
    private:
        string nombre = "\0";
        ListaIngrediente listaIngrediente;
    public:
		Postre();
        Postre(string nombre);
        string getNombre();
        ListaIngrediente getLista();
        ListaIngrediente setLista(ListaIngrediente listaIngrediente);
};
#endif
