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
	        
	        inline void setIdMaq(std::string nombre){id_maq=nombre;}   
	       
		inline bool getEstado(){return estado;} 
	
		inline int getNucleoTotal(){return nuc_tot;} 

		inline int getNucleosDisp(){return nuc_disp;}
		
		inline void setNucleosDisp(const int nucleos){nuc_disp = nucleos; if(nuc_disp<=0){estado=false; nuc_disp=0; }else{estado=true;}}
		
		//void visualizarMaquinas();
};

#endif
