#include "SistemaDeMensajes.h"
#include "Proxy.h"

// Completar...
SistemaDeMensajes::SistemaDeMensajes(){
    for(int i =0; i < 4 ;i++){
        _conns[i] = NULL;
    }
}

void SistemaDeMensajes::desregistrarJugador(int id ){
    delete _conns[id];
    _conns[id] = NULL;
}

Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* proxy = new Proxy(&_conns[id]);
    proxies.push_back(proxy);
   // proxies[id] =proxy;
    return proxy;
}