#include <iostream>
using namespace std;
#include "Lista.h"

Lista::Lista() {}

Nodo* Lista::crear (int num) {
    Nodo *tmp;
    Nodo *aux;
    Nodo *aux2;
    
    tmp = new Nodo;
    tmp->num = num;

	//Si la lista esta vacia//
    if (this->raiz == NULL) { 
        this->raiz = tmp;
        tmp->sig = NULL;
        this->ultimo = this->raiz;
    }else {
		aux = this->raiz;
        while( aux != NULL ){
			aux2 = aux->sig;
			//Si el num que se ingresa es menor a la raiz
			if(tmp->num <= aux->num){
				tmp->sig = this->raiz;
				this->raiz = tmp;
				break;
			}
			//Si el numero que se ingresa es mayor al ultimo
			else if(aux->num < tmp->num and aux2 == NULL){
				aux->sig= tmp;
				tmp->sig=NULL;
				this->ultimo = tmp;
				break;	
			}
			//Si es un numero que debe ir entre medio de la lista
			else if(aux->num < tmp->num and aux2->num >= tmp->num){
				aux->sig = tmp;
				tmp->sig = aux2;
				break;
			}else{
				//Iterador del while
				aux = aux->sig;
			}
		}
    }
    return this->raiz;
}
void Lista::imprimir () {  
	Nodo *tmp = this->raiz;
	
	cout << " | ";
    while (tmp != NULL) {
		cout << tmp->num<< " | ";
        
        tmp = tmp->sig;
    }
    cout << "" << endl;
}

Nodo* Lista::getUltimo(){
	return this->ultimo;
}

Nodo* Lista::rellenar(int max){
	
	Nodo *tmp = new Nodo();
	tmp->sig = NULL;
	
	Nodo *raiz = this->raiz;
	Nodo *tmp2 = NULL;
	int aux = (raiz->num)+1;
	
	// El ciclo funciona hasta que aux llegue hasta el ultimo valor del nodo.
	//El siguente fragmento es el que logra rellenar, se explica en el readme.
	while(aux != max){
		tmp2 = raiz->sig;
		
		Nodo *tmp = new Nodo();
		tmp->sig = NULL;
		tmp->num = aux;
		
		if(tmp2->num != tmp->num){
			raiz->sig = tmp;
			tmp->sig = tmp2;
			tmp2 = tmp;
		}	
		aux = aux +1;
		raiz = raiz->sig;
	}
	return this->raiz;
}

