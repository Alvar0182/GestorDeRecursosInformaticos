#ifndef CLASE_ADMINISTRADOR_USUARIOS__ADMINISTRADORU_H_
#define CLASE_ADMINISTRADOR_USUARIOS__ADMINISTRADORU_H_

class Administradoru:public Administrador{
    private:
    std::string cargo;

    public:
    void altaUsuario();
    void bajaUsuario();
};

#endif /* CLASE_ADMINISTRADOR_USUARIOS__ADMINISTRADORU_H_ */