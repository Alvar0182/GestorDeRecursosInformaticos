#ifndef RESERVA_H
#define RESERVA_H
#include <ctime>
#include <list>
#include <string>
using namespace std;

class Reserva{
    private:
    string id_reser;
    string creador_reserva;
    time_t tiempo;
    int nuc_reser;
    string maq_reser;

    public:

    Reserva(string id,string creador,time_t tiempo_,int nuc,string maq);

    string getId_reser(){return id_reser;}
    void setId_reser(string id){id_reser=id;}

    string getCreador_reserva(){return creador_reserva;}
    void setCreador_reserva(string creador){creador_reserva=creador;}

    time_t getTiempo(){return tiempo;}
    void setTiempo(time_t time){tiempo=time;}

    int getNuc_reser(){return nuc_reser;}
    void setNuc_reser(int nuc){nuc_reser=nuc;}
    
    string getMaq_reser(){return maq_reser;}
    void setMaq_reser(string maq){maq_reser=maq;}
};
#endif
