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
	Usuario(string idUsuario, string correo, int limTiempo, int limNucleo, int tDisp, int nDisp);
	void crearReserva(std::string correoElectronico, int numNucleos, time_t tiempo);
	void modificarReserva(std::string id_reser,std::string correoElectronico, int numNucleos, time_t tiempo);
	void cancelarReserva(std::string id_reser);
	inline string getIdUsu(){return idUsu;}
	inline void setIdUsu(string id){idUsu=id;}
	inline string getCorreo(){return correo;}
	inline void setCorreo(string cor){correo=cor;}
	inline time_t getLim_tiempo(){return lim_tiempo;}
	inline void setLim_tiempo(time_t tiempo){lim_tiempo=tiempo;}
	inline int getLim_nucleo(){return lim_nucleo;}
	inline void setLim_nucleo(int limite){lim_nucleo=limite;}
	inline time_t getTiempoDisp(){return tiempoDisp;}
	inline void setTiempoDisp(time_t tiempo){tiempoDisp=tiempo;}
	inline int getNucleoDisp(){return nucleoDisp;}
	inline void setNucleoDisp(int disp){nucleoDisp=disp;}
#endif /* CLASEUSUARIO_USUARIO_H_ */
