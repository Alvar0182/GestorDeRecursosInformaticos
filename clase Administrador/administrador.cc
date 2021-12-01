/*
 * administrador.cc
 *
 *  Created on: 24 nov. 2021
 *      Author: asimancas
 */


#include "administrador.h"
#include "usuario.h"
#include "reserva.h"
#include <vector>
#include <list>
using namespace std;

Administrador::void verInfor(){
	int opcion;
	string cadena;
	cout<<"Introduzca si quiere buscar un usuario o una maquina. Introduzca 1 si quiere usuario y 2 si quiere máquina"<<endl;
	cin>>opcion;

	int idUser,idMaquina;
	if(opcion==1){
		cout<<"Introduzca el id del usuario"<<endl;
		cin>>idUser;
	}
	else if(opcion==2){
		cout<<"Introduzca el id de la maquina"<<endl;
		cin>>idMaquina;
	}

	for(int i=0;usuarios_.size()>i;i++){
		if(idUser=usuarios_[i].getIdUsu()){
			cout<<"El id del usuario es: "<<usuarios_[i].getIdUsu();
			cout<<"El correo del usuario es: "<<usuarios_[i].getCorreo();
		}
	}

	for(int i=0;maquinas_.size()>i;i++){
		if(idMaquina=maquinas_[i].getId_maq()){
			cout<<"El id de la maquina es: "<<maquinas_[i].getIdmaq()<<endl;
			cout<<"El estado de la maquina es: "<<maquinas_[i].getEstado()<<endl;
			cout<<"Nucleos totales de esta maquina: "<<maquinas_[i].getNuc_tot()<<endl;
			cout<<"Nucleos disponibles de esta maquina: "<<maquinas_[i].getNuc_disp()<<endl;
		}
	}


Administrador::void modificarReserva(){
	int idReserva;
	cout<<"Introduzca el ID de la reserva que desea modificar"<<endl;
	cin>>idReserva;
	vector <Reserva>
	}
}

Administrador::void borrarReserva(){

}
