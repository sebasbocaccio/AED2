#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include "Proxy.h"
#include <string>
#include <vector>

#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:
    SistemaDeMensajes();
    // Pre: 0 <= id < 4
    void registrarJugador(int id, string ip){
        if(_conns[id] != NULL){
            desregistrarJugador(id);
            _conns[id] = new ConexionJugador(ip);
        }
        else{_conns[id] = new ConexionJugador(ip);}
    }
    Proxy* obtenerProxy(int id);
    // Pre: 0 <= id < 4
    bool registrado(int id) const{
        return _conns[id] ;
    }

    void desregistrarJugador(int id);
    ~SistemaDeMensajes(){

        // delete[] _conns; NO FUNCIONA

        // FUNCIONA
        for(int i = 0; i< 4; i++){
            delete _conns[i];
        }
        for(Proxy*  elemento : proxies){
            delete elemento;
        }


    }
    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje){
        _conns[id]->enviarMensaje(mensaje);
    }
    // Pre: registrado(id)
    string ipJugador(int id) const{
        return _conns[id]->ip();
    }

  private:
    vector<Proxy*> proxies;
    //Proxy* proxies[4];
    ConexionJugador* _conns[4];
};

#endif
