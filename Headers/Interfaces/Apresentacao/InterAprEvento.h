//
// Created by paulo on 10/06/19.
//

#ifndef TRABALHO_1_CLION_INTERAPREVENTO_H
#define TRABALHO_1_CLION_INTERAPREVENTO_H

#include "../Servico/InterServEvento.h"
#include "../../Entidades/Usuario.h"

class InterAprEvento {
    private:
    protected:
    public:
        virtual void executar(Usuario& usuario) = 0;
        virtual void setCntrsServAutenticacao(InterServEvento *cntrServEvento) = 0;

};


#endif //TRABALHO_1_CLION_INTERAPREVENTO_H
