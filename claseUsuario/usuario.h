#ifndef CLASEUSUARIO_USUARIO_H_
#define CLASEUSUARIO_USUARIO_H_

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Usuario{
private:
	string idUsu;
	string correo;
	int lim_tiempo;
	int lim_nucleo;
	int tiempoDisp;
	int nucleoDisp;
public:
	Usuario(string idUsuario, string mail, int limTiempo, int limNucleo, int tDisp, int nDisp);
	/*void crearReserva(std::string correoElectronico, int numNucleos, time_t tiempo);
	void modificarReserva(std::string id_reser,std::string correoElectronico, int numNucleos, time_t tiempo);
	void cancelarReserva(std::string id_reser);*/
	inline string getIdUsu(){return idUsu;}
	inline void setIdUsu(string id){idUsu=id;}
	inline string getCorreo(){return correo;}
	inline void setCorreo(string cor){correo=cor;}
	inline ing getLim_tiempo(){return lim_tiempo;}
	inline void setLim_tiempo(int tiempo){lim_tiempo=tiempo;}
	inline int getLim_nucleo(){return lim_nucleo;}
	inline void setLim_nucleo(int limite){lim_nucleo=limite;}
	inline int getTiempoDisp(){return tiempoDisp;}
	inline void setTiempoDisp(int tiempo){tiempoDisp=tiempo;}
	inline int getNucleoDisp(){return nucleoDisp;}
	inline void setNucleoDisp(int disp){nucleoDisp=disp;}
#endif /* CLASEUSUARIO_USUARIO_H_ */
