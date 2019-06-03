//
// Created by Oscar Madureira on 20/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDOCADASTRARCARTAOCREDITO_H
#define TRABALHO_1_CLION_COMANDOCADASTRARCARTAOCREDITO_H

#include "ComandoSQL.h"
#include "../Dominios/Identificador.h"
#include "../Dominios/Num_Cartao_Credito.h"
#include "../Dominios/Data_De_Validade.h"

class ComandoCadastrarCartaoCredito: public ComandoSQL{
public:
    void cadastrarCartaoCredito(const Identificador &identificador, const Num_Cartao_Credito &numCartaoCredito,
                                const Data_De_Validade &dataDeValidade);
};


#endif //TRABALHO_1_CLION_COMANDOCADASTRARCARTAOCREDITO_H
