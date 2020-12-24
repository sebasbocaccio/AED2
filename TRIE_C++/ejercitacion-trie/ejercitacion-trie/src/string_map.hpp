template <typename T>
string_map<T>::string_map() : _size(0) {
    this->raiz = new Nodo();
}

template <typename T>
string_map<T>::string_map(const string_map<T>& aCopiar) : string_map() { *this = aCopiar; } // Provisto por la catedra: utiliza el operador asignacion para realizar la copia.

template <typename T>
string_map<T>& string_map<T>::operator=(const string_map<T>& d) {
    eraseall(this->raiz); // Vuelo_todo a la mierda y empiezo de 0
    this->raiz = new Nodo(); // Le cree una raiz pobresito no tenia
    for (int i = 0; i < 256 ;++i) {
        if(d.raiz->siguientes[i] != nullptr){
            Nodo* nuevoNodo = new Nodo();
            this->raiz->siguientes[i] = nuevoNodo;
            addall(this->raiz->siguientes[i],d.raiz->siguientes[i]);
        }
    }
    if(d.raiz->definicion != NULL){raiz->definicion =d.raiz->definicion; }
}
template <typename T>
void string_map<T>::addall(Nodo* dondeCopio ,Nodo* Acopiar){
    for(int i = 0;i < 256; i++){
        if (Acopiar->siguientes[i] != nullptr){
            dondeCopio->definidos++;
            Nodo* nuevoNodo = new Nodo();
            dondeCopio->siguientes[i] = nuevoNodo;
            addall(dondeCopio->siguientes[i],Acopiar->siguientes[i]);
        }
    }
    if(Acopiar->definicion != nullptr){
        T* def = new T;
        *def = *Acopiar->definicion;
        dondeCopio->definicion = def;
        this->_size++;
    }
}


template <typename T>
void string_map<T>::eraseall(Nodo* nodo){ // Me borra todos los nodos  siguientes pasado por parametro y el pasado por parametro tambien.
    for (int i = 0; i < 256 ; ++i) {
        if(nodo->siguientes[i] != nullptr){eraseall(nodo->siguientes[i]);}
    }
    if(nodo->definicion != NULL){delete nodo->definicion;}
    delete nodo;
}
template <typename T>
string_map<T>::~string_map(){
    eraseall(this->raiz);
}
template <typename T>
void string_map<T>::insert(const pair<string , T>& elemento ){
    Nodo* recorredor = this->raiz; // Nodo que voy a usar para recorrer hasta llegar a donde quiero.
    T* def = new T;
    for(int i =0; i< elemento.first.size();i++){
        int ascii = elemento.first[i]; // Guardo el codigo ascii del elemento i del string.
        if(recorredor->siguientes[ascii] == nullptr){ // Si no estaba definido,era porque  no habia ningun nodo. Debo crearlo.
            Nodo* nuevoNodo = new Nodo();
            recorredor->siguientes[ascii] = nuevoNodo;
            recorredor->definidos++;
        }
        recorredor = recorredor->siguientes[ascii];
    }
    //Defini_todo el camino por mi string

    //Pongo el significado a mi elemento

    *def= elemento.second;
    if(recorredor->definicion != NULL){delete recorredor->definicion;}
    recorredor->definicion=def;
    this->_size++;

    return; // COMPLETAR
}

template <typename T>
T& string_map<T>::operator[](const string& clave){
    Nodo* recorredor = this->raiz; // Nodo que voy a usar para recorrer hasta llegar a donde quiero.
    for(int i =0; i< clave.size();i++){
        int ascii = clave[i]; // Guardo el codigo ascii del elemento i del string.
        if(recorredor->siguientes[ascii] == nullptr){ // Si no estaba definido,era porque  no habia ningun nodo. Debo crearlo.
            Nodo* nuevoNodo = new Nodo();
            recorredor->siguientes[ascii] = nuevoNodo;
            recorredor->definidos++;
        }
        recorredor = recorredor->siguientes[ascii];
    }
    T* valor = new  T;
    // Si llegue aca, cada elemento estaba definido.
    if(recorredor->definicion == NULL){recorredor->definicion = valor;}
    else delete(valor);
    return *recorredor->definicion;
}



