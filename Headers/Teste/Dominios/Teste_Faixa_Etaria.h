//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_FAIXA_ETARIA_H
#define TRABALHO_1_CLION_TESTE_FAIXA_ETARIA_H

#include <iostream>
#include "../Teste.h"
#include "Teste_Dominios.h"
#include "../../Dominios/Faixa_Etaria.h"
#include <stdexcept>

class Teste_Faixa_Etaria : public Teste_Dominios {
public:
    void mensagemSucesso() override {
        std::cout << "Sucesso Faixa etaria" << std::endl;
    }
    void mensagemFalha() override {
        std::cout << "Falha Faixa etaria" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;

    Faixa_Etaria *faixaEtaria;
    void configurar() override ;
    void desconfigurar() override {
        delete faixaEtaria;
    }

    void casoSucesso() override ;
    void casoFalha() override ;
};


#endif //TRABALHO_1_CLION_TESTE_FAIXA_ETARIA_H
