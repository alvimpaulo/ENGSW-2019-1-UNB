//
// Created by Oscar Madureira on 18/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDOAUTENTICAR_H
#define TRABALHO_1_CLION_COMANDOAUTENTICAR_H


#include "ComandoSQL.h"
#include "../Dominios/Identificador.h"
#include "../Dominios/Senha.h"

class ComandoAutenticar: public ComandoSQL{
public:
    std::string getSenha(Identificador identificador);
};


#endif //TRABALHO_1_CLION_COMANDOAUTENTICAR_H
