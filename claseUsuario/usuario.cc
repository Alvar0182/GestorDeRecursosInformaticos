#include "usuario.h"
#include "reserva.h"
#include <iostream>
#include <list>

void::Usuario crearReserva(std::string correoElectronico, int numNucleos, time_t tiempo){
	Reserva r;
	r.setCorreoElectronico(correoElectronico);
	r.setnumNucleos(numNucleos);
	r.setTiempo(tiempo);
	reservas_.push_back(r);
}

void::Usuario modificarReserva(std::string id_reser,std::string correoElectronico, int numNucleos, time_t tiempo){
	std::list<Reserva>::iterator r;
	r=reservas_.begin();
	for(int i=0;reservas_.size()>i;i++){
		if(id_reser=(*r).getIdReser()){
			std::cout<<"Introduzca los nuevos datos de la reserva"<<std::endl;
			std::string correo;
			int nucleos;
			time_t time;
			std::cout<<"Introduzca su correo electronico: ";
			std::cin>>correo;
			std::cout<<std::endl;
			std::cout<<"Introduzca el numero de nucleos que desea reservar: ";
			std::cin>>nucleos;
			std::cout<<std::endl;
			std::cout<<"Introduzca el tiempo que desea reservar: ";
			std::cin>>time;
			std::cout<<std::endl;

			Reserva res;
			res.setIdReser(id_reser);
			res.setCorreoElectronico(correo);
			res.setnumNucleos(nucleos);
			res.setTiempo(time);
			reservas_.push_back(res)
		}
		j++;
	}
}

void::Usuario cancelarReserva(std::string id_reser){
	std::list<Reserva>::iterator r;
	r=reservas_begin();
	for(int i=0;reservas_.size()>i;i++){
		if(id_reser=(*r).getIdReser()){
			std::string correo="";
			int nucleos=0;
			time_t tiempo=0;
			Reserva res;
			res.setCorreoElectronico(correo);
			res.setnumNucleos(nucleos);
			res.setTiempo(tiempo);
		}
		r++;
	}
}