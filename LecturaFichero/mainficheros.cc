#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <list>
#include <ctime>
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
		temp.lim_tiempo=aux; //entime_t de fecha
		getline(fichero,aux,',');
		temp.lim_nucleo=stoi(aux);
		getline(fichero,aux,',');
		temp.tiempoDisp=aux; //en time_t de fecha
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
		temp.duracion=aux; //en time_t de fecha
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
		fichero<<i->getIdUsu()<<","<<
		i->getCorreo()<<","<<
		i->getLim_tiempo()<<","<< // tiempo 
		i->getLim_nucleo()<<","<< 
		i->getTiempoDisp()<<","<<
		i->getNucleoDisp()<<endl;
	}
	fichero.close();
}

void escribeReservas(){
	ofstream fichero("reservas.txt");
	list<Reserva>::iterator i;
	for( i=reservas.begin();i!=reservas.end();i++){
		fichero<<i->getIdReser()<<","<<
		i->getCreador()<<","<<
		i->getDuracion()<<","<< //tiempo
		i->getCantNuc()<<","<<
		i->getMaquina()<<endl;
	}
	fichero.close();
}

void escribeMaquinas(){
	ofstream fichero("maquinas.txt");
	list<Maquina>::iterator i;
	for( i=maquinas.begin();i!=maquinas.end();i++){
		fichero<<i->getIdMaq()<<","<<
		i->getEstado()<<","<<
		i->getNucleoTotal()<<","<<
		i->getNucleosDisp()<<","<<endl;
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
