#include <iostream>
using namespace std;
#ifndef POSTRE_H
#define POSTRE_H

class Postre{
    private:
        string nombre = "\0";
    public:
		Postre();
        Postre(string nombre);
        string getNombre();
};
#endif
