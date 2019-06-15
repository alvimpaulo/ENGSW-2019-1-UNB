//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRSERVAUTENTICACAO_H
#define TRABALHO_1_CLION_CNTRSERVAUTENTICACAO_H

#include "../../Interfaces/Servico/InterServAutenticacao.h"

class CntrServAutenticacao: public InterServAutenticacao{
public:
    //autentica o usuario
    void autenticar(const Usuario& usuario) override;
};


#endif //TRABALHO_1_CLION_CNTRSERVAUTENTICACAO_H
