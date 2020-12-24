
template<class T>
ColaPrior<T>::ColaPrior(): tamano(0) {

}

template<class T>
int ColaPrior<T>::tam() const {
	return this->tamano;
}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
    this->tamano++;
    elementos.push_back(elem);
    siftUp(elementos,elementos.size()-1);

}
int hijoizq(int i){return 2*i +1;}
int hijoder(int i){return 2*i +2;}
int padre(int i){return  (i-1)/2;}
template<class T>
void swapi(vector<T> &elementos,int i,int j){
    T temporal = elementos[i];
    elementos[i] = elementos[j];
    elementos[j] = temporal;
}
template<class T>
void ColaPrior<T>::siftUp(vector<T> &elementos, int i){
    if(i != 0 && elementos[i] >  elementos[padre(i)]){
        T temporal = elementos[i];
        elementos[i] = elementos[padre(i)];
        elementos[padre(i)] = temporal;
        siftUp(elementos, padre(i));
    }
}
template<class T>
void ColaPrior<T>::siftDown(vector<T> &elementos, int i){
    if( hijoizq(i) <= elementos.size()-1 ){ //Si el numero de hijoizq es mayor a la cantidad de elementos. Entonces hijoizq(i) no esta definido => hijoder(i) tampoco.
        T maximo = elementos[hijoizq(i)];
        int indiceMaximo = hijoizq(i);
        if(hijoder(i) <= elementos.size()-1){
            if(maximo < elementos[hijoder(i)]){ // Si tenia hijo derecho, me quedo con el maximo entre ambos
                maximo = elementos[hijoder(i)];
                indiceMaximo = hijoder(i);
            }

        }
        if(maximo > elementos[i]){
            swapi(elementos, i, indiceMaximo );
            siftDown(elementos, indiceMaximo);
        }
    }

}
template<class T>
const T& ColaPrior<T>::proximo() const {
	return this->elementos[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
	elementos[0] = elementos[elementos.size()-1]; // Pongo el ultimo adelante
	elementos.pop_back(); // Popeo el ultimo..
	if(elementos.size() != 0){siftDown(elementos, 0);}
	tamano--;

}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
	for(int i = 0;i < elems.size(); i++){
	    elementos.push_back(elems[i]);
	}
	for(int i = elems.size()/2; i >= 0 ; i--){
	    siftDown(elementos, i);
	}
}

