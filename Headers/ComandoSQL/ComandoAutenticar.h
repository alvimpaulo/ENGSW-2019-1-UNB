//
// Created by Oscar Madureira on 18/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDOAUTENTICAR_H
#define TRABALHO_1_CLION_COMANDOAUTENTICAR_H


#include "ComandoSQL.h"
#include "../Entidades/Usuario.h"

class ComandoAutenticar: public ComandoSQL{
public:
    std::string getSenha(const Usuario &usuario);
};


#endif //TRABALHO_1_CLION_COMANDOAUTENTICAR_H
