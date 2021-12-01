/*
 * usuario.h
 *
 *  Created on: 24 nov. 2021
 *      Author: asimancas
 */

#ifndef CLASEUSUARIO_USUARIO_H_
#define CLASEUSUARIO_USUARIO_H_

#include <string>
#include <ctime>
using namespace std;

class Usuario{
private:
	string idUsu;
	string correo;
	time_t lim_tiempo;
	int lim_nucleo;
	time_t tiempoDisp;
	int nucleoDisp;
public:
	void crearReserva(std::string correoElectronico, int numNucleos, time_t tiempo);
	void modificarReserva(std::string id_reser,std::string correoElectronico, int numNucleos, time_t tiempo);
	void cancelarReserva(std::string id_reser);
	void visualizarReserva();
};
#endif /* CLASEUSUARIO_USUARIO_H_ */
