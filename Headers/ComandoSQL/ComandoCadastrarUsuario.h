//
// Created by Oscar Madureira on 18/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDOCADASTRARUSUARIO_H
#define TRABALHO_1_CLION_COMANDOCADASTRARUSUARIO_H


#include "../Dominios/Nome.h"
#include "../Dominios/Identificador.h"
#include "../Dominios/Senha.h"
#include "ComandoSQL.h"

class ComandoCadastrarUsuario: public ComandoSQL{
public:
    void cadastrarUsuario(const Nome& nome, const Identificador& identificador, const Senha& senha);
};


#endif //TRABALHO_1_CLION_COMANDOCADASTRARUSUARIO_H
