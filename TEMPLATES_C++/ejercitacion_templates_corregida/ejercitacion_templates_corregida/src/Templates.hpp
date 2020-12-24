#ifndef Templates

template<typename T>
T cuadrado(T x) {
    return x * x;
};

template<class Contenedor, class Elem>
bool contiene(Contenedor c, Elem e) {
    for (Elem i : c) {
        if (i == e) {
            return true;
        }
    }
    return false;
}

template<class Contenedor>
bool esPrefijo(Contenedor a, Contenedor b) {
    if (a.size() >= b.size()) { return false; }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) { return false; }
    }
    return true;
}


#endif
