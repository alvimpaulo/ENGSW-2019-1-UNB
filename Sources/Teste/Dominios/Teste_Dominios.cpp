//
// Created by oetch on 30/09/2018.
//

#include "../../../Headers/Teste/Dominios/Teste_Dominios.h"

int Teste_Dominios::rodar(){
    configurar();

    casoSucesso();
    casoFalha();

    desconfigurar();

    return estado;
}