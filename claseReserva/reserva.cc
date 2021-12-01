//reserva.cc

#include "reserva.h"

using namespace std;

Reserva::Reserva(string id, string creador, struct date fIni, struct date fFin, int nucl, string maq){
	id_reser=id;
	creador_reser=creador;
	fechaInicio=fIni;
	fechaFin=fFin; //probablemente hay que poner cada parte del struct
	duracion= fIni-fFin;
	cant_nuc=nucl;
	maq_reser=maq;
}

void setFechas(struct date fIni, struct date fFin){
	fechaInicio=fIni;
	fechaFin=fFin;		//problamente hay que pone cada parte del struct
	duracion= fIni-fFin;
}