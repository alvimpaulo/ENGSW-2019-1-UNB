//
// Created by paulo on 19-Nov-18.
//

#include "../../Headers/ComandoSQL/ComandoCancelarReserva.h"

ComandoCancelarReserva::ComandoCancelarReserva(const Identificador &identificadorAcomodacao,
                                               const Intervalo_Datas &intervaloDatas,
                                               const Identificador& identificadorUsuario) {
    listaResultado.clear();
    comandoSQL = "delete from Reservas where ";
    comandoSQL += "Acomodacao = '" + identificadorAcomodacao.getIdentificador() + "'";
    comandoSQL += "and DataInicio = '" + intervaloDatas.getDataInicio().getData() + "'";
    comandoSQL += "and DataTermino = '" + intervaloDatas.getDataTermino().getData() + "'";
    comandoSQL += "and Usuario = '" + identificadorUsuario.getIdentificador() + "';";
}
