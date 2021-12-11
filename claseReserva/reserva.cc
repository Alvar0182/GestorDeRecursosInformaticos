#include "reserva.h"

Reserva::Reserva(string id, string creador,time_t tiempo_,int nuc, string maq){
    id_reser=id;
    creador_reserva=creador;
    tiempo=tiempo_;
    nuc_reser=nuc;
    maq_reser=maq;
}
