#include "administrador.h"
#include "usuario.h"
#include "reserva.h"
#include <vector>
#include <list>
using namespace std;

Administrador::verInfor(){
	int opcion;
	string cadena;
	cout<<"Introduzca si quiere buscar un usuario o una maquina. Introduzca 1 si quiere usuario y 2 si quiere máquina"<<endl;
	cin>>opcion;

	string idUser,idMaquina;
	if(opcion==1){
		cout<<"Introduzca el id del usuario"<<endl;
		cin>>idUser;
	}
	else if(opcion==2){
		cout<<"Introduzca el id de la maquina"<<endl;
		cin>>idMaquina;
	}

	for(int i=0;usuarios.size()>i;i++){
		if(idUser=usuarios[i].getIdUsu()){
			cout<<"El id del usuario es: "<<usuarios[i].getIdUsu();
			cout<<"El correo del usuario es: "<<usuarios[i].getCorreo();
		}
	}

	for(int i=0;reservas.size()>i;i++){
		if(idMaquina=reservas[i].getId_maq()){
			cout<<"El id de la maquina es: "<<reservas[i].getIdmaq()<<endl;
			cout<<"El estado de la maquina es: "<<reservas[i].getEstado()<<endl;
			cout<<"Nucleos totales de esta maquina: "<<reservas[i].getNuc_tot()<<endl;
			cout<<"Nucleos disponibles de esta maquina: "<<reservas[i].getNuc_disp()<<endl;
		}
	}


void Administrador::modificarReserva(){
	int idReserva;
	cout<<"Introduzca el ID de la reserva que desea modificar"<<endl;
	cin>>idReserva;

	std::list<Reserva>::iterator r;
	r=reservas.begin();
	for(int i=0;reservas.size()>i;i++){
		if(idReserva=(*r).getIdReser()){
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
			res.setCorreoElectronico(correo);
			res.setnumNucleos(nucleos);
			res.setTiempo(time);
			reservas.push_back(res)
		}
		j++;
	}
}

void Administrador::borrarReserva(std::string idReserva){
	std::list<Reserva>::iterator r;
	r=reservas_begin();
	for(int i=0;reservas.size()>i;i++){
		if(id_reser=(*r).getIdReser()){
			reservas.erase(r);
		}
		r++;
	}
}