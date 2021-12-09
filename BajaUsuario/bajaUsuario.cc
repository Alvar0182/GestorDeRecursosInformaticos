void bajaUsuario(){
	//pedir usuario
	string id;
	cin>>id;
	//buscar usuario
	int existe=0;
	list<Usuario>::iterator i;
		for(i=usuarios.begin();i!=usuarios.end();i++){
			if(id==i->getIdUsu()){

				//eliminar reservas que tenga el usuario
					list<Reserva>::iterator it;
					for(it=reservas.begin();it!=reservas.end();it++){
						if(i->getIdUsu()==it->getCreador()){
							reservas.erase(it);
						}
					}

				//eliminar usuario

				usuarios.erase(i);		

		}

}