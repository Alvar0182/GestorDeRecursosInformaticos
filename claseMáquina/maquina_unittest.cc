//maquina_unittest

#include "maquina.h"
#include "gtest/gtest.h"

//Cambiar la ruta del makefile a la carpeta con googletest
//De todas formas en este directorio se encuentra el ejecutable con el que se hizo la prueba unitaria

TEST(Maquina, ObjetoConstructor){
    Maquina maq("aaaa", 10);
    EXPECT_EQ("aaaa",maq.getIdMaq());
    EXPECT_EQ(true, maq.getEstado());
    EXPECT_EQ(10,maq.getNucleoTotal());
    EXPECT_EQ(10,maq.getNucleosDisp());
}

TEST(Maquina, Estado){
    Maquina maq("aaaa", 10);
    EXPECT_EQ(true, maq.getEstado());
    EXPECT_EQ(10,maq.getNucleosDisp());
    maq.setNucleosDisp(0);
    EXPECT_EQ(false, maq.getEstado());
    EXPECT_EQ(0,maq.getNucleosDisp());
    maq.setNucleosDisp(5);
    EXPECT_EQ(true, maq.getEstado());
    EXPECT_EQ(5,maq.getNucleosDisp());
}

TEST(Maquina, DatoErroneo){
    Maquina maq("cccc", 10);
    EXPECT_EQ(true, maq.getEstado());
    EXPECT_EQ(10,maq.getNucleosDisp());
    maq.setNucleosDisp(-5);
    EXPECT_EQ(false, maq.getEstado());
    EXPECT_EQ(0,maq.getNucleosDisp());
    maq.setNucleosDisp(5);
    EXPECT_EQ(true, maq.getEstado());
    EXPECT_EQ(5,maq.getNucleosDisp());
    maq.setNucleosDisp(0);
    EXPECT_EQ(false, maq.getEstado());
    EXPECT_EQ(0,maq.getNucleosDisp());
}
