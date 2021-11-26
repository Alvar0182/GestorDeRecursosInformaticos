//maquina.cc

#include "maquina.h"

using namespace std;


Maquina::Maquina(string id, int nucleos){
	id_maq=id;
	estado=true;
	nuc_tot=nucleos;
	nuc_disp=nucleos;
}

void setNucleosDisp(const int nucleos){
	nuc_disp = nucleos;
}