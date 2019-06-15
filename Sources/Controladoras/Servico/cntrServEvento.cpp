//
// Created by paulo on 15/06/19.
//

#include "../../../Headers/Controladoras/Servico/cntrServEvento.h"

std::list<Evento>
cntrServEvento::pesquisar(const Data &dataInicio, const Data &dataTermino, const Cidade &cidade, const Estado &estado) {
    return std::list<Evento>();
}

void cntrServEvento::cadastrarEvento(const Codigo_De_Evento &codigoDeEvento, const Nome_De_Evento &nomeDeEvento,
                                     const std::list<Apresentacao> &apresentacoes, const Cidade &cidade,
                                     const Estado &estado, const Classe_De_Evento &classeDeEvento,
                                     const Faixa_Etaria &faixaEtaria, const Usuario &usuario) {
        ComandoCadastrarEvento sqlCadastrarEvento(identificadorAcomodacao, tipoAcomodacao, capacidadeDeAcomodacao, diaria,
                                                cidade, estado, identificadorUsuario);
        sqlCadastrarEvento.executar();


}

void cntrServEvento::descadastrarEvento(const Codigo_De_Evento &codigoDeEvento, const Usuario &usuario) {

}

void
cntrServEvento::editarEvento(const Codigo_De_Evento &codigoDeEvento, const Evento &evento, const Usuario &usuario) {

}
