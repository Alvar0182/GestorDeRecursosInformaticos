//usuario_unittest.cc

#include "usuario.h"
#include "gtest/gtest.h"


TEST(Usuario, Constructor){
    Usuario test("usuario", "correo", 1,2,3,4);
    EXPECT_EQ("usuario",test.getIdUsu());
    EXPECT_EQ("correo", test.getCorreo());
    EXPECT_EQ(1,test.getLim_tiempo());
    EXPECT_EQ(2,test.getLim_nucleo());
    EXPECT_EQ(3,test.getTiempoDisp());
    EXPECT_EQ(4,test.getNucleoDisp());

}

TEST(Usuario, Setters){
    Usuario u("aaa", "b", 2,2,2,2);
    u.setIdUsu("usuarioM");
    EXPECT_EQ("usuarioM",test.getIdUsu());
    u.setLim_tiempo(4);
    EXPECT_EQ(4,test.getLim_tiempo());
    u.setLim_nucleo(3);
    EXPECT_EQ(3,test.getLim_nucleo());
    u.setTiempoDispo(1);
    EXPECT_EQ(1,test.getTiempoDisp());
    u.setNucleoDisp(5);
    EXPECT_EQ(5,test.getNucleoDisp());
}