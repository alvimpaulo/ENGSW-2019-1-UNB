//
// Created by paulo on 16/06/19.
//

#include "../../Headers/ComandoSQL/ComandoPesquisarEvento.h"
#include "ios"
#include "iomanip"
#include "sstream"
#include "ctime"
#include <utility>

std::list<std::pair<Evento, Apresentacao> >
ComandoPesquisarEvento::pesquisarEvento(const Data &dataInicio, const Data &dataTermino, const Cidade &cidade,
                                        const Estado &estado) {
    listaResultado.clear();
    std::list<std::pair<Evento, Apresentacao> > listaEventoApresentacao;

    //converter data de dd/mm/aaaa para aaaa-mm-dd
    struct tm tmDataInicio;
    strptime(dataInicio.getData().c_str(), "%d/%m/%Y", &tmDataInicio);
    char dataInicioConverted[11];
    strftime(dataInicioConverted, sizeof(dataInicioConverted), "%Y-%m-%d", &tmDataInicio);

    //converter data de dd/mm/aaaa para aaaa-mm-dd
    struct tm tmDataTermino;
    strptime(dataInicio.getData().c_str(), "%d/%m/%Y", &tmDataTermino);
    char dataTerminoConverted[11];
    strftime(dataTerminoConverted, sizeof(dataTerminoConverted), "%Y-%m-%d", &tmDataTermino);

    comandoSQL = "SELECT Eventos.Nome,\n"
                 "       Apresentacoes.Codigo,\n"
                 "       Apresentacoes.Data,\n"
                 "       Apresentacoes.Horario,\n"
                 "       Apresentacoes.Preco,\n"
                 "       Apresentacoes.Sala,\n"
                 "       Apresentacoes.Disponibilidade,\n"
                 "       Eventos.Classe,\n"
                 "       Eventos.Faixa\n"
                 "  FROM Apresentacoes\n"
                 "       INNER JOIN\n"
                 "       Eventos ON Apresentacoes.Evento = Eventos.Codigo\n"
                 " WHERE Evento IN (\n"
                 "           SELECT Codigo\n"
                 "             FROM Eventos\n"
                 "            WHERE (Estado, Cidade) = (\"" + estado.getEstado() + "\", \"" + cidade.getCidade() + "\") \n"
                 "       )\n"
                 "AND \n"
                 "       Data >= \"" + dataInicioConverted + "\" AND \n"
                 "       Data <= \"" + dataTerminoConverted + "\";";

    this->executar();

    if(listaResultado.empty()) {
        throw std::runtime_error("Pesquisa vazia");
    } else {
        Evento eventoAtual;
        Apresentacao apresentacaoAtual;
        Nome_De_Evento nomeDeEventoAtual;
        Codigo_De_Apresentacao codigoDeApresentacaoAtual;
        Data dataAtual;
        Horario horarioAtual;
        Preco precoAtual;
        Num_De_Sala numDeSalaAtual;
        Disponibilidade disponibilidadeAtual;
        Classe_De_Evento classeDeEventoAtual;
        Faixa_Etaria faixaEtariaAtual;


        const int numDeColunas = 9;
        int colunasPercorridas = 0;

        while (!listaResultado.empty()){
            ElementoResultado colunaAtual;
            colunaAtual = listaResultado.front();
            if (!colunaAtual.getNomeColuna().compare("Nome")) {
                nomeDeEventoAtual.setNome_De_Evento(colunaAtual.getValorColuna());
                eventoAtual.setNomeDeEvento(nomeDeEventoAtual);
                colunasPercorridas++;
            }
            if (!colunaAtual.getNomeColuna().compare("Codigo")) {
                codigoDeApresentacaoAtual.setCodigoApresentacao(colunaAtual.getValorColuna());
                apresentacaoAtual.setCodigoDeApresentacao(codigoDeApresentacaoAtual);
                colunasPercorridas++;
            }
            if (!colunaAtual.getNomeColuna().compare("Data")) {

                //converter data de aaaa-mm-dd para dd/mm/aaaa
                std::string rawData;
                rawData = colunaAtual.getValorColuna();
                struct tm tmDataApresentacao;
                strptime(rawData.c_str(), "%Y-%m-%d", &tmDataApresentacao);
                char dataApresentacaoConverted[11];
                strftime(dataApresentacaoConverted, sizeof(dataApresentacaoConverted), "%d/%m/%Y", &tmDataApresentacao);

                dataAtual.setData(dataApresentacaoConverted);
                apresentacaoAtual.setData(dataAtual);
                colunasPercorridas++;
            }
            if (!colunaAtual.getNomeColuna().compare("Horario")) {
                horarioAtual.setHorario(colunaAtual.getValorColuna());
                apresentacaoAtual.setHorario(horarioAtual);
                colunasPercorridas++;
            }
            if (!colunaAtual.getNomeColuna().compare("Preco")) {
                precoAtual.setPreco(colunaAtual.getValorColuna());
                apresentacaoAtual.setPreco(precoAtual);
                colunasPercorridas++;
            }
            if (!colunaAtual.getNomeColuna().compare("Sala")) {
                numDeSalaAtual.setNumSala(colunaAtual.getValorColuna());
                apresentacaoAtual.setNumDeSala(numDeSalaAtual);
                colunasPercorridas++;
            }
            if (!colunaAtual.getNomeColuna().compare("Disponibilidade")) {
                disponibilidadeAtual.setDisponibilidade(colunaAtual.getValorColuna());
                apresentacaoAtual.setDisponibilidade(disponibilidadeAtual);
                colunasPercorridas++;
            }
            if (!colunaAtual.getNomeColuna().compare("Classe")) {
                classeDeEventoAtual.setClasseEvento(colunaAtual.getValorColuna());
                eventoAtual.setClasseDeEvento(classeDeEventoAtual);
                colunasPercorridas++;
            }
            if (!colunaAtual.getNomeColuna().compare("Faixa")) {
                faixaEtariaAtual.setFaixaEtaria(colunaAtual.getValorColuna());
                eventoAtual.setFaixaEtaria(faixaEtariaAtual);
                colunasPercorridas++;
            }
            listaResultado.pop_front();
            if(colunasPercorridas % numDeColunas == 0) { // se tiver sido lido todas as colunas
                listaEventoApresentacao.emplace_back(eventoAtual, apresentacaoAtual);
            }
        }

        return listaEventoApresentacao;
    }
}
