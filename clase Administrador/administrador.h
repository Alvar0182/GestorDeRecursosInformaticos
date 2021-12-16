#ifndef CLASE_ADMINISTRADOR_ADMINISTRADOR_H_
#define CLASE_ADMINISTRADOR_ADMINISTRADOR_H_

#include <string>

class Administrador{
private:
	std:: string id_admin;

public:
	void verInfor();
	void modificarReserva();
	void borrarReserva();
};
#endif /* CLASE_ADMINISTRADOR_ADMINISTRADOR_H_ */