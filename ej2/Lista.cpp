#include <iostream>
using namespace std;
#include "Lista.h"

Lista::Lista() {}


Nodo* Lista::crear (string str) {
	
    Nodo *tmp = new Nodo();   
    Nodo *aux = new Nodo();
    Nodo *aux2 = new Nodo();

    tmp->str = str;
    
    int valorAux2 = 0;
    int valorAux = 0;
    int valorStr = 0;
    int valorRaiz = 0;
    int valorUltimo = 0;
    int indiceStr = 0;

    if (this->raiz == NULL) { 
        this->raiz = tmp;
        tmp->sig = NULL;
        this->ultimo = this->raiz;
    }
    else {
		
        aux = this->raiz;
        
        while( aux != NULL ){
			aux2 = aux->sig;
			
			for(int i=0; i<26; i++){
				if(this->raiz->str[indiceStr] == alfabeto[i]){
					valorRaiz = intAlfabeto[i];
					break;
				}
			}
			for(int i=0; i<26; i++){
				if(this->ultimo->str[indiceStr] == alfabeto[i]){
					valorUltimo = intAlfabeto[i];
					break;
				}
			}
			for(int i=0; i<26; i++){
				if(tmp->str[indiceStr] == alfabeto[i]){
					valorStr = intAlfabeto[i];
					break;
				}
			}
			for(int i=0; i<26; i++){
				if(aux->str[indiceStr] == alfabeto[i]){
					valorAux = intAlfabeto[i];
					break;
				}
			}
			
			if(aux2 != NULL){
				for(int i=0; i<26; i++){
					if(aux2->str[indiceStr] == alfabeto[i]){
						valorAux2 = intAlfabeto[i];
						break;
					}
				}
			}
			
			//Si el termino es debe ir al inicio de la lista
			if(valorStr < valorRaiz){
				tmp->sig = this->raiz;
				this->raiz = tmp;
				break;
			}
			//Si el termino es debe ir al final de la lista
			else if( valorUltimo < valorStr and aux2 == NULL){
				aux->sig= tmp;
				tmp->sig=NULL;
				
				this->ultimo->sig = tmp;
				this->ultimo = tmp;
				
				break;	
			}
			
			//Si el termino es debe ir al al medio de la lista
			else if(valorAux < valorStr and valorAux2 >= valorStr){
				aux->sig = tmp;
				tmp->sig = aux2;
				break;
			}
			//Si el tiene igual letra, se debe ver la siguente letra
			else if(valorAux == valorStr){
				int flag = 0;
				
				indiceStr = indiceStr + 1;
				//si el indice es igual al tamaño del string, la unica opcion es que vaya al ultimo
				if( indiceStr == tmp->str.length()){
					aux->sig= tmp;
					tmp->sig=NULL;
				
					this->ultimo->sig = tmp;
					this->ultimo = tmp;
					
					indiceStr = 0;
					flag = 1;
				}
				//Entonces ya que se sabe donde debe ir el elemento es necesario romper el while, pero tambien se debe tener cuidado
				//porque cuando ingresa a esta condicion no siempre debe romperse, por lo mismo se crea la variable flag.
				if(flag == 1){
					break;
				}
			}else{
				//En esta condicion es cuando se tiene que comparar con un elemento siguente
				indiceStr = 0;
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
		cout << tmp->str<< " | ";
        tmp = tmp->sig;
    }
    cout << "" << endl;
}

Nodo* Lista::getUltimo(){
	return this->ultimo;
}

