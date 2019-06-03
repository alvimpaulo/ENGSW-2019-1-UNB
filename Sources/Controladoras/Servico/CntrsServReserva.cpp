//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Servico/CntrsServReserva.h"

void
CntrsServReserva::cancelarReserva(const Identificador &identificadorAcomodacao, const Intervalo_Datas &intervaloDatas, const Identificador& identificadorUsuario) {
    ComandoCancelarReserva sqlCancelarReserva(identificadorAcomodacao, intervaloDatas, identificadorUsuario);
    sqlCancelarReserva.executar();
}

void
CntrsServReserva::realizarReserva(const Identificador &identificadorAcomodacao, const Intervalo_Datas &intervaloDatas, const Identificador& identificadorUsuario) {
    ComandoRealizarReserva sqlRealizarReserva(identificadorAcomodacao, intervaloDatas, identificadorUsuario);
    sqlRealizarReserva.realizarReserva(identificadorAcomodacao, intervaloDatas, identificadorUsuario);
}
