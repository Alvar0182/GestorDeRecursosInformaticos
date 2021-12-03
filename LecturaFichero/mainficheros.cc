#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include "maquina.h"
#include "reserva.h"
#include "usuario.h"
using namespace std;

void leeUsuarios(){
	usuarios.clear();
	ifstream fichero("usuarios.txt");
	string aux;
	Usuario temp;
	while(getline(fichero,aux,',')){
		temp.idUsu=aux;
		getline(fichero,aux,',');
		temp.correo=aux;
		getline(fichero,aux,',');
		temp.lim_tiempo=stoi(aux); //en int (cantidad de dias) o en time_t/struct de fecha
		getline(fichero,aux,',');
		temp.lim_nucleo=stoi(aux);
		getline(fichero,aux,',');
		temp.tiempoDisp=stoi(aux);//en int (cantidad de dias) o en time_t/struct de fecha
		getline(fichero,aux,'\n');
		temp.nucleoDisp=stoi(aux);
		usuarios.push_back(temp);
	}
	fichero.close();
}

void leeMaquinas(){
	maquinas.clear();
	ifstream fichero("maquinas.txt");
	string aux;
	Maquina temp;
	while(getline(fichero,aux,',')){
		temp.id_maq=aux;
		getline(fichero,aux,',');
		temp.estado=stoi(aux);
		getline(fichero,aux,',');
		temp.nuc_tot=stoi(aux);
		getline(fichero,aux,'\n');
		temp.nuc_disp=stoi(aux);
		maquinas.push_back(temp);
	}
	fichero.close();
}

void leeReservas(){
	reservas.clear();
	ifstream fichero("reservas.txt");
	string aux;
	Reserva temp;
	while(getline(fichero,aux,',')){
		temp.id_reser=aux;
		getline(fichero,aux,',');
		temp.creador_reser=aux;
		getline(fichero,aux,',');
		temp.duracion=stoi(aux); //en int (cantidad de dias) o en time_t/struct de fecha
		getline(fichero,aux,',');
		temp.fechaInicio=stoi(aux); //en int (cantidad de dias) o en time_t/struct de fecha
		getline(fichero,aux,',');
		temp.fechaFin=stoi(aux); //en int (cantidad de dias) o en time_t/struct de fecha
		getline(fichero,aux,',');
		temp.cant_nuc=stoi(aux);
		getline(fichero,aux,'\n');
		temp.maq_reser=aux;

		reservas.push_back(temp);
	}
	fichero.close();
}

void escribeUsuarios(){
	ofstream fichero("usuarios.txt");
	list<Usuario>::iterator i;
	for( i=usuarios.begin();i!=usuarios.end();i++){
		fichero<<i->idUsu<<","<<
		i->correo<<","<<
		i->lim_tiempo<<","<<
		i->lim_nucleo<<","<<
		i->tiempoDisp<<","<<
		i->nucleoDisp<<endl;
	}
	fichero.close();
}

void escribreReservas(){
	ofstream fichero("reservas.txt");
	list<Reserva>::iterator i;
	for( i=reservas.begin();i!=reservas.end();i++){
		fichero<<i->id_reser<<","<<
		i->creador_reser<<","<<
		i->duracion<<","<<
		i->fechaInicio<<","<<
		i->fechaFin<<","<<
		i->cant_nuc<<","<<
		i->maq_reser<<endl;
	}
	fichero.close();
}

void escribeMaquinas(){
	ofstream fichero("maquinas.txt");
	list<Maquina>::iterator i;
	for( i=maquinas.begin();i!=maquinas.end();i++){
		fichero<<i->id_maq<<","<<
		i->estado<<","<<
		i->nuc_tot<<","<<
		i->nuc_disp<<","<<endl;
	}
	fichero.close();
}


int main(){
	//lectura de ficheros
	list<Maquina> maquinas;
	list<Usuario> usuarios;
	list<Reserva> reserva;
	leeUsuarios();
	leeReservas();
	leeMaquinas();





	//escritura de ficheros
	escribeUsuarios();
	escribeReservas();
	escribeMaquinas();
}