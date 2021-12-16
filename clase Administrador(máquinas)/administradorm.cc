#include "administradorm.h"
#include <vector>
#include <list>
#include <string>

void Administradorm::bajaMaq(){
	//pedir maquina
		std::string id;
		cin>>id;
	//buscar maquina
		std::list<Maquina>::iterator i;
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

void Administrador::altaMaq(){
    std::cout<<"Introduzca los datos de la maquina (id, estado, nucleos totales, nucleos disponibles)"<<std::endl;
    string id_maq;
	int nuc_tot;
    std::cout<<"Introduzca el id de la maquina"<<std:endl;
    std::cin>>id_maq;
    std::cout<<"Introduzca los nucleos totales de la maquina"<<std:endl;
    std::cin>>nuc_tot;
    Maquina(id_maq,nuc_tot);
    maquinas.push_back(Maquina);
}

void Administrador::modifMaq(){
    std::string maquina;
    int nucleos;
    std::cout<<"Introduzca el id de la maquina que desea modificar"<<std::endl;
    std::cin>>id_maquina;
    std::cout<<"Introduzca el numero de nucleos que desea poner a la maquina"<<std::endl;
    std::cin>>nucleos;

    std::list<Maquina>::iterator i;
    for(i=maquinas.begin();i!=maquinas.end();i++){
        if(maquina=i->getIdMaq()){
            (*i).setnumNucleos(nucleos);
        }
    }
}