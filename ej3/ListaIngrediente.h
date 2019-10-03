#include <iostream>
#include "Ingrediente.h"
using namespace std;
#ifndef LISTAINGREDIENTE_H
#define LISTAINGREDIENTE_H

using namespace std;

typedef struct _Nodo2 {
    Ingrediente *ingre;
    struct _Nodo2 *sig;
} Nodo2;


class ListaIngrediente {
    private:
        Nodo2 *raiz = NULL;
        Nodo2 *ultimo = NULL;
        char mayAlfabeto[27] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        char minAlfabeto[27] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		int intAlfabeto[27] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
		
    public:
        ListaIngrediente();
        Nodo2* crear (Ingrediente *ingre);
        Nodo2* getUltimo();
        Nodo2* getRaiz();
		void imprimir ();
		int valorLetra(Nodo2 *tmp, int indiceStr);
		void* eliminarNodo(string nombreEliminar);
		string mayuscula(Nodo2 *tmp);

};
#endif
