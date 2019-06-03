//
// Created by paulo on 17-Nov-18.
//

#ifndef TRABALHO_1_CLION_INTERSERVAUTENTICACAO_H
#define TRABALHO_1_CLION_INTERSERVAUTENTICACAO_H

#include "../../Entidades/Usuario.h"

class InterServAutenticacao {
public:
    //autentica o usuario
    virtual void autenticar(const Identificador& identificador, const Senha& senha) = 0;
};


#endif //TRABALHO_1_CLION_INTERSERVAUTENTICACAO_H
