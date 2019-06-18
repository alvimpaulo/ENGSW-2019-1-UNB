//
// Created by paulo on 15-Sep-18.
//

#ifndef TRABALHO_1_CLION_TESTE_CAPACIDADE_DE_ACOMOCADAO_H
#define TRABALHO_1_CLION_TESTE_CAPACIDADE_DE_ACOMOCADAO_H

#include <iostream>
#include "../Teste.h"
#include "Teste_Dominios.h"
#include "../../Dominios/Disponibilidade.h"
#include <stdexcept>

/**
 * @brief Classe que testa a classe Capacidade_De_Acomodacao.
 * @details
 */
class Teste_Disponibilidade: public Teste_Dominios{

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

    Disponibilidade *disponibilidade;
    void configurar() override ;
    void desconfigurar() override {
        delete disponibilidade;
    }

    void casoSucesso() override ;
    void casoFalha() override ;

};


#endif //TRABALHO_1_CLION_TESTE_CAPACIDADE_DE_ACOMOCADAO_H
