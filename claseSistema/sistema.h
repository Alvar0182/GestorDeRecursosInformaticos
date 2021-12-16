#ifndef CLASESISTEMA_SISTEMA_H_
#define CLASESISTEMA_SISTEMA_H_

#include <iostream>
#include <cstdlib>


class Sistema{
	
	private:
		
        bool existeReserva;
        bool existeUsuario;
        bool existeMaquina;
        bool pasaLimite;
        bool sufcNuc;
	public:
		
		Sistema(bool existeReserva, bool existeUsuario, bool existeMaquina, bool pasaLimite, bool sufcNuc);

		inline bool comprobarReserva(const bool existeReserva){if(existeReserva=true){return true;}else{return false;})} 
		inline bool comprobarUsuario(const bool existeUsuario){if(existeUsuario=true){return true;}else{return false;})} 
		inline bool comprobarMaquina(const bool existeMaquina){if(existeMaquina=true){return true;}else{return false;})}
        inline bool comprobarLimite(const bool pasaLimite){if(pasaLimite=true){return true;}else{return false;})}
        inline bool quedanNuc(const bool sufcNuc){if(sufcNuc=true{return true;}else{return false;})};

		
};




#endif /* CLASESISTEMA_SISTEMA_H_ */
