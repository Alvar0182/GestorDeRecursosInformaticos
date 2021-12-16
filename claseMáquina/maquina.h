//maquina.h

#ifndef MAQUINA_H
#define MAQUINA_H

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Maquina{
	
	private:
		string id_maq;
		bool estado; //true = disponible
		int nuc_tot;
		int nuc_disp;
	public:
		
		Maquina(string id, int nucleos);

		inline string getIdMaq(){return id_maq;} 
	
		inline bool getEstado(){return estado;} 
	
		inline int getNucleoTotal(){return nuc_tot;} 

		inline int getNucleosDisp(){return nuc_disp;}
		
		inline void setNuc_Disp(const int nucleos){nuc_disp = nucleos; if(nuc_disp<=0){estado=false; nuc_disp=0; }else{estado=true;}}
		inline void setNuc_Tot(const int nucleos){nuc_tot = nucleos;}
		inline void setId_Maq(const string id){id_maq = id;}
		inline void setEstado(const bool status){estado = status;}

		
		//void visualizarMaquinas();
};

#endif
