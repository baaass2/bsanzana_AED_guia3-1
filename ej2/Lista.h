#include <iostream>
using namespace std;
#ifndef LISTA_H
#define LISTA_H

typedef struct _Nodo {
    string str;
    struct _Nodo *sig;
} Nodo;

class Lista {
    private:
        Nodo *raiz = NULL;
        Nodo *ultimo = NULL;
        char alfabeto[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
		int intAlfabeto[26] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
		
    public:
        Lista();
        Nodo* crear (string str);
        Nodo* getUltimo();
		void imprimir ();

};
#endif
