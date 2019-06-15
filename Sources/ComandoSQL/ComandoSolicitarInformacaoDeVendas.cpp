//
// Created by paulo on 14/06/19.
//

#include "../../Headers/ComandoSQL/ComandoSolicitarInformacaoDeVendas.h"
#include "list"

ComandoSolicitarInformacaoDeVendas::ComandoSolicitarInformacaoDeVendas(const Codigo_De_Evento &codigoDeEvento) {
    listaResultado.clear();
    comandoSQL = "SELECT Usuario, Apresentacao FROM Ingressos WHERE Apresentacao IN (SELECT Codigo FROM Aprensentacoes WHERE Evento = ";
    comandoSQL += "'" + codigoDeEvento.getCodigoEvento() + "'";
    comandoSQL += ")";

}

std::list<Cpf> ComandoSolicitarInformacaoDeVendas::getCpfs() {
   std::list<Cpf> listaCpfs;
   Cpf cpfAtual;
   std::map<std::string, std::string> apresentacaoIngressoMap;

    if(listaResultado.empty()){
        throw std::runtime_error("Pesquisa vazia");
    }

    while(!listaResultado.empty()){
        std::string cpfAtualString;
        std::string apresentacaoAtualString;
        if(listaResultado.front().getNomeColuna() == "Usuario"){
        }
        cpfAtualString = listaResultado.front().getValorColuna();
        cpfAtual.setCpf(cpfAtualString);
        listaCpfs.push_back(cpfAtual);
        listaResultado.pop_front();
    }

    return listaCpfs;
}
