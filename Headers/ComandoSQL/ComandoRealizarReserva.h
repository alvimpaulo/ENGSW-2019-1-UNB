//
// Created by paulo on 19-Nov-18.
//

#ifndef TRABALHO_1_CLION_COMANDOREALIZARRESERVA_H
#define TRABALHO_1_CLION_COMANDOREALIZARRESERVA_H

#include "ComandoSQL.h"
#include "../Entidades/Acomodacao.h"

class ComandoRealizarReserva: public ComandoSQL {
public:
    ComandoRealizarReserva(const Identificador& identificadorAcomodacao, const Intervalo_Datas& intervaloDatas, const Identificador& identificadorUsuario);
    void realizarReserva(const Identificador& identificadorAcomodacao, const Intervalo_Datas& intervaloDatas, const Identificador& identificadorUsuario);
};


#endif //TRABALHO_1_CLION_COMANDOREALIZARRESERVA_H
