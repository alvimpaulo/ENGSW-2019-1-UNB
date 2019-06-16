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

std::list< std::pair<std::string, std::list<std::string> > >
CntrServVendas::solicitarInformacaoDeVendas(const Codigo_De_Evento &codigoDeEvento, const Usuario &usuario) {
    ComandoSolicitarInformacaoDeVendas sqlSolicitar(codigoDeEvento, usuario);
    sqlSolicitar.executar();
    std::list< std::pair<std::string, std::list<std::string> > > resultadoPesquisa = sqlSolicitar.getApresentacaoVsCpf(codigoDeEvento, usuario);
    return resultadoPesquisa;
}
