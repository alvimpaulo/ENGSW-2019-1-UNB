//
// Created by paulo on 16-Sep-18.
//

#ifndef TRABALHO_1_CLION_TESTE_NUM_CONTA_CORRENTE_H
#define TRABALHO_1_CLION_TESTE_NUM_CONTA_CORRENTE_H

#include <iostream>
#include "../../Dominios/Num_Conta_Corrente.h"
#include "../Teste.h"
#include "Teste_Dominios.h"
#include <stdexcept>

/**
 * @brief Classe que testa a classe Num_Conta_Corrente.
 * @details
 */
 class Teste_Num_Conta_Corrente: public Teste_Dominios{
public:
    void mensagemSucesso(){
        std::cout << "Sucesso Numero da Conta Corrente" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Numero da Conta Corrente" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;


    Num_Conta_Corrente *numContaCorrente;
    void configurar();
    void desconfigurar(){
        delete numContaCorrente;
    }

    void casoSucesso();
    void casoFalha();
};


#endif //TRABALHO_1_CLION_TESTE_NUM_CONTA_CORRENTE_H
