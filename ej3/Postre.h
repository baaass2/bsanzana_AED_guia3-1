#include <iostream>

using namespace std;
#ifndef POSTRE_H
#define POSTRE_H

class Postre{
    private:
        string nombre = "\0";
		//Lista *listaIngredientes = new Lista();

    public:
		Postre();
        Postre(string nombre);
        
        
        //void agregarIngrediente(string ingrediente);
        //void eliminarIngrediente(string ingrediente);
        string getNombre();
        //Lista getLista();
};
#endif
