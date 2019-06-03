//
// Created by paulo on 19-Nov-18.
//

#ifndef TRABALHO_1_CLION_COMANDOCANCELARRESERVA_H
#define TRABALHO_1_CLION_COMANDOCANCELARRESERVA_H

#include "ComandoSQL.h"
#include "../Entidades/Acomodacao.h"

class ComandoCancelarReserva: public ComandoSQL {
public:
    ComandoCancelarReserva(const Identificador& identificadorAcomodacao, const Intervalo_Datas& intervaloDatas, const Identificador& identificadorUsuario);
};


#endif //TRABALHO_1_CLION_COMANDOCANCELARRESERVA_H
