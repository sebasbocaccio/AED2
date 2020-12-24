#include <vector>
#include "algobot.h"
#include <set>
#include <map>


using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set<int> elementos;
    vector<int> res;
    for (int i = 0; i < s.size(); i++) {
        if (elementos.count(s[i]) == 0) {
            elementos.insert(s[i]);
        }

    }
    for (int n : elementos) {
        res.push_back(n);
    }
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set<int> elementos;
    vector<int> res;
    for (int i = 0; i < s.size(); i++) {
        if (elementos.count(s[i]) == 0) {
            elementos.insert(s[i]);
        }

    }
    for (int n : elementos) {
        res.push_back(n);
    }
    return res;
}


// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    vector<int> resa = quitar_repetidos(a);
    vector<int> resb = quitar_repetidos(b);
    set<int> conjuntoa;
    set<int> conjuntob;
    for (int i = 0; i < resa.size(); i++) {
        if (conjuntoa.count(resa[i]) == 0) {
            conjuntoa.insert(resa[i]);
        }

    }
    for (int i = 0; i < resa.size(); i++) {
        if (conjuntob.count(resb[i]) == 0) {
            conjuntob.insert(resb[i]);
        }
    }
    for (int n : conjuntoa) {
        if (conjuntob.count(n) == 0) {
            return false;
        }
    }

    for (int n : conjuntob) {
        if (conjuntoa.count(n) == 0) {
            return false;
        }
    }
    return true;
}


// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
    vector<int> resa = quitar_repetidos(a);
    vector<int> resb = quitar_repetidos(b);
    set<int> conjuntoa;
    set<int> conjuntob;
    for (int i = 0; i < resa.size(); i++) {
        if (conjuntoa.count(resa[i]) == 0) {
            conjuntoa.insert(resa[i]);
        }

    }
    for (int i = 0; i < resa.size(); i++) {
        if (conjuntob.count(resb[i]) == 0) {
            conjuntob.insert(resb[i]);
        }
    }
    for (int n : conjuntoa) {
        if (conjuntob.count(n) == 0) {
            return false;
        }
    }

    for (int n : conjuntob) {
        if (conjuntoa.count(n) == 0) {
            return false;
        }
    }
    return true;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int, int> clavesRes;
    for (int n : s) {
        if (clavesRes.count(n) == 0) {
            clavesRes[n] = 1;
        } else {
            clavesRes[n]++;
        }

    }
    return clavesRes;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    map<int, int> DiccionarioConRepeticiones = contar_apariciones(s);
    vector<int> res;
    for (pair<int, int> p : DiccionarioConRepeticiones) {
        if (p.second == 1) {
            res.push_back(p.first);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> interseccion;
    for (int e : a) {
        if (b.count(e) == 1)
            interseccion.insert(e);
    }
    return interseccion;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for (int e : s) {
        if (res.count(e % 10) == 0) {
            res[e % 10].insert(e);

        } else res[e % 10].insert(e);

    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    vector<char> res;
    vector<char> respuesta;
    bool ElementoPuesto = false;
    for (char c : str) {
        ElementoPuesto = false;
        for (pair<char, char> p : tr) {
            if (p.first == c) {
                res.push_back(p.second);
                ElementoPuesto = true;
            }

        }
        if (not ElementoPuesto) { res.push_back(c); }
    }
    for (char c : res) {
        respuesta.push_back(c);
    }

    return respuesta;
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s) {
    map<string, vector<string>> alumnos;
    for (Mail l : s) {
        string libreta;
        int contador = 0;
        for (char c : l.asunto()) {
            contador++;
            if (c == ';') {
                alumnos[l.asunto()].push_back(libreta);
                libreta = "";
            } else {
                libreta.push_back(c);
                if (contador == l.asunto().size())(alumnos[l.asunto()].push_back(libreta));
            }
        }

    }
    for (pair<string, vector<string>> st : alumnos) {
        for (string libDelIndividio : st.second) {
            for (pair<string, vector<string>> st2 : alumnos) {
                for (string libDelIndividio2 : st2.second) {
                    if (st.first != st2.first && libDelIndividio == libDelIndividio2) {
                        return true;
                    }
                }

            }

        }

    }
    return false;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    return map<set<LU>, Mail>();
}
