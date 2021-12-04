#ifndef RESERVA_H
#define RESERVA_H
#include <ctime>
#include <list>

class Reserva{
    private:
    int id_reser;
    int creador_reserva;
    time_t tiempo;
    int nuc_reser;
    int maq_reser;

    public:

    Reserva(int id,int creador,time_t tiempo_,int nuc,int maq);

    int getId_reser(){return id_reser;}
    void setId_reser(int id){id_reser=id;}

    int getCreador_reserva(){return creador_reserva;}
    void setCreador_reserva(int creador){creador_reserva=creador;}

    time_t getTiempo(){return tiempo;}
    void setTiempo(time_t time){tiempo=time;}

    int getNuc_reser(){return nuc_reser;}
    void setNuc_reser(int nuc){nuc_reser=nuc;}
    
    int getMaq_reser(){return maq_reser;}
    void setMaq_reser(int maq){maq_reser=maq;}
};
#endif