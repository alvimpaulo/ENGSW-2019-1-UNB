//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRAPRAUTENTICACAO_H
#define TRABALHO_1_CLION_CNTRAPRAUTENTICACAO_H


#include "../../Interfaces/Apresentacao/InterAprAutenticacao.h"
#include "../../Entidades/Usuario.h"

class CntrAprAutenticacao: public InterAprAutenticacao{
private:
    InterServAutenticacao* cntrServAutenticacao;
protected:
public:
    CntrAprAutenticacao();
    void autenticar(Usuario &usuario) override;
    void setCntrsServAutenticacao(InterServAutenticacao *cntrServAutenticacao) override;
    virtual ~CntrAprAutenticacao();
};


#endif //TRABALHO_1_CLION_CNTRAPRAUTENTICACAO_H
