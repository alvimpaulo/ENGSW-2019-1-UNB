//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_CPF_H
#define TRABALHO_1_CLION_TESTE_CPF_H

#include <iostream>
#include "../Teste.h"
#include "Teste_Dominios.h"
#include "../../Dominios/Cpf.h"
#include <stdexcept>


class Teste_Cpf : public Teste_Dominios {

public:
    void mensagemSucesso() override {
        std::cout << "Sucesso Cpf" << std::endl;
    }
    void mensagemFalha() override {
        std::cout << "Falha Cpf" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;

    Cpf *cpf;
    void configurar() override ;
    void desconfigurar() override {
        delete cpf;
    }

    void casoSucesso() override ;
    void casoFalha() override ;


};


#endif //TRABALHO_1_CLION_TESTE_CPF_H
