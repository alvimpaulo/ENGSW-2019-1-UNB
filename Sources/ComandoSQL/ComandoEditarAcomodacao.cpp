//
// Created by paulo on 18-Nov-18.
//

#include "../../Headers/ComandoSQL/ComandoEditarAcomodacao.h"

ComandoEditarAcomodacao::ComandoEditarAcomodacao(const Identificador &identificadorAcomodacao,
                                                 const Acomodacao &acomodacao) {
    listaResultado.clear();
    comandoSQL = "update Acomodacoes set ";
    comandoSQL += "Tipo = '" + acomodacao.getTipo().getTipoAcomodacao() + "'";
    comandoSQL += ", Capacidade = '" + acomodacao.getCapacidade().getCapacidade_de_Acomodacao() + "'";
    comandoSQL += ", Cidade = '" + acomodacao.getCidade().getNome() + "'";
    comandoSQL += ", Estado = '" + acomodacao.getEstado().getEstado() + "'";
    comandoSQL += ", Diaria = '" + std::to_string(acomodacao.getDiaria().getDiaria()) + "'";
    comandoSQL += " where Identificador = '" + identificadorAcomodacao.getIdentificador() + "'";

}
