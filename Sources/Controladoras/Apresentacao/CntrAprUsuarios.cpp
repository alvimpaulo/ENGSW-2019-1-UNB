//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Apresentacao/CntrAprUsuarios.h"
#include "../../../Headers/Dominios/Senha.h"
#include "../../../Headers/Dominios/Nome.h"
#include "../../../Headers/Entidades/Usuario.h"
#include "../../../Headers/ComandoSQL/ComandoDescadastrarCartaoCredito.h"

void CntrAprUsuarios::cadastrar() {
    Identificador identificador;
    Nome nome;
    Senha senha;
    Usuario usuario;
    std::string input;

    while(nome.getNome() == "NomeNaoDefinido" || senha.getSenha() == "NaoDef1!" || identificador.getIdentificador() == "abcde" ) {
        try {
            std::cout << "Digite o seu nome         : ";
            std::getline(std::cin, input);
            nome.setNome(input);
            std::cout << "Digite o seu identificador: ";
            std::getline(std::cin, input);
            identificador.setIdentificador(input);
            std::cout << "Digite a sua senha        : ";
            std::getline(std::cin, input);
            senha.setSenha(input);
        } catch (std::invalid_argument &e) {
            std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
        }
    }

    usuario.setNome(nome);
    usuario.setIdentificador(identificador);
    usuario.setSenha(senha);

    try{
        cntrServUsuario->cadastrarUsuario(nome, identificador, senha);
    } catch(std::invalid_argument &e){
        std::cout << std::endl << "Nao foi possivel cadastras usuario!" << std::endl;
        return;
    }

    std::cout << std::endl << "Usuario cadastrado com sucesso!" << std::endl;
}

void CntrAprUsuarios::executar(Identificador &identificador) {
    int escolha;
    bool flag;
    std::string input;
    std::cout << "Sistema de Acomodacao - Servicos do usuario" << std::endl << std::endl;

    std::cout << "1 - Editar usuario." << std::endl;
    std::cout << "2 - Descadastrar usuario." << std::endl;
    std::cout << "3 - Cadastrar cartao de credito." << std::endl;
    std::cout << "4 - Descadastrar cartao de credito." << std::endl;
    std::cout << "5 - Cadastrar conta corrente." << std::endl;
    std::cout << "6 - Descadastrar conta corrente." << std::endl;
    std::cout << "7 - Sair." << std::endl;

    std::cout << "Escolha a opcao: ";

    std::getline(std::cin, input);
    escolha = std::stoi(input);

    flag = true;

    while (flag){
        switch (escolha) {
            case OPCAO_EDITAR_USUARIO:
                editar(identificador);
                flag = false;
                break;
            case OPCAO_DESCADASTRAR_USUARIO:
                descadastrar(identificador);
                flag = false;
                throw std::runtime_error("Usuario descadastrado");
                break;
            case OPCAO_CADASTRAR_CARTAO:
                cadastrarCartaoCredito(identificador);
                flag = false;
                break;
            case OPCAO_DESCADASTRAR_CARTAO:
                descadastrarCartaoCredito(identificador);
                flag = false;
                break;
            case OPCAO_CADASTRAR_CONTA:
                cadastrarContaCorrente(identificador);
                flag = false;
                break;
            case OPCAO_DESCADASTRAR_CONTA:
                descadastrarContaCorrente(identificador);
                flag = false;
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

void CntrAprUsuarios::editar(Identificador &identificador) {

    Nome nome;
    Senha senha;
    Usuario usuario;
    std::string input;


    while(nome.getNome() == "NomeNaoDefinido" || senha.getSenha() == "NaoDef1!" || identificador.getIdentificador() == "abcde") {
        try {
            std::cout << "Digite o seu nome         : ";
            std::getline(std::cin, input);
            nome.setNome(input);

            std::cout << "Digite a sua senha        : ";
            std::getline(std::cin, input);
            senha.setSenha(input);
        } catch (std::invalid_argument &e) {
            std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
        }
    }

    try{
        cntrServUsuario->editarUsuario(nome, senha, identificador);
    } catch(std::invalid_argument &e){
        std::cout << std::endl << "Nao foi possivel editar usuario!" << std::endl;
        return;
    }

    std::cout << std::endl << "Usuario editado com sucesso!" << std::endl;
}

void CntrAprUsuarios::descadastrar(Identificador &identificador) {
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
                    cntrServUsuario->descadastrarUsuario(identificador);
                    flag = false;
                } catch(std::runtime_error &e){
                    std::cout << std::endl << "Voce nao pode descadastrar enquanto houver pendencias!" << std::endl;
                    return;
                }
                break;
            default:break;
        }
    }

    std::cout << "Usuario descadastrado com sucesso" << std::endl;
}
void CntrAprUsuarios::cadastrarContaCorrente(Identificador &identificador) {
    Num_Conta_Corrente numContaCorrente;
    Agencia agencia;
    Banco banco;

    std::string input;

    try {
        std::cout << "Digite o número da sua conta corrente: ";
        std::getline(std::cin, input);
        numContaCorrente.setNum_Conta_Corrente(input);
        std::cout << "Digite o número da sua agencia: ";
        std::getline(std::cin, input);
        agencia.setAgenciaNum(input);
        std::cout << "Digite o número de seu banco: ";
        std::getline(std::cin, input);
        banco.setBancoNum(input);
        cntrServUsuario->cadastrarContaCorrente(identificador, numContaCorrente, agencia, banco);
    } catch (std::exception &e){
        return;
    }



    std::cout << "Conta corrente cadastrada com sucesso" << std::endl;
}

void CntrAprUsuarios::cadastrarCartaoCredito(Identificador &identificador) {
    Num_Cartao_Credito numCartaoCredito;
    Data_De_Validade dataDeValidade;

    std::string input;
    try {
        std::cout << "Digite o número de seu cartao de credito: ";
        std::getline(std::cin, input);
        numCartaoCredito.setNum_Cartao(input);
        std::cout << "Digite o número a data de validade de seu cartao de credito: ";
        std::getline(std::cin, input);
        dataDeValidade.setData_De_Validade(input);
        cntrServUsuario->cadastrarCartaoCredito(identificador, numCartaoCredito, dataDeValidade);
    } catch (std::exception &e){
        return;
    }



    std::cout << "Cartao de credito cadastrado com sucesso" << std::endl;
}

void CntrAprUsuarios::descadastrarContaCorrente(Identificador &identificador) {
    Num_Conta_Corrente numContaCorrente;

    std::string input;

    try {
        std::cout << "DIgite o número da sua conta corrente: ";
        std::getline(std::cin, input);
        numContaCorrente.setNum_Conta_Corrente(input);
        cntrServUsuario->descadastrarContaCorrente(numContaCorrente);
    } catch (std::exception &e){
        return;
    }



    std::cout << "Conta corrente descadastrada com sucesso" << std::endl;
}

void CntrAprUsuarios::descadastrarCartaoCredito(Identificador &identificador) {
    Num_Cartao_Credito numCartaoCredito;

    std::string input;

    try {
        std::cout << "DIgite o número do seu cartao de credito: ";
        std::getline(std::cin, input);
        numCartaoCredito.setNum_Cartao(input);
        cntrServUsuario->descadastrarCartaoCredito(numCartaoCredito);
    } catch (std::exception &e){
        return;
    }



    std::cout << "Cartao de credito descadastrado com sucesso" << std::endl;
}

