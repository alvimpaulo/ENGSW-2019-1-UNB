//
// Created by Oscar Madureira on 20/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDODESCADASTRARUSUARIO_H
#define TRABALHO_1_CLION_COMANDODESCADASTRARUSUARIO_H


#include "ComandoSQL.h"
#include "../Entidades/Usuario.h"

class ComandoDescadastrarUsuario: public ComandoSQL{
public:
    void descadastraUsuario(const Usuario& usuario);
};


#endif //TRABALHO_1_CLION_COMANDODESCADASTRARUSUARIO_H
