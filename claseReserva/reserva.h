#ifndef RESERVA_H
#define RESERVA_H
#include <list>
#include <string>
using namespace std;

class Reserva{
    private:
    string id_reser_;
    string creador_reserva_;
    int tiempo_;
    int nuc_reser_;
    string maq_reser_;

    public:

    Reserva(string id,string creador,int tiempo,int nuc,string maq);

    string getId_reser(){return id_reser_;}
    void setId_reser(string id){id_reser_=id;}

    string getCreador_reserva(){return creador_reserva_;}
    void setCreador_reserva(string creador){creador_reserva_=creador;}

    int getTiempo(){return tiempo_;}
    void setTiempo(int time){tiempo_=time;}

    int getNuc_reser(){return nuc_reser_;}
    void setNuc_reser(int nuc){nuc_reser_=nuc;}
    
    string getMaq_reser(){return maq_reser_;}
    void setMaq_reser(string maq){maq_reser_=maq;}
};
#endif
