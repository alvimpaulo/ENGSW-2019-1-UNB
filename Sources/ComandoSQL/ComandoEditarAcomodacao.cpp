//
// Created by paulo on 18-Nov-18.
//

#include "../../Headers/ComandoSQL/ComandoEditarAcomodacao.h"

ComandoEditarAcomodacao::ComandoEditarAcomodacao(const Identificador &identificadorAcomodacao,
                                                 const Acomodacao &acomodacao) {
    listaResultado.clear();
    comandoSQL = "update Acomodacoes set ";
    comandoSQL += "Tipo = '" + acomodacao.getTipo().getTipoAcomodacao() + "'";
    comandoSQL += ", Capacidade = '" + acomodacao.getCapacidade().getNumSala() + "'";
    comandoSQL += ", Cidade = '" + acomodacao.getCidade().getCidade() + "'";
    comandoSQL += ", Estado = '" + acomodacao.getEstado().getEstado() + "'";
    comandoSQL += ", Preco = '" + std::to_string(acomodacao.getDiaria().getPreco()) + "'";
    comandoSQL += " where Identificador = '" + identificadorAcomodacao.getIdentificador() + "'";

}
