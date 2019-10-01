#include <iostream>
using namespace std;
#ifndef LISTA_H
#define LISTA_H


class Lista {
    private:
        Nodo *raiz = NULL;
        Nodo *ultimo = NULL;
        char mayAlfabeto[27] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        char minAlfabeto[27] = {' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		int intAlfabeto[27] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
		
    public:
        Lista();
        Nodo* crear (Postre *postre);
        Nodo* getUltimo();
        Nodo* getRaiz();
		void imprimir ();
		int valorLetra(Nodo *tmp, int indiceStr);
		void* eliminarNodo(string nombreEliminar);
		string mayuscula(Nodo *tmp);

};
#endif
