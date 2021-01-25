
#include "hash_table.h"
//
// Created by sebasbocaccio on 25/1/21.
//
template <class T>
Hash_table<T>:: Hash_table(int size, int (*foo)(T)):_BUCKET(size) ,hash(foo){
    _table = vector<vector<T>>(_BUCKET);
    _elements = 0;
}

template <class T>
void Hash_table<T>::add(T value){
    _table[hash(value)].push_back(value);
    _elements++;
}

template <class T>
bool Hash_table<T>::inside(T value){
    for ( auto &elem : _table[hash(value)]){
        if (elem == value){return true;}
    }
    return false;
}

template <class T>
bool Hash_table<T>::erase(T value){
     for (unsigned i=0; i<_table[hash(value)].size(); ++i){
        if (_table[hash(value)][i] == value){
            _table[hash(value)].erase(_table[hash(value)].begin() + i);
            _elements--;
            return true;
        }
    return false;

    }
}
template <class T>
int Hash_table<T>::cantElems(){
    return _elements;
}