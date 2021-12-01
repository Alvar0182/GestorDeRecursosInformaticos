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

		inline string getId(){return id_maq;} 
	
		inline bool getEstado(){return estado;} 
	
		inline int getNucleoTotal(){return nuc_tot;} 

		inline int getNucleosDisp(){return nuc_disp;}
		void setNucleosDisp();
		
		//void visualizarMaquinas();
};