template <typename T>
int string_map<T>::count(const string& clave) const{
    Nodo* recorredor = this->raiz; // Nodo que voy a usar para recorrer hasta llegar a donde quiero.
    for(int i =0; i< clave.size();i++){
        int ascii = clave[i]; // Guardo el codigo ascii del elemento i del string.
        if(recorredor->siguientes[ascii] == nullptr){return false;} // No estaba definido el caracter clave[i]
        recorredor = recorredor->siguientes[ascii]; // Avanzo en el trie;
    }
    // Si llegue aca, cada elemento estaba definido.
    if(recorredor->definicion == NULL){return false;}
    else{return true;}

}

template <typename T>
const T& string_map<T>::at(const string& clave) const {
    Nodo* recorredor = this->raiz; // Nodo que voy a usar para recorrer hasta llegar a donde quiero.
    for(int i =0; i< clave.size();i++){
        int ascii = clave[i]; // Guardo el codigo ascii del elemento i del string.
        recorredor = recorredor->siguientes[ascii]; // Avanzo en el trie;
    }
    //Estoy parado en mi nodo
    return *(recorredor->definicion);
}

template <typename T>
T& string_map<T>::at(const string& clave) {
    Nodo* recorredor = this->raiz; // Nodo que voy a usar para recorrer hasta llegar a donde quiero.
    for(int i =0; i< clave.size();i++){
        int ascii = clave[i]; // Guardo el codigo ascii del elemento i del string.
        recorredor = recorredor->siguientes[ascii]; // Avanzo en el trie;
    }
    //Estoy parado en mi nodo

    return (*(recorredor->definicion));
}

template <typename T>
void string_map<T>::erase(const string& clave) {
    Nodo *recorredor = this->raiz; // Nodo que voy a usar para recorrer hasta llegar a donde quiero.
    Nodo *ultimoNodo = NULL;
    int ultimoindice;
    int ultimoascii;
    for (int i = 0; i < clave.size(); i++) {
        int ascii = clave[i]; // Guardo el codigo ascii del elemento i del string.
        if ((recorredor->definicion != NULL || recorredor->definidos > 1)) { // Nodo a partir del cual tengo que borrar
            ultimoNodo = recorredor;
            ultimoindice = i;
            ultimoascii = ascii;
        }
        recorredor = recorredor->siguientes[ascii]; // Avanzo en el trie;
    }//Llegue a mi clave
    delete recorredor->definicion;
    recorredor->definicion = NULL;
    if (recorredor->definidos !=0) { //  Si tenia hijos, no puedo borrarlo porque estaria borrando la conexion hacia ellos
        this->_size--;
        return; }
    else {// No tenia hijos, tengo que borrar desde ultimo nodo hasta mi nodo
        if (ultimoNodo != NULL) {
            ultimoNodo->definidos--; // Bajo en 1 la cantidad de hijos que tiene ultimo nodo
            recorredor = ultimoNodo->siguientes[ultimoascii]; // Me guardo a partir de donde tengo que borrar.
            ultimoNodo->siguientes[ultimoascii] = nullptr;    // Ya no esta definido, pues lo voy a borrar
            for (int i = ultimoindice + 1; i < clave.size(); i++) {
                int ascii = clave[i]; // Guardo el codigo ascii del elemento i del string.
                Nodo *temporal = recorredor->siguientes[ascii];
                delete recorredor;
                recorredor = temporal;
            }
        } else {
            recorredor = this->raiz; // Si entre aca es porque debo borrar todos los nodos hasta la clave

            for (int i = 0; i < clave.size(); i++) {
                int ascii = clave[i]; // Guardo el codigo ascii del elemento i del string.
                if( recorredor == raiz){
                    Nodo* temporal = recorredor->siguientes[ascii];
                    recorredor->siguientes[ascii] = nullptr;
                    recorredor = temporal;
                }
                else{
                    Nodo *temporal = recorredor->siguientes[ascii];
                    delete recorredor;
                    recorredor = temporal;
                }

            }
        }
    }
    if(clave.size() != 0) {delete recorredor;} // Si el elemento a eliminar no es ' ' , borro el nodo
    this->_size--;
    return;
}

template <typename T>
int string_map<T>::size() const{
    return this->_size;
}

template <typename T>
bool string_map<T>::empty() const{
    return (this->_size == 0 );
}