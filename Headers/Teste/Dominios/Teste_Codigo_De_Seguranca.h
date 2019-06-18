//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_CODIGO_DE_SEGURANCA_H
#define TRABALHO_1_CLION_TESTE_CODIGO_DE_SEGURANCA_H

#include <iostream>
#include "../Teste.h"
#include "Teste_Dominios.h"
#include "../../Dominios/Codigo_De_Seguranca.h"
#include <stdexcept>

class Teste_Codigo_De_Seguranca: public Teste_Dominios{
public:
    void mensagemSucesso() override {
        std::cout << "Sucesso Disponibilidade" << std::endl;
    }
    void mensagemFalha() override {
        std::cout << "Falha Disponibilidade" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;

    Codigo_De_Seguranca *codigoDeSeguranca;
    void configurar() override ;
    void desconfigurar() override {
        delete codigoDeSeguranca;
    }

    void casoSucesso() override ;
    void casoFalha() override ;


};


#endif //TRABALHO_1_CLION_TESTE_CODIGO_DE_SEGURANCA_H
