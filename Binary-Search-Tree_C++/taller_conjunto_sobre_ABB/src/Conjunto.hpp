template<class T>
void Conjunto<T>::borradorNodo(Nodo *nodo) {
    if (nodo == NULL) { return; }
    if (elementos == 0){return;}
    borradorNodo(nodo->izq);
    borradorNodo(nodo->der);
    delete nodo;
}

template<class T>

Conjunto<T>::Conjunto():elementos(0), _raiz(NULL) {
}

template<class T>
Conjunto<T>::~Conjunto() {
    borradorNodo(_raiz);

}

template<class T>
bool Conjunto<T>::pertenece(const T &clave) const {
    Nodo *recorredor = _raiz;
    bool encontre = false;
    if(elementos == 0){return false;}
    while (recorredor != NULL && !encontre) {
        if (recorredor->valor == clave) { encontre = true; }
        else if (recorredor->valor > clave) { recorredor = recorredor->izq; }
        else recorredor = recorredor->der;
    }

    return encontre;
}

template<class T>
void Conjunto<T>::insertar(const T &clave) {
    Nodo *nuevoNodo = new Nodo(clave);
    //Caso Base
    if (elementos == 0) {
        _raiz = nuevoNodo;
        elementos++;
        return;
    }

    bool encontre = false;
    Nodo *recorredor = _raiz;
    while (!encontre) {
        if (recorredor->valor == clave) {
            delete nuevoNodo;
            return;
        }
        if (recorredor->valor < clave) { // Caso de derecha

            if (recorredor->der == NULL) { //Si no hay nodo
                recorredor->der = nuevoNodo;
                nuevoNodo->padre = recorredor;
                encontre = true;
            } else(recorredor = recorredor->der);
        } else if (recorredor->valor > clave) {//Caso Izquierda

            if (recorredor->izq == NULL) { //Si no hay nodo
                recorredor->izq = nuevoNodo;
                nuevoNodo->padre = recorredor;
                encontre = true;
            } else(recorredor = recorredor->izq);
        }

    }
    elementos++;
    return;


}

