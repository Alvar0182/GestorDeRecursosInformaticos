#include "reserva.h"
#include "gtest/gtest.h"

//Para compilar este test, cambie la ruta del makefile de esta carpeta y ponga la ruta donde tiene googletest. No obstante, está el ejecutable del mismo en esta misma carpeta
TEST(Reserva,Constructor){
    Reserva r("12345","Antonio",1500,5,"Maquina1");
    EXPECT_EQ("12345",r.getId_reser());
    EXPECT_EQ("Antonio",r.getCreador_reserva());
    EXPECT_EQ(1500,r.getTiempo());
    EXPECT_EQ(5,r.getNuc_reser());
    EXPECT_EQ("Maquina1",r.getMaq_reser());
}

TEST(Resera,Setters){
    Reserva r("67890","Juan",2000,6,"Maquina2");
    EXPECT_EQ("Juan",r.getCreador_reserva());
    r.setCreador_reserva("Jesus");
    EXPECT_EQ("Jesus",r.getCreador_reserva());
}