#include <iostream>
#include "Postre.h"
using namespace std;
Postre::Postre() {
}

Postre::Postre(string nombre) {
    this->nombre = nombre;
	//this->listaIngredientes = listaIngredientes;
}

string Postre::getNombre() {
    return this->nombre;
}

//Lista Postre::getLista(){
	//return this->listaIngredientes;
//}

//void Postre::agregarIngrediente(string ingrediente){
	//this->listaIngredientes->crear(ingrediente);
//}

//void Postre::eliminarIngrediente(string ingrediente){
	//this->listaIngredientes->eliminarNodo(ingrediente);	
//}

