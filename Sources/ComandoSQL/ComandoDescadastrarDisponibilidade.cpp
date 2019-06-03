//
// Created by paulo on 21-Nov-18.
//

#include "../../Headers/ComandoSQL/ComandoDescadastrarDisponibilidade.h"

ComandoDescadastrarDisponibilidade::ComandoDescadastrarDisponibilidade(const Identificador &identificadorAcomodacao,
                                                                       const Identificador &identificadorUsuario,
                                                                       const Data &dataInicio,
                                                                       const Data &dataTermino) {
    listaResultado.clear();
    comandoSQL = "delete from Disponibilidade where Acomodacao = '" + identificadorAcomodacao.getIdentificador()
            + "' and Usuario = '" + identificadorUsuario.getIdentificador() + "'"
            + " and DataInicio = '" + dataInicio.getData() + "'";
            + " and DataTermino = '" + dataTermino.getData() + "'";

}
