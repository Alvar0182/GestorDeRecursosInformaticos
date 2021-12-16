#ifndef CLASE_ADMINISTRADOR_MÁQUINAS__ADMINISTRADORM_H_
#define CLASE_ADMINISTRADOR_MÁQUINAS__ADMINISTRADORM_H_

class Administradorm:public Administrador{
    private:
    std::string cargo;

    public:
    void altaMaq();
    void bajaMaq();
    void modifMaq();
};
#endif