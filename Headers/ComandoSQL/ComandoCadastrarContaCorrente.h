//
// Created by Oscar Madureira on 20/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDOCADASTRARCONTACORRENTE_H
#define TRABALHO_1_CLION_COMANDOCADASTRARCONTACORRENTE_H

#include "ComandoSQL.h"
#include "../Dominios/Identificador.h"
#include "../Dominios/Num_Conta_Corrente.h"
#include "../Dominios/Agencia.h"
#include "../Dominios/Codigo_De_Evento.h"

class ComandoCadastrarContaCorrente: public ComandoSQL{
public:
    void cadastrarContaCorrente(const Identificador &identificador, const Num_Conta_Corrente &numContaCorrente,
                                 const Agencia &agencia, const Codigo_De_Evento &banco);
};


#endif //TRABALHO_1_CLION_COMANDOCADASTRARCONTACORRENTE_H
