#include <iostream>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include "Lista.h"

void imprimirLista(Nodo* tmp){
	
	cout << " | ";
    while (tmp != NULL) {
		cout << tmp->str << " | ";
        
        tmp = tmp->sig;
    }
    cout << "" << endl;
}
int main (void) {

    Lista *lista = new Lista();
    
     Nodo *tmp = new Nodo(); 
    
    char stop = 'F';
    string str = " ";

    cout << "Ingresando datos a lista ..."<<endl;
    while(stop != 'V'){
		cout << "Ingrese string a la lista: ";cin >> str;
		
		for(int i = 0; i < str.length(); i++){
			str[i] = toupper(str[i]);
		}
		
		tmp = lista->crear(str);
		lista->imprimir();
		cout << "Para detener escriba V, seguir F: ";cin >> stop;
	}

	cout << "Lista ordenada..."<<endl;
	imprimirLista(tmp);
    return 0;
}
