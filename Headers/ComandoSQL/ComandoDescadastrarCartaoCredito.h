//
// Created by Oscar Madureira on 20/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDODESCADASTRARCARTAOCREDITO_H
#define TRABALHO_1_CLION_COMANDODESCADASTRARCARTAOCREDITO_H


#include "../Dominios/Num_Cartao_Credito.h"
#include "ComandoSQL.h"

class ComandoDescadastrarCartaoCredito: public ComandoSQL{
public:
    void descadastrarCartao(const Num_Cartao_Credito &numCartaoCredito);
};


#endif //TRABALHO_1_CLION_COMANDODESCADASTRARCARTAOCREDITO_H
