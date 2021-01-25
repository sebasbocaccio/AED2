//
// Created by sebasbocaccio on 25/1/21.
//
#include "vector"

#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H
using namespace std;


template <class T>
class Hash_table {

    public:
    // Generate a hash table. Requires the size of the table and a pointer to the hash function.
    Hash_table(int size, int (*foo)(T));

    // Add value to the dictionary. Doesn't check if the element was already inside.
    void add(T value);

    // Check if the value is in the hashtable. Returns the result.
    bool inside(T value);

    // Erase if the vale is in the hashtable. Returns the element was deleted successfully.
    bool erase(T value);

    // Return how many elements are in the hashtable.
    int cantElems();

    private:
        int _elements;
        int (*hash)(T);
        int _BUCKET;
        vector<vector<T>> _table;
};



#endif //HASH_TABLE_HASH_TABLE_H
