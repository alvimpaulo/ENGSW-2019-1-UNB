//
// Created by paulo on 15/06/19.
//

#include "../../Headers/ComandoSQL/ComandoCadastrarEvento.h"
#include "ios"
#include "iomanip"
#include "sstream"

void ComandoCadastrarEvento::cadastrarEvento(const Codigo_De_Evento *codigoDeEvento, const Nome_De_Evento &nomeDeEvento,
                                             const std::list<Apresentacao> &apresentacoes, const Cidade &cidade,
                                             const Estado &estado, const Classe_De_Evento &classeDeEvento,
                                             const Faixa_Etaria &faixaEtaria){
    int codigoApresentacaoAtual = 0;
    std::ostringstream codigoApresentacaoAtualStream;

    for (int i = 0; i < apresentacoes.size(); ++i) {
        listaResultado.clear();
        comandoSQL = "SELECT max(Codigo) \n"
                     "  FROM Apresentacoes;";
        this->executar();

        if(listaResultado.empty()){
            throw std::runtime_error("Pesquisa vazia");
        } else {
            while (!listaResultado.empty()) {
                codigoApresentacaoAtual = std::stoi(listaResultado.front().getValorColuna()) + 1;
                listaResultado.pop_front();
            }
            listaResultado.clear();

            codigoApresentacaoAtualStream << std::internal << std::setw(4) << std::setfill('0')<< codigoApresentacaoAtual;

            comandoSQL = "INSERT INTO Apresentacoes VALUES (\n"
                            "                              \"" + codigoApresentacaoAtualStream.str() + "\",\n"
                            "                              \"" + apresentacoes.front().getData().getData() + "\",\n"
                            "                              \"" + apresentacoes.front().getHorario().getHorario() + "\",\n"
                            "                              \"" + apresentacoes.front().getPreco().getPreco() + "\",\n"
                            "                              \"" + apresentacoes.front().getNumDeSala().getNumSala() + "\",\n"
                            "                              \"" + apresentacoes.front().getDisponibilidade().getDisponibilidade() + "\",\n"
                            "                              \"" + codigoDeEvento->getCodigoEvento() + "\"\n"
                            "                          );";

        }
    }

}
