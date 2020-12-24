#include <iostream>

using namespace std;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int m, int d);

    int mes(); // Completar declaraciones funciones
    int dia();
    void incrementar_dia();
    bool operator==(Fecha o) {
        return (this->mes() == o.mes() && this->dia() == o.dia());
    }
    bool operator<(Fecha o) {
        return (this->mes() < o.mes() || this->mes() == o.mes()  && this->dia() < o.dia());
    }
  private:
    int mes_ ;
    int dia_;
};
Fecha::Fecha(int m, int d): dia_(d), mes_(m){};
int Fecha::mes(){return mes_;}
int Fecha::dia(){return dia_;}
void Fecha::incrementar_dia(){
    if(dia() < dias_en_mes(mes())){dia_++;}
    else{
        dia_ = 1;
        mes_++;
    }

}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

// Ejercicio 11, 12

class Horario{
    public:
    Horario(int h, int min);

    uint hora();
        uint min();
        bool operator==(Horario h){
            return(this->hora() == h.hora() && this->min() == h.hora());
        }
        bool operator<(Horario h){
        return(this->hora() < h.hora() || this->hora() == h.hora()  && this->min() < h.min());
    }
    private:
        uint hora_;
        uint min_;
};

ostream& operator<<(ostream& os, Horario h) {
    os <<h.hora() << ":" << h.min();
    return os;
}
Horario::Horario(int h,int min): hora_(h), min_(min){};
uint Horario::hora(){return hora_;}
uint Horario::min(){return min_;}

// Ejercicio 13
using mensaje = string;
class Recordatorio {
    public:
        Recordatorio(Fecha f, Horario h , mensaje m );
        Fecha fecha();
        Horario horario();
        mensaje Darmensaje();
    private:
        Fecha fecha_;
        Horario horario_;
        ::mensaje mensaje_;
        vector<Recordatorio> ordenar_por_fecha(vector<Recordatorio> vec);

};
Fecha Recordatorio::fecha(){return this->fecha_;}
Horario Recordatorio::horario(){return horario_;}
mensaje Recordatorio::Darmensaje(){return mensaje_;}
   ostream &operator<<(ostream &os, Recordatorio r){
       os <<r.Darmensaje() << ' ' << "@" <<' ' <<r.fecha() << ' '<<r.horario();
       return os;
   };
Recordatorio::Recordatorio(Fecha f, Horario h, ::mensaje m): fecha_(f),horario_(h),mensaje_(m){};
// Ejercicio 14

// Clase Agenda

// INTERPRETACIONES SOBRE EL EJERCICIO:
//No sabia si la agenda debia seguir guardando los eventos pasados, como no aclara supongo que si.


class Agenda{
    public:
    Agenda(Fecha f);
    void agregar_recordatorio(Recordatorio rec);
        void incrementar_dia();
        vector<Recordatorio> recordatorios_de_hoy();
        Fecha hoy();
    private:
        Fecha fecha_;
        vector<Recordatorio> todosLosRecordatorios_;
        vector<Recordatorio> ordenar_por_fecha(vector<Recordatorio>);
};
// Constructor
Agenda::Agenda(Fecha f ): fecha_(f) {};
//Operaradores
ostream &operator<<(ostream &os, Agenda a){
    os<< a.hoy() << "\n"<< "=====" << "\n" ;
    for(int i =0; i < a.recordatorios_de_hoy().size(); i++){
        os<<a.recordatorios_de_hoy()[i] << "\n";
    }
    return os;
};

//Funciones Publicas
void Agenda::agregar_recordatorio(Recordatorio rec) {todosLosRecordatorios_.push_back(rec);}
void Agenda::incrementar_dia() {
    fecha_.incrementar_dia();
    // Actualizo compromisos
}
Fecha Agenda::hoy() {return this->fecha_;}

vector<Recordatorio> Agenda::recordatorios_de_hoy(){ //Devuelve los recordatorios del dia en orden que van a suceder.
    vector<Recordatorio> ret;
    for(Recordatorio rec : this->todosLosRecordatorios_ ){
        if(rec.fecha() == hoy()){
            ret.push_back(rec);
        }
    }
    if(ret.size() > 1){ret = ordenar_por_fecha(ret);}
    return ret;
}

vector<Recordatorio> Agenda::ordenar_por_fecha(vector<Recordatorio> vec) {
    bool permute = true;
    Recordatorio temporal(Fecha(1, 1), Horario(1, 1), "Im_A_Useless_Recordatorio"); //  No estoy pudiendo Definir sin inicializar.
    if(vec.size() < 2){return vec;}// Pongo el caso  base de que tenga 0 o 1 recordatorio, entonces ya esta ordenado

    //----------
    //Caso con mas de 2 elementos

    while (permute == true) {
        permute = false;
        for (int i = 0; i < vec.size() - 1; i++) {
            if (vec[i + 1].horario() < vec[i].horario()) {
                temporal = vec[i + 1];
                vec[i + 1] = vec[i];
                vec[i] = temporal;
                permute = true;
            }
        }
    }
    return vec;


}
