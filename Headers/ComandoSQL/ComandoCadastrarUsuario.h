//
// Created by Oscar Madureira on 18/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDOCADASTRARUSUARIO_H
#define TRABALHO_1_CLION_COMANDOCADASTRARUSUARIO_H


#include "../Entidades/Usuario.h"
#include "ComandoSQL.h"

class ComandoCadastrarUsuario: public ComandoSQL{
public:
    void cadastrarUsuario(const Cpf& cpf, const Senha& senha);
};


#endif //TRABALHO_1_CLION_COMANDOCADASTRARUSUARIO_H
