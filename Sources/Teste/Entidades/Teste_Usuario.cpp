//
// Created by oetch on 16/09/2018.
//

#include "../../../Headers/Teste/Entidades/Teste_Usuario.h"

int Teste_Usuario::rodar(){
    configurar();

    casoSucesso();

    desconfigurar();

    return estado;
}

void Teste_Usuario::casoSucesso(){
    Cpf cpf;
    Senha senha;

    try{
        usuario->setSenha(senha);
        usuario->setCpf(cpf);
    } catch(std::exception &exception){
        std::cout<<exception.what() << std::endl;
        estado = FALHA;
    }


}


