//
// Created by paulo on 16-Nov-18.
//

#include <iostream>
#include "../../../Headers/Controladoras/Apresentacao/CntrAprAutenticacao.h"

void CntrAprAutenticacao::autenticar(Usuario& usuario){
    Cpf cpf;
    Senha senha;
    std::string input;
    std::cout << "Autenticacao de usuário" << std::endl;

    try{
        std::cout << "Digite o seu cpf: ";
        std::getline(std::cin, input);
        cpf.setCpf(input);
        std::cout << "Digite a sua senha        : ";
        std::getline(std::cin, input);
        senha.setSenha(input);
    } catch(std::invalid_argument &e){
        throw std::invalid_argument("Nao foi possivel efetuar o login, pois os dados foram inseridos fora do formato");
    }

    try{
        Usuario usuarioTeste;
        usuarioTeste.setCpf(cpf);
        usuarioTeste.setSenha(senha);
        cntrServAutenticacao->autenticar(usuarioTeste);
    } catch(std::invalid_argument &e){
        throw std::invalid_argument("Nao foi possivel efetuar o login, verifique se os campos foram preenchidos adequadamente!");
    }

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
