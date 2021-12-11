void crearReserva(){

	//pedir datos
		string id;
		string creador;
		time_t time;
		int nucleos;
		string maquina;

	  cout<<"Indica los datos de esta reserva"<<endl;
	  cout<<"Indica id de reserva"<<endl;
	  cin>>id;
	  cout<<"Indica tu id de usuario"<<endl;
	  cin>>creador;
	  cout<<"Indica el tiempo a reservar"<<endl;
	  cin>>time;
	  cout<<"Indica los nucleos a reservar"<<endl;
	  cin>>nucleos;
	  cout<<"Indica de que maquina reservar"<<endl;
	  cin>>maquina;

	//buscar si existe

	  int existe=0;		//Usaremos existe de forma que si alguna condicion no se cumple, lo ponemos a 0 y se salta el resto de comprobaciones y no se crea el objeto
	  list<Reserva>::iterator i;
		for(i=reservas.begin();i!=reservas.end();i++){
			if(id==i->getId_reser()){
        existe=1;}
		}

	//buscar si el usuario puede

		if(existe==1){
			//buscar al usuario
			//comparar tiempos/nucleos
			//restar si se puede

			list<Usuario>::iterator itu;
			for(itu=usuarios.begin();itu!=usuarios.end();itu++){
				
				if(creador==itu->getIdUsu()){

					if(time>itu->getTiempoDisp()){
						//El tiempo a reservar es mayor del que puede
						cout<<"No puedes reservar tanto tiempo"<<endl;
						existe=0;
					}else{
							//Si puede reservar esa cantidad de tiempo
							itu->setTiempoDisp( (itu->getTiempoDisp()-time) );
						}

					if(nucelos>itu->getNucleoDisp()){
						//Los nucleos a reservar son mas de lo que puede
						cout<<"No puedes reservar tantos nucleos"<<endl;
						existe=0;
					}else{
							//Si puede reservar la cantidad de nucleos
							itu->setNucleoDisp( (itu->getNucleoDisp()-nucleos) );
						}
				}


			}

			
		}
	//buscar si la maquina puede
		if(existe==1){
			//buscar la maquina
			//comparar nucleos
			//restar si se puede

			list<Maquina>::iterator itm;
			for(itm=maquinas.begin();itm!=maquinas.end();i++;){
				if(maquina==itm->getIdMaq()){
					if(nucleos>itm->getNucleosDisp()){
						//Se intenta reservas mas de lo que puede la maquina
						cout<<"Esta maquina no tienen tantos nucleos disponibles"<<endl;
						existe=0;
					}else{
						itm->setNucleosDisp( (itm->getNucleosDisp()-nucleos) );
					}
				}
			}
		}

	//hacer la reserva
		if(existe==1){
			//creamos objeto de Reserva
			//añadimos a la lista

			Reserva res(id, creador, time, nucleos, maquina);
			reservas.push_back(res);
		}

}
