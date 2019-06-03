//
// Created by oetch on 30/09/2018.
//

#include "../../../Headers/Teste/Entidades/Teste_Entidades.h"

int Teste_Entidades::rodar(){
    configurar();

    casoSucesso();

    desconfigurar();

    return estado;
}