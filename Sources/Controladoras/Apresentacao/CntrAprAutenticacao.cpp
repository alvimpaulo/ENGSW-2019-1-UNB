//
// Created by paulo on 16-Nov-18.
//

#include <iostream>
#include "../../../Headers/Controladoras/Apresentacao/CntrAprAutenticacao.h"
#include "../../../Headers/Dominios/Senha.h"

void CntrAprAutenticacao::autenticar(Identificador &identificador){
    Identificador   id;
    Senha           senha;
    std::string input;
    std::cout << "Autenticacao de usuário" << std::endl;

    try{
        std::cout << "Digite o seu identificador: ";
        std::getline(std::cin, input);
        id.setIdentificador(input);
        std::cout << "Digite a sua senha        : ";
        std::getline(std::cin, input);
        senha.setSenha(input);
    } catch(std::invalid_argument &e){
        throw std::invalid_argument("Nao foi possivel efetuar p login, pois os dados foram inseridos fora do formato");
    }

    try{
        cntrServAutenticacao->autenticar(id, senha);
    } catch(std::invalid_argument &e){
        throw std::invalid_argument("Nao foi possivel efetuar o login, verifique se os campos foram preenchidos adequadamente!");
    }

    identificador = id;

    std::cout << std::endl << "Login efetuado com sucesso!" << std::endl;
}

void CntrAprAutenticacao::setCntrsServAutenticacao(InterServAutenticacao *cntrServAutenticacao){
    this->cntrServAutenticacao = cntrServAutenticacao;
}

CntrAprAutenticacao::CntrAprAutenticacao() {
    cntrServAutenticacao = nullptr;
}

CntrAprAutenticacao::~CntrAprAutenticacao() {
    delete cntrServAutenticacao;
}
