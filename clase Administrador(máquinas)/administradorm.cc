/*
 * administradorm.cc
 *
 *  Created on: 24 nov. 2021
 *      Author: asimancas
 */

#include "administradorm.h"


void bajaMaq(){

	//pedir maquina

		string id;
		cin>>id;

	//buscar maquina

		list<Maquina>::iterator i;
			for(i=maquinas.begin();i!=maquinas.end();i++){
				if(id==i->getIdMaq()){

				//eliminar reservas asignada a la maquina
					list<Reserva>::iterator it;
					for(it=reservas.begin();it!=reservas.end();it++){
						if(i->getIdMaq()==it->getMaq_reser()){
							reservas.erase(it);
						}
					}

	//eliminar maquina

				maquinas.erase(i);		
		}

			}
}


