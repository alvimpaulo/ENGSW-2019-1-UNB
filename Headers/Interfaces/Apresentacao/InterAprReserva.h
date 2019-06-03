//
// Created by paulo on 17-Nov-18.
//

#ifndef TRABALHO_1_CLION_INTERAPRRESERVA_H
#define TRABALHO_1_CLION_INTERAPRRESERVA_H


#include "../../Dominios/Identificador.h"
#include "../Servico/InterServReserva.h"

class InterAprReserva {
private:
protected:
public:
    virtual void executar(Identificador &identificador) = 0;
    virtual void setCntrsServReserva(InterServReserva *cntrsServReserva) = 0;
};


#endif //TRABALHO_1_CLION_INTERAPRRESERVA_H
