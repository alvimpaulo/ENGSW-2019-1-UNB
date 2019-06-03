//
// Created by paulo on 15-Sep-18.
//

#ifndef TRABALHO_1_CLION_TESTE_NUM_CARTAO_H
#define TRABALHO_1_CLION_TESTE_NUM_CARTAO_H

#include <iostream>
#include "../../Dominios/Num_Cartao_Credito.h"
#include "../Teste.h"
#include "Teste_Dominios.h"
#include <stdexcept>

/**
 * @brief Classe que testa a classe Num_Cartao_Credito.
 * @details
 */
class Teste_Num_Cartao: public Teste_Dominios{
public:
    void mensagemSucesso(){
        std::cout << "Sucesso Numero do Cartao" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Numero do Cartao" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;


    Num_Cartao_Credito *numCartao;
    void configurar();
    void desconfigurar(){
        delete numCartao;
    }

    void casoSucesso();
    void casoFalha();
};


#endif //TRABALHO_1_CLION_TESTE_NUM_CARTAO_H
