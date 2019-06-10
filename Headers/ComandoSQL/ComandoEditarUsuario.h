//
// Created by Oscar Madureira on 20/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDOEDITARUSUARIO_H
#define TRABALHO_1_CLION_COMANDOEDITARUSUARIO_H


#include "ComandoSQL.h"
#include "../Dominios/Cidade.h"
#include "../Dominios/Senha.h"
#include "../Dominios/Identificador.h"

class ComandoEditarUsuario: public ComandoSQL{
public:
    void editarUsuario(const Cidade &nome, const Senha &senha, const Identificador &identificador);
};


#endif //TRABALHO_1_CLION_COMANDOEDITARUSUARIO_H
