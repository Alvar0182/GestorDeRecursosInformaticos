//sistema unitest

#include "sistema.h"
#include "gtest/gtest.h"

//Cambiar la ruta del makefile a la carpeta con googletest
//De todas formas en este directorio se encuentra el ejecutable con el que se hizo la prueba unitaria


TEST(existeReserva){
    Sistema sis(true);
    EXPECT_EQ(true, sis.comprobarReserva());
    Sistema sis(false);
    EXPECT_EQ(false, sis.comprobarReserva());
}

TEST(existeUsuario){
    Sistema sis(true);
    EXPECT_EQ(true, sis.comprobarUsuario());
    Sistema sis(false);
    EXPECT_EQ(false, sis.comprobarUsuario());

TEST(existeUsuario){
    Sistema sis(true);
    EXPECT_EQ(true, sis.comprobarUsuario());
    Sistema sis(false);
    EXPECT_EQ(false, sis.comprobarUsuario());

TEST(existeMaquina){
    Sistema sis(true);
    EXPECT_EQ(true, sis.comprobarMaquina());
    Sistema sis(false);
    EXPECT_EQ(false, sis.comprobarMaquina());
}

TEST(pasaLimite){
    Sistema sis(true);
    EXPECT_EQ(true, sis.comprobarLimite());
    Sistema sis(false);
    EXPECT_EQ(false, sis.comprobarlimite());
}
TEST(sufcNuc){
    Sistema sis(true);
    EXPECT_EQ(true, sis.quedanNuc());
    Sistema sis(false);
    EXPECT_EQ(false, sis.quedanNuc());
}