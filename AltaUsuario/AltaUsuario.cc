void altaUsuario(){
	//pedir datos
	  string id;
	  string correo;
	  time_t tiempo; //con time_t o struct de tiempo
	  int nucleos;

	  cout<<"Indica los datos del nuevo usuario"<<endl;
	  cout<<"Indica nombre"<<endl;
	  cin>>id;
	  cout<<"Indica correo"<<endl;
	  cin>>correo;
	  cout<<"Indica el tiempo disponible"<<endl;
	  cin>>tiempo;
	  cout<<"Indica los nucleos disponibles"<<endl;
	  cin>>nucleos;

  //buscar si existe
	  int existe=0;
	  list<Usuario>::iterator i;
		for(i=usuarios.begin();i!=usuarios.end();i++){
			if(id==i->getIdUsu()){
        existe=1;}
		}
  //crear objeto
	  if(existe==1){
		  Usuario usu(id, correo, tiempo, tiempo, nucleos, nucleos);

  //añadir a la lista
	    usuarios.push_back(usu);
	  }
}
