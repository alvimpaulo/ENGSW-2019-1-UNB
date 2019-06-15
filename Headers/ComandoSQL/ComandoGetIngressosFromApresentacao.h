//
// Created by paulo on 14/06/19.
//

#ifndef TRABALHO_1_CLION_COMANDOGETINGRESSOSFROMAPRESENTACAO_H
#define TRABALHO_1_CLION_COMANDOGETINGRESSOSFROMAPRESENTACAO_H

#include "../Entidades/Apresentacao.h"
#include "ComandoSQL.h"


class ComandoGetIngressosFromApresentacao: public ComandoSQL{
public:
    ComandoGetIngressosFromApresentacao(const Apresentacao &apresentacao);
};


#endif //TRABALHO_1_CLION_COMANDOGETINGRESSOSFROMAPRESENTACAO_H
