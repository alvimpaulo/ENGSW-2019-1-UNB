//
// Created by paulo on 15/06/19.
//

#include "../../../Headers/Controladoras/Servico/CntrServEvento.h"

std::list<std::pair<Evento, Apresentacao>>
CntrServEvento::pesquisar(const Data &dataInicio, const Data &dataTermino, const Cidade &cidade, const Estado &estado) {

    ComandoPesquisarEvento sqlPesquisarEvento;
    return sqlPesquisarEvento.pesquisarEvento(dataInicio, dataTermino, cidade, estado);

}

void CntrServEvento::cadastrarEvento(const Nome_De_Evento &nomeDeEvento,
                                     const std::list<Apresentacao> &apresentacoes, const Cidade &cidade,
                                     const Estado &estado, const Classe_De_Evento &classeDeEvento,
                                     const Faixa_Etaria &faixaEtaria, const Usuario &usuario) {
        ComandoCadastrarEvento sqlCadastrarEvento;
        sqlCadastrarEvento.cadastrarEvento(nomeDeEvento, apresentacoes, cidade, estado, classeDeEvento, faixaEtaria, usuario);


}

void CntrServEvento::descadastrarEvento(const Codigo_De_Evento &codigoDeEvento, const Usuario &usuario) {
    ComandoDescadastrarEvento comandoDescadastrarEvento;
    comandoDescadastrarEvento.descadastrarEvento(codigoDeEvento, usuario);
}

void
CntrServEvento::editarEvento(const Evento &evento, const Usuario &usuario) {
    ComandoEditarEvento comandoEditarEvento;
    comandoEditarEvento.editarEvento(evento, usuario);
}
