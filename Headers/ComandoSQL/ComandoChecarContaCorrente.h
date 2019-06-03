//
// Created by paulo on 22-Nov-18.
//

#ifndef TRABALHO_1_CLION_COMANDOCHECARCONTACORRENTE_H
#define TRABALHO_1_CLION_COMANDOCHECARCONTACORRENTE_H

#include "ComandoSQL.h"
#include "../Entidades/Acomodacao.h"

class ComandoChecarContaCorrente :public ComandoSQL {
public:
    ComandoChecarContaCorrente(const Identificador& identificadorUsuario);
    bool existeConta();
};


#endif //TRABALHO_1_CLION_COMANDOCHECARCONTACORRENTE_H
