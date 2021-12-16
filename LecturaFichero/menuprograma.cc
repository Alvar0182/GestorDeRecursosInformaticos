//menu programa

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

void leeUsuarios(list<Usuario> &usuarios){
	usuarios.clear();
	ifstream fichero("usuarios.txt");
	string aux;
	Usuario temp("111", "correo", 1, 1, 1, 1);
	while(getline(fichero,aux,',')){
		temp.setIdUsu(aux);
		getline(fichero,aux,',');
		temp.setCorreo(aux);
		getline(fichero,aux,',');
		temp.setLim_tiempo(stoi(aux));
		getline(fichero,aux,',');
		temp.setLim_nucleo(stoi(aux));
		getline(fichero,aux,',');
		temp.setTiempoDisp(stoi(aux));
		getline(fichero,aux,'\n');
		temp.setNucleoDisp(stoi(aux));
		usuarios.push_back(temp);
	}
	fichero.close();
}

void leeMaquinas(list<Maquina> &maquinas){
	maquinas.clear();
	ifstream fichero("maquinas.txt");
	string aux;
	Maquina temp("111", 1);
	while(getline(fichero,aux,',')){
		temp.setId_Maq(aux);
		getline(fichero,aux,',');
		if(aux=="true")
			temp.setEstado(1);
		else
			temp.setEstado(0);
		getline(fichero,aux,',');
		temp.setNuc_Tot(stoi(aux));
		getline(fichero,aux,'\n');
		temp.setNuc_Disp(stoi(aux));
		maquinas.push_back(temp);
	}
	fichero.close();
}

void leeReservas(list<Reserva> &reservas){
	reservas.clear();
	ifstream fichero("reservas.txt");
	string aux;
	Reserva temp("111","aaa", 1, 1,"maq");
	while(getline(fichero,aux,',')){
		temp.setId_reser(aux);
		getline(fichero,aux,',');
		temp.setCreador_reserva(aux);
		getline(fichero,aux,',');
		temp.setTiempo(stoi(aux)); //tiempo en int
		getline(fichero,aux,',');
		temp.setNuc_reser(stoi(aux));
		getline(fichero,aux,'\n');
		temp.setMaq_reser(aux);

		reservas.push_back(temp);
	}
	fichero.close();
}

