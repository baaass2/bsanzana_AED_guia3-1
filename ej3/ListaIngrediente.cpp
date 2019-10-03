#include <iostream>
#include "ListaIngrediente.h"
using namespace std;

ListaIngrediente::ListaIngrediente() {}

Nodo2* ListaIngrediente::crear (Ingrediente* ingre) {
	
    Nodo2 *tmp = new Nodo2();   
    Nodo2 *aux = new Nodo2();
    Nodo2 *aux2 = new Nodo2();

    tmp->ingre = ingre;
    
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
				if( indiceStr == tmp->ingre->getNombre().length() ){
					string ingreActual;
					string ingreIngresar;
					
					//Esto es para comparar 2 palabras iguales.
					ingreActual = mayuscula(aux);
					ingreIngresar  = mayuscula(tmp);
					// Se este ingresando palabras iguales
					if(ingreActual == ingreIngresar){
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
void ListaIngrediente::imprimir () {  
	Nodo2 *tmp = this->raiz;
	
	cout << " | ";
    while (tmp != NULL) {
		cout << tmp->ingre->getNombre()<< " | ";
        tmp = tmp->sig;
    }
    cout << "" << endl;
}

void* ListaIngrediente::eliminarNodo(string nombreEliminar){
	
	Nodo2 *nEliminar;
    Nodo2 *nAnterior = NULL;
    
	nEliminar = this->raiz;
	
	while(nEliminar != NULL and nEliminar->ingre->getNombre() != nombreEliminar){
		nAnterior = nEliminar;
		nEliminar = nEliminar->sig;
	}
	if(nEliminar == NULL){
		cout << "No se ha encontrado el ingre..."<<endl;
	}
	else if(nAnterior == NULL){
		cout << "Se encontro el ingre inicio..."<<endl;
		this->raiz = this->raiz->sig;
		delete nEliminar;
	}
	else{
		cout << "Se encontro el ingre ..."<<endl;
		nAnterior->sig = nEliminar->sig;
		delete nEliminar;
	}
}

int ListaIngrediente::valorLetra(Nodo2 *tmp, int indiceStr){
	
	int valorLetra = 0;
	
	for(int i=0; i<27; i++){
		if(tmp->ingre->getNombre()[indiceStr] == minAlfabeto[i] or tmp->ingre->getNombre()[indiceStr] == mayAlfabeto[i]){
			valorLetra = intAlfabeto[i];
			break;
		}
	}
		
	return valorLetra;
}

Nodo2* ListaIngrediente::getUltimo(){
	return this->ultimo;
}


Nodo2* ListaIngrediente::getRaiz(){
	return this->raiz;
}

string ListaIngrediente::mayuscula(Nodo2 *tmp){
	 
	string str = tmp->ingre->getNombre();
	
	for(int i = 0; i < tmp->ingre->getNombre().length(); i++){
		str[i] = toupper(str[i]);
	}
	return str;
}

