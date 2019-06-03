//
// Created by Oscar Madureira on 20/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDODESCADASTRARCONTACORRENTE_H
#define TRABALHO_1_CLION_COMANDODESCADASTRARCONTACORRENTE_H


#include "ComandoSQL.h"
#include "../Dominios/Num_Conta_Corrente.h"

class ComandoDescadastrarContaCorrente: public ComandoSQL{
public:
    void descadastrarConta(const Num_Conta_Corrente &numContaCorrente);
};


#endif //TRABALHO_1_CLION_COMANDODESCADASTRARCONTACORRENTE_H
