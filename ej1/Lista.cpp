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

