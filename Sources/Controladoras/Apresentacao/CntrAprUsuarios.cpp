//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Apresentacao/CntrAprUsuarios.h"
#include "../../../Headers/Entidades/Usuario.h"

void CntrAprUsuarios::cadastrar() {
    Cpf cpf;
    Senha senha;
    Num_Cartao_Credito numCartaoCredito;
    Codigo_De_Seguranca codigoDeSeguranca;
    Data_De_Validade dataDeValidade;

    Usuario usuario;
    Cartao_De_Credito cartaoDeCredito;

    std::string input;

    while (cpf.getCpf() == "000.000.000-00" ||
           senha.getSenha() == "Na0Def" ||
           numCartaoCredito.getNum_Cartao() == "0000000000000000" ||
           codigoDeSeguranca.getCodigoSeguranca() == "000" ||
           dataDeValidade.getData_De_Validade() == "01/00") {
        try {
            std::cout << "Digite o seu cpf : ";
            std::getline(std::cin, input);
            cpf.setCpf(input);

            std::cout << "Digite a sua senha        : ";
            std::getline(std::cin, input);
            senha.setSenha(input);

            std::cout << "Digite seu numero do cartao        : ";
            std::getline(std::cin, input);
            numCartaoCredito.setNum_Cartao(input);

            std::cout << "Digite seu codigo de seguranca        : ";
            std::getline(std::cin, input);
            codigoDeSeguranca.setCodigoSeguranca(input);

            std::cout << "Digite a sua data de validade        : ";
            std::getline(std::cin, input);
            dataDeValidade.setData_De_Validade(input);
        } catch (std::invalid_argument &e) {
            std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
        }
    }

    usuario.setCpf(cpf);
    usuario.setSenha(senha);

    cartaoDeCredito.setCodigoDeSeguranca(codigoDeSeguranca);
    cartaoDeCredito.setDataDeValidade(dataDeValidade);
    cartaoDeCredito.setNumero(numCartaoCredito);

    try {
        cntrServUsuario->cadastrarUsuario(usuario, cartaoDeCredito);
    } catch (std::invalid_argument &e) {
        std::cout << std::endl << "Nao foi possivel cadastrar usuario!" << std::endl;
        return;
    }
}

void CntrAprUsuarios::executar(Usuario& usuario) {
    int escolha;
    bool flag;
    std::string input;
    std::cout << "Sistema de Acomodacao - Servicos do usuario" << std::endl << std::endl;

    std::cout << "1 - Descadastrar usuario." << std::endl;
    std::cout << "2 - Sair." << std::endl;

    std::cout << "Escolha a opcao: ";

    std::getline(std::cin, input);
    escolha = std::stoi(input);

    flag = true;

    while (flag){
        switch (escolha) {
            case OPCAO_DESCADASTRAR_USUARIO:
                descadastrar(usuario);
                flag = false;
                throw std::runtime_error("Usuario descadastrado");
                break;
            case OPCAO_SAIR:
                flag = false;
            default:
                return;
        }
    }
}

void CntrAprUsuarios::setCntrsServUsuarios(InterServUsuarios *cntrsServUsuarios) {
    this->cntrServUsuario = cntrsServUsuarios;
}

CntrAprUsuarios::~CntrAprUsuarios() {
     delete cntrServUsuario;
}

void CntrAprUsuarios::descadastrar(Usuario &usuario) {
    int escolha;
    bool flag;
    std::string input;
    std::cout << "Sistema de Acomodacao - Servicos do usuario" << std::endl << std::endl;

    std::cout << "Deseja descadastrar sua conta?" << std::endl;
    std::cout << "0 - Nao." << std::endl;
    std::cout << "1 - Sim." << std::endl;

    std::cout << "Escolha a opcao: ";

    std::getline(std::cin, input);
    escolha = std::stoi(input);

    flag = true;

    while (flag){
        switch (escolha) {
            case OPCAO_NAO:
                return;
            case OPCAO_SIM:
                try{
                    cntrServUsuario->descadastrarUsuario(usuario);
                    flag = false;
                } catch(std::runtime_error &e){
                    std::cout << std::endl << "Voce nao pode descadastrar enquanto houver evento cadastrado!" << std::endl;
                    throw std::runtime_error("Usuario nao pode ser descadastrado");
                    return;
                }
                break;
            default:break;
        }
    }

    std::cout << "Usuario descadastrado com sucesso" << std::endl;
}

