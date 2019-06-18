//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Entidades/Teste_Ingresso.h"

int Teste_Ingresso::rodar(){
    configurar();

    casoSucesso();

    desconfigurar();

    return estado;
}

void Teste_Ingresso::casoSucesso(){
    Codigo_De_Ingresso codigoDeIngresso;

    try{
        ingresso->setCodigoDeIngresso(codigoDeIngresso);

    } catch(std::exception &exception){
        std::cout<<exception.what() << std::endl;
        estado = FALHA;
    }


}
