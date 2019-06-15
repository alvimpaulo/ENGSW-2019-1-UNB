//
// Created by paulo on 14/06/19.
//

#include "../../../Headers/Controladoras/Servico/CntrServVendas.h"

std::list<std::string>
CntrServVendas::comprarIngresso(const Usuario &usuario, const Codigo_De_Apresentacao &codigoDeApresentacao,
                                int qtdIngresso) {
    ComandoComprarIngresso sqlComprar;
    return sqlComprar.comprarIngresso(usuario, qtdIngresso, codigoDeApresentacao);
}

std::list<Cpf> CntrServVendas::solicitarInformacaoDeVendas(const Codigo_De_Evento &codigoDeEvento) {
    ComandoSolicitarInformacaoDeVendas sqlSolicitar(codigoDeEvento);
    sqlSolicitar.executar();
    std::list<Cpf> resultadoPesquisa = sqlSolicitar.getCpfs();
    return resultadoPesquisa;
}
