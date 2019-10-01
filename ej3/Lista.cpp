#include <iostream>
#include "Nodo.h"
#include "Lista.h"
using namespace std;

Lista::Lista() {}


Nodo* Lista::crear (Postre* postre) {
	
    Nodo *tmp = new Nodo();   
    Nodo *aux = new Nodo();
    Nodo *aux2 = new Nodo();

    tmp->postre = postre;
    
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
			
			valorRaiz = valorLetra(this->raiz, indiceStr);
			valorUltimo = valorLetra(this->ultimo, indiceStr);
			valorStr = valorLetra(tmp, indiceStr);
			valorAux = valorLetra(aux, indiceStr);
			
			if(aux2 != NULL){
				valorAux2 = valorLetra(aux2, indiceStr);
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
				//si el indice es igual al tamaño del string, hay 2 opciones.
				if( indiceStr == tmp->postre->getNombre().length() ){
					string postreActual;
					string postreIngresar;
					
					//Esto es para comparar 2 palabras iguales.
					postreActual = mayuscula(aux);
					postreIngresar  = mayuscula(tmp);
					// Se este ingresando palabras iguales
					if(postreActual == postreIngresar){
						aux->sig = tmp;
						tmp->sig = aux2;	
					// Es que vaya al ultimo.	
					}else{				
						aux->sig= tmp;
						tmp->sig=NULL;
				
						this->ultimo->sig = tmp;
						this->ultimo = tmp;
					}
						
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
		cout << tmp->postre->getNombre()<< " | ";
        tmp = tmp->sig;
    }
    cout << "" << endl;
}

void* Lista::eliminarNodo(string nombreEliminar){
	
	Nodo *nEliminar;
    Nodo *nAnterior = NULL;
    
	nEliminar = this->raiz;
	
	while(nEliminar != NULL and nEliminar->postre->getNombre() != nombreEliminar){
		nAnterior = nEliminar;
		nEliminar = nEliminar->sig;
	}
	if(nEliminar == NULL){
		cout << "No se ha encontrado el postre..."<<endl;
	}
	else if(nAnterior == NULL){
		cout << "Se encontro el postre inicio..."<<endl;
		this->raiz = this->raiz->sig;
		delete nEliminar;
	}
	else{
		cout << "Se encontro el postre ..."<<endl;
		nAnterior->sig = nEliminar->sig;
		delete nEliminar;
	}
}

int Lista::valorLetra(Nodo *tmp, int indiceStr){
	
	int valorLetra = 0;
	
	for(int i=0; i<27; i++){
		if(tmp->postre->getNombre()[indiceStr] == minAlfabeto[i] or tmp->postre->getNombre()[indiceStr] == mayAlfabeto[i]){
			valorLetra = intAlfabeto[i];
			break;
		}
	}
		
	return valorLetra;
}

Nodo* Lista::getUltimo(){
	return this->ultimo;
}


Nodo* Lista::getRaiz(){
	return this->raiz;
}

string Lista::mayuscula(Nodo *tmp){
	 
	string str = tmp->postre->getNombre();
	
	for(int i = 0; i < tmp->postre->getNombre().length(); i++){
		str[i] = toupper(str[i]);
	}
	return str;
}

