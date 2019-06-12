//
// Created by paulo on 17-Nov-18.
//

#ifndef TRABALHO_1_CLION_INTERSERVUSUARIOS_H
#define TRABALHO_1_CLION_INTERSERVUSUARIOS_H

#include "../../Entidades/Usuario.h"


class InterServUsuarios{
public:
    //cadastra um usuario no sistema
    virtual void cadastrarUsuario(const Cpf& cpf, const Senha& senha) = 0;

    //Descadastra um usuario, se for possivel
    virtual void descadastrarUsuario(const Usuario& usuario) = 0;

};


#endif //TRABALHO_1_CLION_INTERSERVUSUARIOS_H
