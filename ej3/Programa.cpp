#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#include "Nodo.h"
#include "Lista.h"
#include "Postre.h"


void imprimirLista(Nodo* tmp){
	
	
	if(tmp == NULL){
		cout << "No existen postres en la lista..."<<endl;
	}else{
		cout << " | ";
		while (tmp != NULL) {
			cout << tmp->postre->getNombre()<< " | ";
			tmp = tmp->sig;
		}
		cout << "" << endl;
	}
}

int main (void) {

    Lista *lista = new Lista();
    
    Nodo *raiz = NULL;
    
    char opc = '0';
    char stop = 'F';
    string nombre;
	
	cout << "... ... ... ... ... ... .... ...... ... ..."<<endl;
	cout << "... ... ... ... ... ... .... ...... ... ..."<<endl;
	cout << "... ... ... ... ... MENU ...... ... ... ..."<<endl; 
	cout << "... ... ... ... ... ... .... ...... ... ..."<<endl;
	
	while(opc != 's' and opc != 'S'){
		stop = 'F';
		cout << "-------------------------------------------"<<endl;
		cout << "*[1] Mostrar lista de postres...           "<<endl;
		cout << "*[2] Agregar postre...                     "<<endl;
		cout << "*[3] Eliminar postre...                    "<<endl;
		//cout << "*[4] Seleccionar postre...                 "<<endl;
		cout << "-------------------------------------------"<<endl;
		cout << "Escriba el numero de la opcion...! : "; cin >> opc;
		cout << "-------------------------------------------"<<endl;
		
		
		if(opc == '1'){
			raiz = lista->getRaiz();
			imprimirLista(raiz);
		}
		else if(opc == '2'){
			while(stop != 'V'){

				cout << "Ingrese nombre de postres a la lista: "; 
				cin >> nombre;
				
				Postre *postre = new Postre(nombre);
				raiz = lista->crear(postre);
				lista->imprimir();
				cout << "Para detener escriba V, seguir F: ";cin >> stop;
			}
		}
		else if(opc == '3'){
			cout << "Nombre de postre a eliminar: ";cin >> nombre;
			lista->eliminarNodo(nombre);
			
			cout << "Lista de postres..."<<endl;
			raiz = lista->getRaiz();
			imprimirLista(raiz);	
		}
		//else if(opc == '4'){
			
			//Postre *postre = new Postre;
			
			//cout << "Nombre de postre a revisar: ";cin >> nombre;
			//raiz = lista->getRaiz();
			
			//while(raiz != NULL){
				//if(raiz->postre->getNombre() == nombre){
					//postre = raiz->postre;
					//break;
				//}
				//raiz = raiz->sig;
			//~ }
			
			//~ if(raiz == NULL){
				//~ cout << "No se ha encontrado el postre.."<< endl;
			//~ }else{
				
				//~ Lista *listaIngre = new Lista();
				//~ listaIngre = postre->getLista();
				
				//~ Nodo *tmp = NULL;
				
				//~ cout << "---------------------------------------"<<endl;
				//~ cout << "*[1] Mostrar ingredientes...           "<<endl;
				//~ cout << "*[2] Agregar ingredientes...           "<<endl;
				//~ cout << "*[3] Eliminar ingredientes...          "<<endl;
				//~ cout << "-------------------------------------------"<<endl;
				//~ cout << "Escriba el numero de la opcion...! : "; cin >> opc;
				
				//~ if(opc == '1'){
					//~ tmp = listaIngre->getRaiz();
					//~ imprimirLista(tmp);
				//~ }
				//~ else if(opc == '2'){
					//~ while(stop != 'V'){
						//~ cout << "Ingrese nombre de ingredientes a la lista: "; 
						//~ cin >> nombre;
						//~ postre->agregarIngrediente(nombre);
						//~ listaIngre->imprimir();
						//~ cout << "Para detener escriba V, seguir F: ";cin >> stop;
					//~ }
				//~ }
				//~ else if(opc == '3'){
					//~ cout << "Ingrese nombre de ingredientes que desea eliminar: "; 
					//~ cin >> nombre;
					//~ postre->eliminarIngrediente(nombre);
					//~ cout << "Lista de ingredientes..."<<endl;
					//~ raiz = listaIngre->getRaiz();
					//~ imprimirLista(raiz);
				//~ }
			//~ }
		//~ }	
		cout << "Escriba (s/S) para cerrar programa o de lo contrario escriba un caracter diferente...!: "; cin >> opc;
	}
	
    return 0;
}

