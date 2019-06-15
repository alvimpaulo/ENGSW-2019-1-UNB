//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Servico/CntrServAcomodacao.h"

std::list<Acomodacao> CntrServAcomodacao::pesquisar(const Data &dataInicio, const Data &dataTermino,
                                                     const Num_De_Sala &capacidadeDeAcomodacao,
                                                     const Cidade &cidade, const Estado &estado) {
    ComandoPesquisarAcomodacao sqlPesquisar(dataInicio, dataTermino, capacidadeDeAcomodacao, cidade, estado);
    sqlPesquisar.executar();
    std::list<Acomodacao> resultadoPesquisa = sqlPesquisar.getResultado(dataInicio, dataTermino);
    return resultadoPesquisa;

}

void CntrServAcomodacao::cadastrar(const Identificador &identificadorAcomodacao, const Tipo_Acomodacao &tipoAcomodacao,
                                    const Num_De_Sala &capacidadeDeAcomodacao, const Preco &diaria,
                                    const Cidade &cidade, const Estado &estado,
                                    const Identificador& identificadorUsuario) {
    ComandoChecarContaCorrente sqlChecarConta(identificadorUsuario);
    bool existeConta = sqlChecarConta.existeConta();
    if(existeConta) {
        ComandoCadastrarAcomodacao sqlCadastrar(identificadorAcomodacao, tipoAcomodacao, capacidadeDeAcomodacao, diaria,
                                                cidade, estado, identificadorUsuario);
        sqlCadastrar.executar();
    } else{
        throw std::invalid_argument("nao foi possivel cadastrar acomodacao pois nao existe conta para esse usuario");
    }

}

void CntrServAcomodacao::cadastrarDisponibilidade(const Identificador &identificadorAcomodacao, const Data &dataInicio,
                                                   const Data &dataTermino, const Identificador &identificadorUsuario) {
    ComandoCadastrarDisponibilidadeAcomodacao sqlCadastrarDisponibilidade(identificadorAcomodacao, dataInicio, dataTermino, identificadorUsuario);
    //sqlCadastrarDisponibilidade.cadastrar();
    sqlCadastrarDisponibilidade.cadastrarDisponibilidadeAcomodacao(identificadorAcomodacao, dataInicio, dataTermino, identificadorUsuario);

}

void CntrServAcomodacao::descadastrar(const Identificador &identificadorAcomodacao, const Identificador& identificadorUsuario) {

    try {
        ComandoDescadastrarAcomodacao sqlDescadastrar(identificadorAcomodacao, identificadorUsuario);
        sqlDescadastrar.executar();
    } catch (std::exception &exception){
        std::cout << exception.what() << std::endl;
    }

    std::cout << "Acomodacao descadastrada com sucesso" << std::endl;
}

void CntrServAcomodacao::descadastrarDisponibilidade(const Identificador &identificadorAcomodacao,
                                                      const Identificador &identificadorUsuario,
                                                      const Data& dataInicio,
                                                      const Data& dataTermino) {

    try {
        ComandoDescadastrarDisponibilidade sqlDescadastrarDisponibilidade(identificadorAcomodacao, identificadorUsuario,
                                                                          dataInicio, dataTermino);
        sqlDescadastrarDisponibilidade.executar();
    } catch (std::exception &exception){
        std::cout << exception.what() << std::endl;
    }

    std::cout << "Disponibilidade da acomodacao descadastrada com sucesso" << std::endl;
}
