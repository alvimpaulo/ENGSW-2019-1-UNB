//
// Created by paulo on 14/06/19.
//

#include "../../../Headers/Controladoras/Apresentacao/CntrAprVendas.h"

void CntrAprVendas::executar(Usuario &usuario) {
    int escolha;
    bool flag;
    std::string input;
    std::cout << "Sistema de Venda de Ingressos - Servicos de venda" << std::endl << std::endl;

    std::cout << "1 - Comprar Ingressos." << std::endl;
    std::cout << "2 - Solicitar Informacao de vendas." << std::endl;
    std::cout << "3 - Sair." << std::endl;

    std::cout << "Escolha a opcao: ";

    std::getline(std::cin, input);
    escolha = std::stoi(input);

    flag = true;

    while (flag){
        switch (escolha) {
            case OPCAO_COMPRAR_INGRESSOS:
                comprarIngressos(usuario);
                flag = false;
                break;
            case OPCAO_SOLICITAR_INFORMACAO_VENDAS:
                solicitarInformacaoVendas(usuario);
                flag = false;
                break;
            case OPCAO_SAIR_VENDAS:
                flag = false;
            default:
                break;
        }
    }
}

void CntrAprVendas::setCntrServVendas(InterServVendas *cntrServVendas) {
    this->cntrServVendas = cntrServVendas;
}

void CntrAprVendas::comprarIngressos(const Usuario &usuario) {
    Codigo_De_Apresentacao codigoDeApresentacao;
    int qtdIngresso;
    std::list<std::string> ingressosVendidos;

    std::string input;

    std::cout << "Sistema de Venda de Ingressos - Servicos de venda - Compra de ingressos." << std::endl << std::endl;

    try {
        std::cout << "Digite o codigo da apresentacao desejada: ";
        std::getline(std::cin, input);
        codigoDeApresentacao.setCodigoApresentacao(input);

        std::cout << "Digite a quantidade de ingressos desejada: ";
        std::getline(std::cin, input);
        qtdIngresso = std::stoi(input);

    } catch (std::invalid_argument &e) {
        std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
        return;
    }

    try{
        ingressosVendidos = cntrServVendas->comprarIngresso(usuario, codigoDeApresentacao, qtdIngresso);
    } catch(std::exception &e) {
        std::cout << std::endl << "nao foi possivel realizar a compra" << std::endl;
        return;
    }
    int i = 0;
    for (const auto& codigoIngresso: ingressosVendidos) {
        std::cout << "Codigo de ingresso " << i + 1 << ": " << codigoIngresso << std::endl;
        i++;
    }
    std::cout << "Compra realizada com sucesso" << std::endl;
}

void CntrAprVendas::solicitarInformacaoVendas(const Usuario &usuario) {
    Codigo_De_Evento codigoDeEvento;
    std::list< std::pair<std::string, std::list<std::string> > > apresentacoesVsCpfs;
    std::vector<Cpf> cpfIngressosVendidos;


    std::string input;

    std::cout << "Sistema de Venda de Ingressos - Servicos de venda - Solicitacao de informacao." << std::endl << std::endl;

    try {
        std::cout << "Digite o codigo do evento desejado: ";
        std::getline(std::cin, input);
        codigoDeEvento.setCodigoEvento(input);

    } catch (std::invalid_argument &e) {
        std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
        return;
    }

    try{
        apresentacoesVsCpfs = cntrServVendas->solicitarInformacaoDeVendas(codigoDeEvento, usuario);
        for (auto const& i: apresentacoesVsCpfs){
            std::cout << "Apresentacao: " << i.first << std::endl;
            std::cout << "Numero de ingressos vendidos: " << i.second.size() << std::endl;
            for(auto const& j: i.second){
                std::cout << "Cpf do comprador: " << j << std::endl;
            }

        }
    } catch(std::exception &e) {
        std::cout << std::endl << "nao foi possível acessar as informacoes deste evento" << std::endl;
        return;
    }
}
