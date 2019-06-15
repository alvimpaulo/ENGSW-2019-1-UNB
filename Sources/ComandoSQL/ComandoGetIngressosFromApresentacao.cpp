//
// Created by paulo on 14/06/19.
//

#include "../../Headers/ComandoSQL/ComandoGetIngressosFromApresentacao.h"

ComandoGetIngressosFromApresentacao::ComandoGetIngressosFromApresentacao(const Apresentacao &apresentacao) {
    listaResultado.clear();
    comandoSQL = "SELECT Cpf from Apresentacoes (Identificador, Tipo, Capacidade, Cidade, Estado, Preco, Usuario) values (";

    comandoSQL += ")";

}
