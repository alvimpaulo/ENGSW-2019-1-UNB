//
// Created by paulo on 14/06/19.
//

#include "../../Headers/ComandoSQL/ComandoSolicitarInformacaoDeVendas.h"
#include "list"

ComandoSolicitarInformacaoDeVendas::ComandoSolicitarInformacaoDeVendas(const Codigo_De_Evento &codigoDeEvento,
                                                                       const Usuario &usuario) {
    listaResultado.clear();
    comandoSQL = "SELECT Usuario,\n"
                 "       Apresentacao\n"
                 "  FROM Ingressos\n"
                 " WHERE Apresentacao IN (\n"
                 "           SELECT Codigo\n"
                 "             FROM Apresentacoes\n"
                 "            WHERE Evento IN (\n"
                 "                      SELECT Codigo\n"
                 "                        FROM Eventos\n"
                 "                       WHERE Codigo = '" + codigoDeEvento.getCodigoEvento() + "' AND \n"
               "                             Usuario = '" + usuario.getCpf().getCpf() + "'\n"
                 "                  )\n"
                 "       )";

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

std::list< std::pair<std::string, std::list<std::string> > >
ComandoSolicitarInformacaoDeVendas::getApresentacaoVsCpf(const Codigo_De_Evento &codigoDeEvento,
                                                         const Usuario &usuario) {
    listaResultado.clear();
    std::list<std::string> codigoApresentacoes
    std::list<std::string> cpfsDosIngressos;
    std::list<std::pair<std::string, std::list<std::string> > > apresentacaoVsCpf;
    comandoSQL = "SELECT DISTINCT Apresentacao\n"
                 "  FROM Ingressos\n"
                 " WHERE Apresentacao IN (\n"
                 "           SELECT Codigo\n"
                 "             FROM Apresentacoes\n"
                 "            WHERE Evento IN (\n"
                 "                      SELECT Codigo\n"
                 "                        FROM Eventos\n"
                 "                       WHERE Codigo = '" + codigoDeEvento.getCodigoEvento() + "' AND \n"
                "                            Usuario = '" + usuario.getCpf().getCpf() + "'\n"
                 "                  )\n"
                 "       );";
    this->executar();

    while (!listaResultado.empty()){
        codigoApresentacoes.push_back(listaResultado.front().getValorColuna());
        listaResultado.pop_front();
    }

    for(auto const& i: codigoApresentacoes){
        listaResultado.clear();
        comandoSQL = "SELECT DISTINCT Usuario\n"
                     "  FROM Ingressos\n"
                     " WHERE Apresentacao = '" + i + "'";
        this->executar();
        while (!listaResultado.empty()){
            cpfsDosIngressos.push_back(listaResultado.front().getValorColuna());
            listaResultado.pop_front();
        }
        apresentacaoVsCpf.emplace_back(i, cpfsDosIngressos);

        cpfsDosIngressos.clear();
    }

    return apresentacaoVsCpf;
}
