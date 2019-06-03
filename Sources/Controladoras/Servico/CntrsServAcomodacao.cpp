//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Servico/CntrsServAcomodacao.h"

std::list<Acomodacao> CntrsServAcomodacao::pesquisar(const Data &dataInicio, const Data &dataTermino,
                                                     const Capacidade_De_Acomodacao &capacidadeDeAcomodacao,
                                                     const Nome &cidade, const Estado &estado) {
    ComandoPesquisarAcomodacao sqlPesquisar(dataInicio, dataTermino, capacidadeDeAcomodacao, cidade, estado);
    sqlPesquisar.executar();
    std::list<Acomodacao> resultadoPesquisa = sqlPesquisar.getResultado(dataInicio, dataTermino);
    return resultadoPesquisa;

}

void CntrsServAcomodacao::cadastrar(const Identificador &identificadorAcomodacao, const Tipo_Acomodacao &tipoAcomodacao,
                                    const Capacidade_De_Acomodacao &capacidadeDeAcomodacao, const Diaria &diaria,
                                    const Nome &cidade, const Estado &estado,
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

void CntrsServAcomodacao::cadastrarDisponibilidade(const Identificador &identificadorAcomodacao, const Data &dataInicio,
                                                   const Data &dataTermino, const Identificador &identificadorUsuario) {
    ComandoCadastrarDisponibilidadeAcomodacao sqlCadastrarDisponibilidade(identificadorAcomodacao, dataInicio, dataTermino, identificadorUsuario);
    //sqlCadastrarDisponibilidade.cadastrar();
    sqlCadastrarDisponibilidade.cadastrarDisponibilidadeAcomodacao(identificadorAcomodacao, dataInicio, dataTermino, identificadorUsuario);

}

void CntrsServAcomodacao::descadastrar(const Identificador &identificadorAcomodacao, const Identificador& identificadorUsuario) {

    try {
        ComandoDescadastrarAcomodacao sqlDescadastrar(identificadorAcomodacao, identificadorUsuario);
        sqlDescadastrar.executar();
    } catch (std::exception &exception){
        std::cout << exception.what() << std::endl;
    }

    std::cout << "Acomodacao descadastrada com sucesso" << std::endl;
}

void CntrsServAcomodacao::descadastrarDisponibilidade(const Identificador &identificadorAcomodacao,
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
