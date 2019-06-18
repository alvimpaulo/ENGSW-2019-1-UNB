//
// Created by paulo on 15/06/19.
//

#include "../../Headers/ComandoSQL/ComandoCadastrarEvento.h"
#include "ios"
#include "iomanip"
#include "sstream"
#include "ctime"

void ComandoCadastrarEvento::cadastrarEvento(const Nome_De_Evento &nomeDeEvento,
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
            if(listaResultado.front().getValorColuna() == "NULL"){
                codigoEventoAtual = 1;
            } else{
                codigoEventoAtual = std::stoi(listaResultado.front().getValorColuna()) + 1;
            }
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
        this->executar();
    }

    for (auto &apresentacao: apresentacoes) {
        listaResultado.clear();
        comandoSQL = "SELECT max(Codigo) \n"
                     "  FROM Apresentacoes;";
        this->executar();

        if(listaResultado.empty()){
            throw std::runtime_error("Pesquisa vazia");
        } else {
            while (!listaResultado.empty()) {
                if(listaResultado.front().getValorColuna() == "NULL"){
                    codigoApresentacaoAtual = 1;
                } else{
                    codigoApresentacaoAtual = std::stoi(listaResultado.front().getValorColuna()) + 1;
                }

                listaResultado.pop_front();
            }
            listaResultado.clear();

            codigoApresentacaoAtualStream << std::internal << std::setw(4) << std::setfill('0')<< codigoApresentacaoAtual;

            //converter data de dd/mm/aaaa para aaaa-mm-dd
            struct tm tm;
            strptime(apresentacao.getData().getData().c_str(), "%d/%m/%Y", &tm);
            char dataConverted[11];
            strftime(dataConverted, sizeof(dataConverted), "%Y-%m-%d", &tm);

            comandoSQL = "INSERT INTO Apresentacoes VALUES (\n"
                            "\"" + codigoApresentacaoAtualStream.str() + "\",\n"
                            "\"" + dataConverted + "\",\n"
                            "\"" + apresentacao.getHorario().getHorario() + "\",\n"
                            "\"" + std::to_string(apresentacao.getPreco().getPreco()) + "\",\n"
                            "\"" + apresentacao.getNumDeSala().getNumSala() + "\",\n"
                            "\"" + apresentacao.getDisponibilidade().getDisponibilidade() + "\",\n"
                            "\"" + codigoEventoAtualStream.str() + "\"\n"
                            ");";
            this->executar();

            codigoApresentacaoAtualStream.str("");
            codigoApresentacaoAtualStream.clear();

        }
    }

}
