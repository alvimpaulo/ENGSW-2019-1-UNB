//
// Created by paulo on 17-Nov-18.
//

#ifndef TRABALHO_1_CLION_INTERSERVRESERVA_H
#define TRABALHO_1_CLION_INTERSERVRESERVA_H


#include "../../Entidades/Acomodacao.h"

class InterServReserva {
public:
    virtual void cancelarReserva(const Identificador& identificadorAcomodacao, const Intervalo_Datas& intervaloDatas, const Identificador& identificadorUsuario) = 0;
    virtual void realizarReserva(const Identificador& identificadorAcomodacao, const Intervalo_Datas& intervaloDatas, const Identificador& identificadorUsuario) = 0;

};


#endif //TRABALHO_1_CLION_INTERSERVRESERVA_H
