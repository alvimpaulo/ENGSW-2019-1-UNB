//
// Created by paulo on 17-Nov-18.
//

#ifndef TRABALHO_1_CLION_INTERAPRACOMODACAO_H
#define TRABALHO_1_CLION_INTERAPRACOMODACAO_H


#include "../../Dominios/Identificador.h"
#include "../Servico/InterServAcomodacao.h"

class InterAprAcomodacao{
private:
protected:
public:
    virtual void executar(Identificador &identificadorUsuario) = 0;
    virtual void setCntrsServAcomodacao(InterServAcomodacao *cntrsServAcomodacao) = 0;
};


#endif //TRABALHO_1_CLION_INTERAPRACOMODACAO_H
