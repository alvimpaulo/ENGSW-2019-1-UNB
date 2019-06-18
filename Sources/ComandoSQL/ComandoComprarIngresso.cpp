//
// Created by paulo on 15/06/19.
//

#include "../../Headers/ComandoSQL/ComandoComprarIngresso.h"
#include "ios"
#include "iomanip"
#include "sstream"

ComandoComprarIngresso::ComandoComprarIngresso() {
    listaResultado.clear();
}

std::string ComandoComprarIngresso::getLastIngresso() {
    listaResultado.clear();
    std::string valorAtual;
    std::ostringstream valorAtualString;
    comandoSQL = "SELECT MAX(Codigo) FROM Ingressos";
    this->executar();

    if(listaResultado.empty()){
        throw std::runtime_error("Pesquisa vazia");
    } else{
        while(!listaResultado.empty()){
            valorAtual =listaResultado.front().getValorColuna();
            listaResultado.pop_front();
        }
        return valorAtual;
    }
}

std::list<std::string> ComandoComprarIngresso::comprarIngresso(const Usuario &usuario, int qtdIngresso,
                                                               const Codigo_De_Apresentacao &codigoDeApresentacao) {

    std::string valorAtual = this->getLastIngresso();
    listaResultado.clear();
    std::ostringstream valorAtualStringStream;
    std::list<std::string> codigosIngressos;

    int valorAtualInt;
    if(valorAtual=="NULL"){
        valorAtualInt = 0;
    } else{
        valorAtualInt = std::stoi(valorAtual);
    }


    for (int i = 0; i < qtdIngresso; ++i) {
        valorAtualInt++;
        valorAtualStringStream << std::internal << std::setw(5) << std::setfill('0') << valorAtualInt;
        comandoSQL = "INSERT INTO Ingressos (\n"
                     "                          Codigo,\n"
                     "                          Usuario,\n"
                     "                          Apresentacao\n"
                     "                      )\n"
                     "                      VALUES (\n"
                     "                          \"" + valorAtualStringStream.str() + "\",\n"
                     "                          \"" + usuario.getCpf().getCpf() + "\",\n"
                     "                          \"" + codigoDeApresentacao.getCodigoApresentacao() + "\"\n"
                     "                      );";
        this->executar();
        codigosIngressos.push_back(valorAtualStringStream.str());
        valorAtualStringStream.str("");
        valorAtualStringStream.clear();
    }

    listaResultado.clear();

    comandoSQL = "SELECT Disponibilidade\n"
                 "  FROM Apresentacoes\n"
                 " WHERE Codigo = \"" + codigoDeApresentacao.getCodigoApresentacao() + "\";";
    this->executar();

    if(listaResultado.empty()){
        throw std::runtime_error("Pesquisa vazia");
    } else{
        while(!listaResultado.empty()){
            valorAtual =listaResultado.front().getValorColuna();
            listaResultado.pop_front();
        }

        valorAtualInt = std::stoi(valorAtual);
        valorAtualInt = valorAtualInt - qtdIngresso;

        listaResultado.clear();

        comandoSQL = "UPDATE Apresentacoes\n"
                     "   SET Disponibilidade = " + std::to_string(valorAtualInt) + "\n"
                     " WHERE Codigo = \"" + codigoDeApresentacao.getCodigoApresentacao() + "\";";
        this->executar();

    }

    return codigosIngressos;

}
