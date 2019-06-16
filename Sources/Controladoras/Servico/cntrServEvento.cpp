//
// Created by paulo on 15/06/19.
//

#include "../../../Headers/Controladoras/Servico/cntrServEvento.h"

std::list<std::pair<Evento, Apresentacao>>
cntrServEvento::pesquisar(const Data &dataInicio, const Data &dataTermino, const Cidade &cidade, const Estado &estado) {

    ComandoPesquisarEvento sqlPesquisarEvento;
    return sqlPesquisarEvento.pesquisarEvento(dataInicio, dataTermino, cidade, estado);

}

void cntrServEvento::cadastrarEvento(const Codigo_De_Evento &codigoDeEvento, const Nome_De_Evento &nomeDeEvento,
                                     const std::list<Apresentacao> &apresentacoes, const Cidade &cidade,
                                     const Estado &estado, const Classe_De_Evento &classeDeEvento,
                                     const Faixa_Etaria &faixaEtaria, const Usuario &usuario) {
        ComandoCadastrarEvento sqlCadastrarEvento;
        sqlCadastrarEvento.cadastrarEvento(codigoDeEvento, nomeDeEvento, apresentacoes, cidade, estado, classeDeEvento, faixaEtaria, usuario);


}

void cntrServEvento::descadastrarEvento(const Codigo_De_Evento &codigoDeEvento, const Usuario &usuario) {
    ComandoDescadastrarEvento comandoDescadastrarEvento;
    comandoDescadastrarEvento.descadastrarEvento(codigoDeEvento, usuario);
}

void
cntrServEvento::editarEvento(const Evento &evento, const Usuario &usuario) {
    ComandoEditarEvento comandoEditarEvento;
    comandoEditarEvento.editarEvento(evento, usuario);
}
