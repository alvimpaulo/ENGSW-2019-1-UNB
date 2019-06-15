//
// Created by paulo on 17-Nov-18.
//

#ifndef TRABALHO_1_CLION_INTERAPRUSUARIOS_H
#define TRABALHO_1_CLION_INTERAPRUSUARIOS_H


#include "../../Controladoras/Servico/CntrServUsuarios.h"
#include "../Servico/InterServUsuarios.h"

class InterAprUsuarios {
private:
protected:
public:
    virtual void cadastrar() = 0;
    virtual void executar(Usuario& usuario) = 0;
    virtual void setCntrsServUsuarios(InterServUsuarios *cntrsServUsuarios) = 0;
};


#endif //TRABALHO_1_CLION_INTERAPRUSUARIOS_H