template<class T>
void Conjunto<T>::remover(const T &v) {
    Nodo *recorredor = _raiz;
    if (elementos == 0) { return; }
    // Caso base, que sea la raiz.
    if (elementos == 1) {
        if (_raiz->valor == v) {
            elementos--;
            delete _raiz;
            _raiz = NULL;
            return;
        } else { return; } // No estaba
    }

    //Ya que no es el arbol null o con 1 elemento. Debo buscarlo un poco mas exhatausivamente
    while (recorredor->valor != NULL && recorredor->valor != v) {
        if (recorredor->valor < v) {
            recorredor = recorredor->der;
        }
        if (recorredor->valor > v) {
            recorredor = recorredor->izq;
        }
    }
    //Aca llego sea el caso que no estaba o que lo encontre

    if (recorredor == NULL) { return; } // Nada mas que hacer

    //Caso es hoja :
    if (recorredor->izq == NULL && recorredor->der == NULL) {
        if (recorredor->padre->izq == recorredor) { recorredor->padre->izq = NULL; }
        else recorredor->padre->der = NULL;
        elementos--;
        delete recorredor;
        return;
    }

    //Caso tiene un hijo
    if (recorredor->izq != NULL && recorredor->der == NULL || recorredor->izq == NULL && recorredor->der != NULL) {

        if (recorredor->izq == NULL) { // Tenia un hijo derecho

            if (recorredor->padre != NULL && recorredor->padre->izq ==
                                             recorredor) { // Me fijo si el padre del nodo a borrar era el izquierdo o derecho
                recorredor->padre->izq = recorredor->der;
                recorredor->der->padre = recorredor->padre;
                delete recorredor;

            } else if (recorredor->padre != NULL) {
                recorredor->padre->der = recorredor->der;
                recorredor->der->padre = recorredor->padre;
                delete recorredor;

            } else { // Caso que estoy borrando la raiz.
                _raiz = recorredor->der;
                delete recorredor;
            }
            // Caso derecho
        } else {
            if (recorredor->padre != NULL && recorredor->padre->izq ==
                                             recorredor) { // Analogo al caso anterior pero sabiendo que el null era el derecho

                recorredor->padre->izq = recorredor->izq;
                recorredor->izq->padre = recorredor->padre;
                delete recorredor;
            } else if (recorredor->padre != NULL) {
                recorredor->padre->der = recorredor->izq;
                recorredor->izq->padre = recorredor->padre;
                delete recorredor;
            } else { //Caso que estoy borrando la raiz
                recorredor = recorredor->izq;
                _raiz = recorredor ->izq;
                delete recorredor;
            }
        }
        elementos--;
        return;
    }
    Nodo *sucesor_O_antecesor = recorredor;

    //Caso 2 hijos.
    T copiaValor;

    bool sucesorInmediato = false;
    if (recorredor->der != NULL) { // Busco el sucesor inmediato
        sucesor_O_antecesor = sucesor_O_antecesor->der;
        while (sucesor_O_antecesor->izq != NULL) {
            sucesor_O_antecesor = sucesor_O_antecesor->izq;
        }
        sucesorInmediato = true;
        recorredor->valor = sucesor_O_antecesor->valor; // Pongo el nuevo valor, falta eliminar el otro que se que es hoja o tiene hijo derecho

        if (sucesor_O_antecesor->der == NULL) { //Caso hoja
            if(sucesor_O_antecesor->padre->valor == sucesor_O_antecesor->valor ){
                sucesor_O_antecesor->padre->der = NULL;}
            else{sucesor_O_antecesor->padre->izq = NULL;}
            delete sucesor_O_antecesor;

        } else {
            if(sucesor_O_antecesor->padre->valor == sucesor_O_antecesor->valor ){
                sucesor_O_antecesor->padre->der = sucesor_O_antecesor->der;
                sucesor_O_antecesor->der->padre = sucesor_O_antecesor->padre;

            }
            else {
                sucesor_O_antecesor->padre->izq = sucesor_O_antecesor->der;
                sucesor_O_antecesor->der->padre = sucesor_O_antecesor->padre;
            }
            delete sucesor_O_antecesor;
        }

    } else if (!sucesorInmediato) {
        if (recorredor->izq != NULL) { // Busco el predecesor inmediato
            sucesor_O_antecesor = sucesor_O_antecesor->izq;
            while (sucesor_O_antecesor->der != NULL) {
                sucesor_O_antecesor = sucesor_O_antecesor->der;
            }
            recorredor->valor = sucesor_O_antecesor->valor; // Pongo el nuevo valor, falta eliminar el otro que se que es hoja o tiene hijo izquierdo

            if (sucesor_O_antecesor->der == NULL) { //Caso hoja
                if(sucesor_O_antecesor->padre->valor == sucesor_O_antecesor->valor ){sucesor_O_antecesor->padre->izq = NULL;}
                else{ sucesor_O_antecesor->padre->der = NULL;}
                delete sucesor_O_antecesor;

            } else {
                if(sucesor_O_antecesor->padre->valor == sucesor_O_antecesor->valor ){
                    sucesor_O_antecesor->padre->izq = sucesor_O_antecesor->izq;
                    sucesor_O_antecesor->izq->padre = sucesor_O_antecesor->padre;
                }
                else{
                    sucesor_O_antecesor->padre->der = sucesor_O_antecesor->izq;
                    sucesor_O_antecesor->izq->padre = sucesor_O_antecesor->padre;
                }

                delete sucesor_O_antecesor;
            }


        }
    }
    elementos--;
    return;
}
template<class T>
void Conjunto<T>::siguienteBusqueda(const T &clave,int cant,Nodo* nodoActual , T &valorSig ) {
    if(nodoActual == NULL){return;}
    if(valorSig < clave && nodoActual->valor > valorSig && nodoActual->valor != clave ){valorSig = nodoActual->valor;}
    if(nodoActual->valor > clave && nodoActual->valor < valorSig ){valorSig = nodoActual->valor;}
    siguienteBusqueda(clave,cant+1, nodoActual->der, valorSig);
    siguienteBusqueda(clave,cant+1, nodoActual->izq, valorSig);
    
}


template<class T>
const T &Conjunto<T>::siguiente(const T &clave) {
    Nodo* recorredor = _raiz;
    T valorActual = recorredor->valor;
    siguienteBusqueda(clave,0, recorredor, valorActual);

    Nodo* solucion = _raiz;

    // ACA HAY UNA CONSULTA QUE HACER!! 
    // Tengo problemas a la hora de retornar T valorActual me tira SegFault, lo que voy a hacer es buscar el nodo que tiene esa valor a ver si cambia en algo. Preguntar Porque
    while(solucion->valor != valorActual && solucion != NULL){
        if(solucion->valor < valorActual){solucion= solucion->der;}
        else(solucion = solucion->izq);
    }
    return solucion->valor;


}

template<class T>
const T &Conjunto<T>::minimo() const {
    Nodo *recorredor = _raiz;
    while (recorredor->izq != NULL) { recorredor = recorredor->izq; }
    return recorredor->valor;
}

template<class T>
const T &Conjunto<T>::maximo() const {
    Nodo *recorredor = _raiz;
    while (recorredor->der != NULL) { recorredor = recorredor->der; }
    return recorredor->valor;
}

template<class T>
unsigned int Conjunto<T>::cardinal() const {
    return elementos;
}

template<class T>
void Conjunto<T>::mostrar(std::ostream &) const {
    assert(false);
}

