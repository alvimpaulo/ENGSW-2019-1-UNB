//
// Created by paulo on 14/06/19.
//

#ifndef TRABALHO_1_CLION_INTERAPRVENDAS_H
#define TRABALHO_1_CLION_INTERAPRVENDAS_H

#include "../Servico/InterServVendas.h"
#include "../../Entidades/Usuario.h"

class InterAprVendas {
public:
    virtual void executar(Usuario& usuario) = 0;
    virtual void setCntrServVendas(InterServVendas *cntrServVendas) = 0;
};


#endif //TRABALHO_1_CLION_INTERAPRVENDAS_H
