#include <iostream>
using namespace std;
#include "Lista.h"

void imprimirLista(Nodo* tmp){
	
	cout << " | ";
    while (tmp != NULL) {
		cout << tmp->num << " | ";
        
        tmp = tmp->sig;
    }
    cout << "" << endl;
}
int main (void) {

    Lista *lista = new Lista();
    Lista *lista2 = new Lista();
    Lista *lista3 = new Lista();
    
    Nodo *t = NULL;
 
    Nodo *p = new Nodo();
    Nodo *n = new Nodo();
    
    
    char stop = 'F';
    int num = 0;
    
    cout << "Ingresando datos a la lista ..."<<endl;
    while(stop != 'V'){
		cout << "Ingrese entero a la lista: ";cin >> num;	
		t=lista->crear(num);
		cout << "Para detener escriba V, seguir F: ";cin >> stop;
	}
	cout << "Lista ingresada..."<<endl;
	lista->imprimir();

	while(t != NULL){
		if(t->num < 0){
			n=lista2->crear(t->num);
		}
		
		else if(t->num > 0){
			p=lista3->crear(t->num);
		}
		t = t->sig;
	}
	cout << "Lista de negativos..."<<endl;
	imprimirLista(n);
	
	
	cout << "Lista de positivos..."<<endl;
	imprimirLista(p);
    return 0;
}
