#include <iostream>
#include <stdio.h>
#include <string>
#include "Postre.h"

using namespace std;

typedef struct _Nodo {
    Postre *postre;
    struct _Nodo *sig;
} Nodo;
