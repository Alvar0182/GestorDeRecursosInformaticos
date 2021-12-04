#include "reserva.h"

Reserva::Reserva(int id,int creador,time_t tiempo_,int nuc,int maq){
    id_reser=id;
    creador_reserva=creador;
    tiempo=tiempo_;
    nuc_reser=nuc;
    maq_reser=maq;
}