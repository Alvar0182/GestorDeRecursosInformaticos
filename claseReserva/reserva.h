//reserva.h

#ifndef RESERVA_H
#define RESERVA_H

struct date{
   int day;  
   int month; 
   int year;  
}

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Reserva{
	private:
		string id_reser;
		string creador_reser;
		struct date duracion;  //duracion en dd/mm/aaaa
		struct date fechaInicio;
		struct date fechaFin;
		int cant_nuc;
		string maq_reser;

	public:

		Reserva(string id, string creador, struct date fIni, struct date fFin, int nucl, string maq);

		inline string getIdReser(){return id_reser;}

		inline string getCreador(){return creador_reser;}

		inline struct date getDuracion(){return duracion;}

		inline struct date getFechaInicio(){return fechaInicio;}

		inline struct date getFechaFin(){return fechaFin;}

		inline int getCantNuc(){return cant_nuc;}

		inline string getMaquina(){return maq_reser;}

		void setFechas();


};

#endif