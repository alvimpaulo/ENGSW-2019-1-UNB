//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Apresentacao/CntrAprUsuarios.h"
#include "../../../Headers/Entidades/Usuario.h"
#include "../../../Headers/ComandoSQL/ComandoDescadastrarCartaoCredito.h"

void CntrAprUsuarios::cadastrar() {
    Cpf cpf;
    Senha senha;
    Usuario usuario;
    std::string input;

    while(cpf.getCpf() == "000.000.000-00" || senha.getSenha() == "NaoDef1!") {
        try {
            std::cout << "Digite o seu cpf : ";
            std::getline(std::cin, input);
            cpf.setCpf(input);
            std::cout << "Digite a sua senha        : ";
            std::getline(std::cin, input);
            senha.setSenha(input);
        } catch (std::invalid_argument &e) {
            std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
        }
    }

    usuario.setCpf(cpf);
    usuario.setSenha(senha);

    try{
        cntrServUsuario->cadastrarUsuario(cpf, senha);
    } catch(std::invalid_argument &e){
        std::cout << std::endl << "Nao foi possivel cadastrar usuario!" << std::endl;
        return;
    }

    std::cout << std::endl << "Usuario cadastrado com sucesso!" << std::endl;
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
                    return;
                }
                break;
            default:break;
        }
    }

    std::cout << "Usuario descadastrado com sucesso" << std::endl;
}

