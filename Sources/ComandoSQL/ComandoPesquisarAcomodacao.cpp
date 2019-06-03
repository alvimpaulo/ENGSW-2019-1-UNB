//
// Created by paulo on 18-Nov-18.
//

#include "../../Headers/ComandoSQL/ComandoPesquisarAcomodacao.h"

ComandoPesquisarAcomodacao::ComandoPesquisarAcomodacao(const Data &dataInicio, const Data &dataTermino,
                                                       const Capacidade_De_Acomodacao &capacidadeDeAcomodacao,
                                                       const Nome &cidade, const Estado &estado) {
    listaResultado.clear();
    comandoSQL = "SELECT * FROM Acomodacoes WHERE Capacidade = '";
    comandoSQL += capacidadeDeAcomodacao.getCapacidade_de_Acomodacao();
    comandoSQL += "' and Cidade = '";
    comandoSQL += cidade.getNome();
    comandoSQL += "' and Estado = '";
    comandoSQL += estado.getEstado();
    comandoSQL += "'";


}

std::list<Acomodacao> ComandoPesquisarAcomodacao::getResultado(const Data &dataInicio, const Data &dataTermino) {
    std::list<Acomodacao> list;
    Identificador identificadorUsuario;

    Identificador identificador;
    Tipo_Acomodacao tipoAcomodacao;
    Capacidade_De_Acomodacao capacidadeDeAcomodacao;
    Nome cidade;
    Estado estado;
    Diaria diaria;
    std::list<Intervalo_Datas> disponibilidades;
    std::list<Intervalo_Datas> reservas;

    Acomodacao acomodacaoAtual;

    if(listaResultado.empty()){
        throw std::runtime_error("Pesquisa vazia");
    }

    while(!listaResultado.empty()){
        ElementoResultado colunaAtual;
        colunaAtual = listaResultado.front();
        if (!colunaAtual.getNomeColuna().compare("Identificador")) // se for identificador
            identificador.setIdentificador(colunaAtual.getValorColuna());
        if (!colunaAtual.getNomeColuna().compare("Tipo")) // se for tipo
            tipoAcomodacao.setTipoAcomodacao(colunaAtual.getValorColuna());
        if (!colunaAtual.getNomeColuna().compare("Capacidade")) // se for identificador
            capacidadeDeAcomodacao.setCapacidade_De_Acomodacao(colunaAtual.getValorColuna());
        if (!colunaAtual.getNomeColuna().compare("Cidade")) // se for identificador
            cidade.setNome(colunaAtual.getValorColuna());
        if (!colunaAtual.getNomeColuna().compare("Estado")) // se for identificador
            estado.setEstado(colunaAtual.getValorColuna());
        if (!colunaAtual.getNomeColuna().compare("Diaria")) // se for identificador
            diaria.setDiaria(colunaAtual.getValorColuna());
        if (!colunaAtual.getNomeColuna().compare("Usuario")) // se for identificador
            identificadorUsuario.setIdentificador(colunaAtual.getValorColuna());
        listaResultado.pop_front();
    }
    acomodacaoAtual.setIdentificador(identificador);
    acomodacaoAtual.setDiaria(diaria);
    acomodacaoAtual.setEstado(estado);
    acomodacaoAtual.setCapacidade(capacidadeDeAcomodacao);
    acomodacaoAtual.setTipo(tipoAcomodacao);
    acomodacaoAtual.setCidade(cidade);
    list.push_back(acomodacaoAtual);

    Data dataInicioAtual;
    Data dataTerminoAtual;
    Intervalo_Datas dataAtual;
    std::list<Acomodacao>::iterator it;
    int numDataInicio = 0;
    int numDataTermino = 0;
    //Reservas
    for(it= list.begin(); it!= list.end(); ++it){
        comandoSQL = "select DataInicio, DataTermino from Reservas where Acomodacao = '";
        comandoSQL += it->getIdentificador().getIdentificador();
        comandoSQL += "'";
        this->executar();
        while (!listaResultado.empty()){
            ElementoResultado colunaAtual;
            colunaAtual = listaResultado.front();
            if (!colunaAtual.getNomeColuna().compare("DataInicio")) {
                dataInicioAtual.setData(colunaAtual.getValorColuna());
                numDataInicio++;
            }
            if (!colunaAtual.getNomeColuna().compare("DataTermino")) {
                dataTerminoAtual.setData(colunaAtual.getValorColuna());
                numDataTermino++;
            }
            listaResultado.pop_front();
            if(numDataInicio == numDataTermino) { // se tiver sido lido 1 par
                dataAtual.setDataInicio(dataInicioAtual);
                dataAtual.setDataTermino(dataTerminoAtual);
                if(dataAtual.getDataInicio() <= dataInicio && dataAtual.getDataTermino() >= dataTermino)
                    it->addReserva(dataAtual);
            }
        }

    }

    numDataInicio = 0;
    numDataTermino = 0;
    //Disponibilidades
    for(it= list.begin(); it!= list.end(); ++it){
        comandoSQL = "select DataInicio, DataTermino from Disponibilidade where Acomodacao = '";
        comandoSQL += it->getIdentificador().getIdentificador();
        comandoSQL += "'";
        this->executar();
        while (!listaResultado.empty()){
            ElementoResultado colunaAtual;
            colunaAtual = listaResultado.front();
            if(!colunaAtual.getNomeColuna().compare("DataInicio")) {
                dataInicioAtual.setData(colunaAtual.getValorColuna());
                numDataInicio++;
            }
            if(!colunaAtual.getNomeColuna().compare("DataTermino")) {
                dataTerminoAtual.setData(colunaAtual.getValorColuna());
                numDataTermino++;
            }
            listaResultado.pop_front();
            if(numDataInicio == numDataTermino) { // se tiver sido lido 1 par
                dataAtual.setDataInicio(dataInicioAtual);
                dataAtual.setDataTermino(dataTerminoAtual);
                if(dataAtual.getDataInicio() <= dataInicio && dataAtual.getDataTermino() >= dataTermino)
                    it->addDisponibilidade(dataAtual);
            }
        }
    }
    return list;
}
