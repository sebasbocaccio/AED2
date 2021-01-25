#include <iostream>
#include "string"
#include "hash_table.cpp"
class DNI{
    public:
        std::string _name;
        int _number;

    DNI(std::string  name, int number): _name(name), _number(number){}

    bool operator==(DNI value){
        return (_number == value._number);
    }
};
int function_hash(DNI dni){
    return  dni._number % 100 ;
}

int main() {
    int (*foo)(DNI);
    foo = &function_hash;
    DNI juan = DNI("juan", 20 );
    DNI pedro = DNI("pedro", 30);
    Hash_table<DNI> inscriptos(100, foo);
    inscriptos.add(juan);

    // Check for an element that is not in the hashtable
    if( inscriptos.inside(pedro)){
        cout << "Not Working fine  1/3" << endl;
    }
    else {
        cout << "Working fine  1/3" << endl;
    }
    // Erase an element.
    if( inscriptos.erase(juan)){
        cout << "Working fine  2/3" << endl;
    }
    else {
        cout << "Not Working fine 2/3" << endl;
    }
    // Check if an erased element is inside
    if( !inscriptos.inside(pedro)){
        cout << "Working fine  3/3" << endl;
    }
    else {
        cout << "Not working fine  3/3" << endl;
    }
}