void escribeUsuarios(list<Usuario> &usuarios){
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

void escribeReservas(list<Reserva> &reservas){
	ofstream fichero("reservas.txt");
	list<Reserva>::iterator i;
	for( i=reservas.begin();i!=reservas.end();i++){
		fichero<<i->getId_reser()<<","<<
		i->getCreador_reserva()<<","<<
		i->getTiempo()<<","<< //tiempo
		i->getNuc_reser()<<","<<
		i->getMaq_reser()<<endl;
	}
	fichero.close();
}

void escribeMaquinas(list<Maquina> &maquinas){
	ofstream fichero("maquinas.txt");
	list<Maquina>::iterator i;
	for( i=maquinas.begin();i!=maquinas.end();i++){
		fichero<<i->getIdMaq()<<","<<
		i->getEstado()<<","<<
		i->getNucleoTotal()<<","<<
		i->getNuc_Disp()<<","<<endl;
	}
	fichero.close();
}

menu1(){
	cout<<"1.- Crear reserva"<<endl;
	cout<<"2.- Modificar reserva"<<endl;
	cout<<"3.- Eliminar reserva"<<endl;
	cout<<"4.- Salir del sistema"<<endl;
}

menu2(){
	cout<<"1.- Alta usuario"<<endl;
	cout<<"2.- Baja usuario"<<endl;
	cout<<"3.- Limitar tiempo de reserva"<<endl;
	cout<<"4.- Limitar nucleos de reserva"<<endl;
	cout<<"5.- Salir del sistema"<<endl;
}

menu3(){
	cout<<"1.- Alta maquina"<<endl;
	cout<<"2.- Baja maquina"<<endl;
	cout<<"3.- Modificar nucleos totales"<<endl;
	cout<<"4.- Cambiar nucleos disponibles"<<endl;
	cout<<"4.- Salir del sistema"<<endl;
}

void crearReserva(list<Reserva> &reservas, list<Usuario> &usuarios, list<Maquina> &maquinas){
	//pedir datos
		string id;
		string creador;
		int time;
		int nucleos;
		string maquina;

	  cout<<"Indica los datos de esta reserva"<<endl;
	  cout<<"Indica id de reserva"<<endl;
	  cin>>id;
	  cout<<"Indica tu id de usuario"<<endl;
	  cin>>creador;
	  cout<<"Indica el tiempo a reservar"<<endl;
	  cin>>time;
	  cout<<"Indica los nucleos a reservar"<<endl;
	  cin>>nucleos;
	  cout<<"Indica de que maquina reservar"<<endl;
	  cin>>maquina;

	//buscar si existe

	  int existe=0;		//Usaremos existe de forma que si alguna condicion no se cumple, lo ponemos a 0 y se salta el resto de comprobaciones y no se crea el objeto
	  list<Reserva>::iterator i;
		for(i=reservas.begin();i!=reservas.end();i++){
			if(id==i->getId_reser()){
        existe=1;}
		}

	//buscar si el usuario puede

		if(existe==1){
			//buscar al usuario
			//comparar tiempos/nucleos
			//restar si se puede

			list<Usuario>::iterator itu;
			for(itu=usuarios.begin();itu!=usuarios.end();itu++){
				
				if(creador==itu->getIdUsu()){

					if(time>itu->getTiempoDisp()){
						//El tiempo a reservar es mayor del que puede
						cout<<"No puedes reservar tanto tiempo"<<endl;
						existe=0;
					}else{
							//Si puede reservar esa cantidad de tiempo
							itu->setTiempoDisp( (itu->getTiempoDisp()-time) );
						}

					if(nucleos>itu->getNucleoDisp()){
						//Los nucleos a reservar son mas de lo que puede
						cout<<"No puedes reservar tantos nucleos"<<endl;
						existe=0;
					}else{
							//Si puede reservar la cantidad de nucleos
							itu->setNucleoDisp( (itu->getNucleoDisp()-nucleos) );
						}
				}


			}

			
		}
	//buscar si la maquina puede
		if(existe==1){
			//buscar la maquina
			//comparar nucleos
			//restar si se puede

			list<Maquina>::iterator itm;
			for(itm=maquinas.begin();itm!=maquinas.end();itm++){
				if(maquina==itm->getIdMaq()){
					if(nucleos>itm->getNuc_Disp()){
						//Se intenta reservas mas de lo que puede la maquina
						cout<<"Esta maquina no tienen tantos nucleos disponibles"<<endl;
						existe=0;
					}else{
						itm->setNuc_Disp( (itm->getNuc_Disp()-nucleos) );
					}
				}
			}
		}

	//hacer la reserva
		if(existe==1){
			//creamos objeto de Reserva
			//añadimos a la lista

			Reserva res(id, creador, time, nucleos, maquina);
			reservas.push_back(res);
		}
}

void modifReserva(list<Reserva> &reservas, list<Usuario> &usuarios, list<Maquina> &maquinas){
	strind id;
	int auxTiempo;
	int auxNucleo;
	string auxMaquina;

	cout<<"Indica la reserva a modificar";

	//identificar la maquina
	//pedir nuevas opciones
	  list<Reserva>::iterator i;
		for(i=reservas.begin();i!=reservas.end();i++){
			if(id==i->getId_reser()){

				cout<<"Indica la nueva cantidad de tiempo"<<endl;
				cin>>auxTiempo;
				cout<<"Indica la nueva cantidad de nucleos"<<endl;
				cin>>auxNucleo;
				cout<<"Indica la nueva maquina"<<endl;
				cin>>auxMaquina;

	//buscar usuario dueño
	//devolverle tiempo y nucleo
	//quitarle tiempo y nucleo
				list<Usuario>::iterator itu;
				for(itu=usuarios.begin();itu!=usuarios.end();itu++){
					if(i->getCreador_reserva()==itu->getIdUsu()){

					if(auxTiempo> (itu->getTiempoDisp()+ i->getTiempo() ) ){ cout<<"No puedes reservar tanto tiempo"; }
					else{ itu->setTiempoDisp( (itu->getTiempoDisp()+ i->getTiempo() - auxTiempo )  ); }

					if(auxNucleo> (itu->getNucleoDisp()+ i->getNuc_reser() ) ){ cout<<"No puedes reservar tanto tiempo"; }
					else{ itu->setNucleoDisp( (itu->getNucleoDisp()+ i->getNuc_reser() - auxNucleo )  ); }

				}
				else{cout<<"no se encontro el usuario"<<endl;};

				}


	//buscar maquina
	//devolver nucleo

				list<Maquina>::iterator itm;
			for(itm=maquinas.begin();itm!=maquinas.end();itm++;){
				if(i->getMaq_reser()==itm->getIdMaq()){
					itm->setNuc_Disp( itm->getNuc_Disp()+i->getNuc_reser() );
				}
				else{cout<<"no se encontro la maquina"<<endl;}
			}

	//buscar maquina
	//quitar nucleo
				list<Maquina>::iterator itm2;
			for(itm2=maquinas.begin();itm2!=maquinas.end();itm2++;){
				if(auxMaquina==itm2->getIdMaq()){
					itm2->setNuc_Disp( itm->getNuc_Disp()+auxNucleo );
				}}

        	}
        else{ cout<<"No se encontro la reserva"<<endl; }
		}

}

void elimReserva(list<Reserva> &reservas, list<Usuario> &usuarios, list<Maquina> &maquinas){
	string id;
	cout<<"indica id de la reserva a borrar"<<endl;
	cin>>id;
	//buscamos reserva
		  list<Reserva>::iterator i;
		for(i=reservas.begin();i!=reservas.end();i++){
			if(id==i->getId_reser()){
        //bucamos usuario
		//devolvemos nucleos y tiempo
				list<Usuario>::iterator itu;
			for(itu=usuarios.begin();itu!=usuarios.end();itu++){
				if(i->getCreador_reserva()==itu->getIdUsu()){
				itu->setTiempoDisp( itu->getTiempoDisp()+ i->getTiempo() );
				itu->setNucleoDisp( itu->getNucleoDisp()+ i->getNuc_reser());
				}

			}


		//buscamos maquina
		//devolvemos nucleos
				list<Maquina>::iterator itm;
			for(itm=maquinas.begin();itm!=maquinas.end();itm++;){
				if(i->getMaq_reser()==itm->getIdMaq()){
				itm->setNuc_Disp( itm->getNuc_Disp()+i->getNuc_reser() );
				}
			}
			reservas.erase(i);
        }

		}

}

void altaUsuario(list<Usuario> &usuarios){
	//pedir datos
	  string id;
	  string correo;
	  int tiempo; //con time_t o struct de tiempo
	  int nucleos;

	  cout<<"Indica los datos del nuevo usuario"<<endl;
	  cout<<"Indica nombre"<<endl;
	  cin>>id;
	  cout<<"Indica correo"<<endl;
	  cin>>correo;
	  cout<<"Indica el tiempo disponible"<<endl;
	  cin>>tiempo;
	  cout<<"Indica los nucleos disponibles"<<endl;
	  cin>>nucleos;

  //buscar si existe
	  int existe=0;
	  list<Usuario>::iterator i;
		for(i=usuarios.begin();i!=usuarios.end();i++){
			if(id==i->getIdUsu()){
        existe=1;}
		}
  //crear objeto
	  if(existe==1){
		  Usuario usu(id, correo, tiempo, tiempo, nucleos, nucleos);

  //añadir a la lista
	    usuarios.push_back(usu);
	  }
}

void bajaUsuario(list<Reserva> &reservas, list<Usuario> &usuarios, list<Maquina> &maquinas){
	//pido usuario
	string id;
	cout<<"Indica el usuario a eliminar"<<endl;
	cin>>id;
	//busco usuario
	list<Usuario>::iterator i;
		for(i=usuarios.begin();i!=usuarios.end();i++){
			if(id==i->getIdUsu()){

						//busco las reservas de las que es dueño

				list<Reserva>::iterator it;
				for(it=reservas.begin();it!=reservas.end();it++){
						if(i->getIdUsu()==it->getCreador_reserva()){
							
							//busco maquina
							list<Maquina>::iterator itm;
							for(itm=maquinas.begin();itm!=maquinas.end();itm++){
								if(it->getMaq_reser()==itm->getIdMaq()){
								//devuelvo nucleo a esa maquina
									itm->setNuc_Disp( itm->getNuc_Disp()+it->getNuc_reser() );								}
							}
							//elimino esa reserva
							reservas.erase(it);
						}

			}

		//elimino al usuario

				usuarios.erase(i);}
	
}}

void cambiarLimTiempo(list<Usuario> &usuarios){
	string id;
	int time;
	cout<<"Indica el usuario a limitar"<<endl;
	cin>>id;

	//buscamos al usuario
	list<Usuario>::iterator i;
		for(i=usuarios.begin();i!=usuarios.end();i++){
			if(id==i->getIdUsu()){

				//pedimos nuevo limite
				cout<<"Indica nuevo limite de tiempo"<<endl;
				cin>>time;
				//aplicamos limite
				i->setLim_tiempo(time);
			}}
}

void cambiarLimNucleo(list<Usuario> &usuarios){
	string id;
	int nucleo;
	cout<<"Indica el usuario a limitar"<<endl;
	cin>>id;

	//buscamos al usuario
	list<Usuario>::iterator i;
		for(i=usuarios.begin();i!=usuarios.end();i++){
			if(id==i->getIdUsu()){

				//pedimos nuevo limite
				cout<<"Indica nuevo limite de nucleo"<<endl;
				cin>>nucleo;
				//aplicamos limite
				i->setLim_tiempo(nucleo);
			}}
}

void altaMaq(list<Maquina> &maquinas){
	cout<<"Introduzca los datos de la maquina (id, estado, nucleos totales, nucleos disponibles)"<<std::endl;
    string id_maq;
	int nuc_tot;
    	cout<<"Introduzca el id de la maquina"<<std:endl;
    	cin>>id_maq;
    	cout<<"Introduzca los nucleos totales de la maquina"<<std:endl;
    	cin>>nuc_tot;

   			 list<Maquina>::iterator itm;
				for(itm=maquinas.begin();itm!=maquinas.end();itm++){
				if(it->getMaq_reser()==itm->getIdMaq()){
  					Maquina(id_maq,nuc_tot);
   					maquinas.push_back(Maquina);}
				}
}

void bajaMaq(list<Reserva> &reservas, list<Usuario> &usuarios, list<Maquina> &maquinas){
	//pido maquina
	string id;
	cout<<"Indica la maquina a eliminar"<<endl;
	cin>>id;
	//busco maquina
	list<Maquina>::iterator i;
		for(i=maquinas.begin();i!=maquinas.end();i++){
			if(id==i->getIdMaq()){

						//busco las reservas en las que esta

				list<Reserva>::iterator it;
				for(it=reservas.begin();it!=reservas.end();it++){
						if(i->getIdMaq()==it->getMaq_reser()){
							
							//busco maquina
							list<Usuario>::iterator itu;
							for(itu=usuarios.begin();itu!=usuarios.end();itu++){
								if(it->getMaq_reser()==itu->getIdMaq()){
								//devuelvo nucleo a esa maquina
									itu->setNucleoDisp( itu->getNucleoDisp()+it->getNuc_reser() );	
									itu->setTiempoDisp( itu->getTiempoDisp()+it->getTiempo() );								}
							}
							//elimino esa reserva
							reservas.erase(it);
						}

			}

		//elimino al usuario

				maquinas.erase(i);}
	
	}

}

void cambiarNucTotal(list<Maquina> &maquinas){
	//busco maquina
	//la identifico
	//le cambio los nuc totales
	int nuc;
	string id;
	cout<<"Indica maquina a cambiar nucleos totales"<<endl;

	list<Maquina>::iterator i;
	for( i=maquinas.begin();i!=maquinas.end();i++){
		if(id==i->getIdMaq()){
			cout<<"Indique nueva cantidad de nucleos totales"<<endl;
			cin>>nuc;
			i->setNuc_Tot(nuc); 
		}
	}


}

void cambiarNucDisp(list<Maquina> &maquinas){
	//busco maquina
	//la identifico
	//le cambio los nuc disponibles
	int nuc;
	string id;
	cout<<"Indica maquina a cambiar nucleos disponibles"<<endl;

	list<Maquina>::iterator i;
	for( i=maquinas.begin();i!=maquinas.end();i++){
		if(id==i->getIdMaq()){
			cout<<"Indique nueva cantidad de nucleos disponibles"<<endl;
			cin>>nuc;
			i->setNuc_Disp(nuc); 
		}
	}


}

int main(){
	//lectura de ficheros
	list<Maquina> maquinas;
	list<Usuario> usuarios;
	list<Reserva> reservas;
	leeUsuarios(usuarios);
	leeReservas(reservas);
	leeMaquinas(maquinas);

	string id;
	cout<<"Bienvenido al sistema de reserva de maquinas. Por favor, introduzca su ID para iniciar sesion"<<endl;
	cout<<"(usuario --> usuario, adminU --> Administrador1, adminM --> Administrador2)"<<endl;
	cin>>id;

	if(id == "usuario"){
		menu1();
		int opcion;
		while(opcion != 4){
			cin>>opcion;
			switch(opcion){
				menu1();
				case 1: //crear reserva
				{
					cout<<"Opcion 1"<<endl;
					crearReserva(reservas, usuarios, maquinas);
				}
				break;
				case 2: //modificiar reserva
				{
					cout<<"Opcion 2"<<endl;
					modifReserva(reservas, usuarios, maquinas);
				}
				break;
				case 3: //eliminar reserva
				{
					cout<<"Opcion 3"<<endl;
					elimReserva(reservas, usuarios, maquinas )
				}
				break;
				case 4:
				{
					cout<<"Saliendo del programa..."<<endl;
				}
				break;

				default: cout<<"Se ha ingresado una opcion incorrecta"<<endl;
				break;
			}
		}
	}
	if(id == "adminU"){
		menu2();
		int opcion;
		while(opcion != 5){
			cin>>opcion;
			switch(opcion){
				menu2();
				case 1: //alta
				{
					cout<<"Opcion 1"<<endl;
					altaUsuario(usuarios);
				}
				break;
				case 2: //baja
				{
					cout<<"Opcion 2"<<endl;
					bajaUsuario(reservas, usuarios, maquinas);
				}
				break;
				case 3: //limitar tiempo
				{
					cout<<"Opcion 3"<<endl;
					cambiarLimTiempo(usuarios);
				}
				break;
				case 4: //limitar nucleo
				{
					cout<<"Opcion 4"<<endl;
					cambiarLimNucleo(usuarios);
				}
				break;
				case 5:
				{
					cout<<"Saliendo del programa..."<<endl;
				}
				break;

				default: cout<<"Se ha ingresado una opcion incorrecta"<<endl;
				break;
			}
		}
	}

	if(id == "adminM"){
		menu3();
		int opcion;
		while(opcion != 5){
			cin>>opcion;
			switch(opcion){
				menu3();
				case 1: //alta maquina
				{
					cout<<"Opcion 1"<<endl;
					altaMaq(maquinas);
				}
				break;
				case 2: //bja maquina
				{
					cout<<"Opcion 2"<<endl;
					bajaMaq(reservas, usuarios, maquinas)
				}
				break;
				case 3: //cambiar nucleos totales
				{
					cout<<"Opcion 3"<<endl;
					cambiarNucTotal(maquinas);
				}
				break;
				case 4: //cambiar nucleos dispon
				{
					cout<<"Opcion 4"<<endl;
					cambiarNucDisp(maquinas);
				}
				break;
				case 5:
				{
					cout<<"Saliendo del programa..."<<endl;
				}
				break;

				default: cout<<"Se ha ingresado una opcion incorrecta"<<endl;
				break;
			}
		}
	}


	//escritura de ficheros
	escribeUsuarios(usuarios);
	escribeReservas(reservas);
	escribeMaquinas(maquinas);
}