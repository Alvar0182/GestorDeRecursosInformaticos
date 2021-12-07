void bajaUsuario(){
	//pedir usuario
  
	  string id;
	  cin>>id;
	//buscar usuario
  
	  list<Usuario>::iterator i;
		for(i=usuarios.begin();i!=usuarios.end();i++){
			  if(id==i->getIdUsu()){
	//eliminar usuario

				usuarios.erase(i);		
		    }
    }
