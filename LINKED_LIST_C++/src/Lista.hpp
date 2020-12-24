#include "Lista.h"

Lista::Lista() : primerNodo(NULL) {}

Lista::Lista(const Lista &l) : Lista() {

    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;

}

Lista::~Lista() {
    Nodo *actual = primerNodo;
    if (actual == NULL) { return; }
    while (actual->sig) {
        actual = actual->sig;
        delete actual->ant;
    }
    delete actual;
}

Lista &Lista::operator=(const Lista &aCopiar) {
    while (this->longitud() != 0) {
        eliminar(0);
    }
    if (aCopiar.primerNodo == NULL) {
        return *this;
    } // Si es una lista vacia, devuelvo una vacia.

    //---------------------------------
    Nodo *nuevoNodo = new Nodo;
    Nodo *paraBorrar = nuevoNodo;  // Esta parte es una guarangada. Pero funciona...
    nuevoNodo->data = aCopiar.primerNodo->data;
    nuevoNodo->sig = aCopiar.primerNodo->sig;
    while (nuevoNodo != NULL) {
        this->agregarAtras(nuevoNodo->data);
        nuevoNodo = nuevoNodo->sig;
        
    }
    delete paraBorrar;
    return *this;

}

void Lista::agregarAdelante(const int &elem) {
    Nodo *nuevoNodo = new Nodo;
    if (primerNodo) {
        Nodo *aux = primerNodo;
        primerNodo = nuevoNodo;
        primerNodo->data = (Nat) elem;
        primerNodo->ant = NULL;
        primerNodo->sig = aux;
        aux->ant = primerNodo;
    } else { // Aca entra si es el primer nodo que agregas.
        nuevoNodo->ant = NULL;
        nuevoNodo->sig = NULL;
        primerNodo = nuevoNodo;
        primerNodo->ant = NULL;
        primerNodo->data = (Nat) elem;
        primerNodo->sig = NULL;
        ultimoNodo = nuevoNodo;
        ultimoNodo->ant = NULL;
        ultimoNodo->data = (Nat) elem;
        ultimoNodo->sig = NULL;

    }
    longitudLista++;
}

void Lista::agregarAtras(const int &elem) {
    Nodo *nuevoNodo = new Nodo;
    if (primerNodo) { // Como primerNodo se inicializa en NULL, solo entra si fue modificado.
        Nodo *aux = ultimoNodo;
        ultimoNodo = nuevoNodo;
        ultimoNodo->data = (Nat) elem;
        ultimoNodo->ant = aux;
        ultimoNodo->sig = NULL;
        aux->sig = nuevoNodo;


    } else { // Aca entra si es el primer nodo que agregas
        nuevoNodo->ant = NULL;
        nuevoNodo->sig = NULL;
        primerNodo = nuevoNodo;
        primerNodo->ant = NULL;
        primerNodo->data = (Nat) elem;
        primerNodo->sig = NULL;
        ultimoNodo = nuevoNodo;
        ultimoNodo->ant = NULL;
        ultimoNodo->data = (Nat) elem;
        ultimoNodo->sig = NULL;
    }
    longitudLista++;
}

void Lista::eliminar(Nat i) {
    int j = 0;
    Nodo *iterador = primerNodo;
    while (i != j) {
        iterador = iterador->sig;
        j++;
    }
    //Caso Primero
    if (iterador->ant == NULL) {
        if (iterador->sig == NULL) {
            delete iterador;
            primerNodo = NULL;
        } else {
            primerNodo = iterador->sig;
            (iterador->sig)->ant = NULL;
            delete iterador;
        }

    }
        //Caso ultimo
    else if (iterador->sig == NULL) {
        (iterador->ant)->sig = NULL;
        delete iterador;

    }
        //Caso medio
    else {
        Nodo *aux1 = iterador->sig;
        Nodo *aux2 = iterador->ant;
        (iterador->ant)->sig = aux1;
        (iterador->sig)->ant = aux2;
        delete iterador;

    }
    longitudLista--;
}

int Lista::longitud() const {
    int i = 0;
    Nodo *iterador = primerNodo;
    while (iterador) {
        iterador = iterador->sig;
        i++;
    }
    return i;
}

const int &Lista::iesimo(Nat i) const {
    // Precodincion de que i este en rango
    Nodo *actual = primerNodo;
    while (i != 0) {
        actual = actual->sig;
        i--;
    }
    return (actual->data);
}

int &Lista::iesimo(Nat i) {
    // Precodincion de que i este en rango
    Nodo *actual = primerNodo;
    while (i != 0) {
        actual = actual->sig;
        i--;
    }
    return reinterpret_cast<int &>(actual->data);
}


void Lista::mostrar(ostream &o) {
    // Completar
}


