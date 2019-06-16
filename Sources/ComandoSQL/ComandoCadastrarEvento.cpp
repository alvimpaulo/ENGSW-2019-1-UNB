//
// Created by paulo on 15/06/19.
//

#include "../../Headers/ComandoSQL/ComandoCadastrarEvento.h"
#include "ios"
#include "iomanip"
#include "sstream"
#include "ctime"

void ComandoCadastrarEvento::cadastrarEvento(const Codigo_De_Evento &codigoDeEvento, const Nome_De_Evento &nomeDeEvento,
                                             const std::list<Apresentacao> &apresentacoes, const Cidade &cidade,
                                             const Estado &estado, const Classe_De_Evento &classeDeEvento,
                                             const Faixa_Etaria &faixaEtaria, const Usuario &usuario){
    int codigoApresentacaoAtual = 0;
    int codigoEventoAtual = 0;
    std::ostringstream codigoApresentacaoAtualStream;
    std::ostringstream codigoEventoAtualStream;

    listaResultado.clear();

    comandoSQL = "SELECT max(Codigo) FROM Eventos;";
    this->executar();
    if(listaResultado.empty()) {
        throw std::runtime_error("Pesquisa vazia");
    } else{
        while (!listaResultado.empty()) {
            codigoEventoAtual = std::stoi(listaResultado.front().getValorColuna()) + 1;
            listaResultado.pop_front();
        }
        listaResultado.clear();

        codigoEventoAtualStream << std::internal << std::setw(3) << std::setfill('0')<< codigoEventoAtual;

        comandoSQL = "INSERT INTO Eventos VALUES (\n"
                     "                        \"" + codigoEventoAtualStream.str() + "\",\n"
                     "                        \"" + nomeDeEvento.getNome_De_Evento() + "\",\n"
                     "                        \"" + cidade.getCidade() + "\",\n"
                     "                        \"" + estado.getEstado() + "\",\n"
                     "                        \"" + classeDeEvento.getClasseEvento() + "\",\n"
                     "                        \"" + faixaEtaria.getFaixaEtaria() + "\",\n"
                     "                        \"" + usuario.getCpf().getCpf() + "\"\n"
                     "                    );";
                                                                                                                                                                                                                                                                                                                                                                                                                                                         "                    );"
    }

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

            //converter data de dd/mm/aaaa para aaaa-mm-dd
            struct tm tm;
            strptime(apresentacoes.front().getData().getData().c_str(), "%d/%m/%Y", &tm);
            char dataConverted[11];
            strftime(dataConverted, sizeof(dataConverted), "%Y-%m-%d", &tm);


            comandoSQL = "INSERT INTO Apresentacoes VALUES (\n"
                            "\"" + codigoApresentacaoAtualStream.str() + "\",\n"
                            "\"" + dataConverted + "\",\n"
                            "\"" + apresentacoes.front().getHorario().getHorario() + "\",\n"
                            "\"" + std::to_string(apresentacoes.front().getPreco().getPreco()) + "\",\n"
                            "\"" + apresentacoes.front().getNumDeSala().getNumSala() + "\",\n"
                            "\"" + apresentacoes.front().getDisponibilidade().getDisponibilidade() + "\",\n"
                            "\"" + codigoDeEvento->getCodigoEvento() + "\"\n"
                            ");";

            codigoApresentacaoAtualStream.str("");
            codigoApresentacaoAtualStream.clear();

        }
    }

}
