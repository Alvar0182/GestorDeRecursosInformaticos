//maquina.cc

#include "maquina.h"

using namespace std;

Maquina::Maquina(string id, int nucleos){
	id_maq=id;
	if(nucleos>0){
		estado=true;
		nuc_tot=nucleos;
		nuc_disp=nucleos;}
	else{
		estado=false;
		nuc_tot=0;
		nuc_disp=0;
	}
}
