//
// Created by paulo on 18-Nov-18.
//

#include "../../Headers/ComandoSQL/ComandoCadastrarAcomodacao.h"

ComandoCadastrarAcomodacao::ComandoCadastrarAcomodacao(const Identificador &identificador,
                                                       const Tipo_Acomodacao &tipoAcomodacao,
                                                       const Num_De_Sala &capacidadeDeAcomodacao,
                                                       const Preco &diaria, const Cidade &cidade, const Estado &estado,
                                                       const Identificador& identificadorUsuario) {
    listaResultado.clear();
    comandoSQL = "insert into Acomodacoes (Identificador, Tipo, Capacidade, Cidade, Estado, Preco, Usuario) values (";
    comandoSQL += "'" + identificador.getIdentificador() + "'";
    comandoSQL += ", '" + tipoAcomodacao.getTipoAcomodacao() + "'";
    comandoSQL += ", '" + capacidadeDeAcomodacao.getNumSala() + "'";
    comandoSQL += ", '" + cidade.getCidade() + "'";
    comandoSQL += ", '" + estado.getEstado() + "'";
    comandoSQL += ", '" + std::to_string(diaria.getPreco()) + "'";
    comandoSQL += ", '" + identificadorUsuario.getIdentificador() + "'";
    comandoSQL += ")";
}
