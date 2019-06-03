//
// Created by paulo on 15-Sep-18.
//

#ifndef TRABALHO_1_CLION_TESTE_CAPACIDADE_DE_ACOMOCADAO_H
#define TRABALHO_1_CLION_TESTE_CAPACIDADE_DE_ACOMOCADAO_H

#include <iostream>
#include "../../Dominios/Capacidade_De_Acomodacao.h"
#include "../Teste.h"
#include "Teste_Dominios.h"
#include <stdexcept>

/**
 * @brief Classe que testa a classe Capacidade_De_Acomodacao.
 * @details
 */
class Teste_Capacidade_De_Acomodacao: public Teste_Dominios{

public:
    void mensagemSucesso(){
        std::cout << "Sucesso Capacidade de Acomodacao" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Capacidade de Acomodacao" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;

    Capacidade_De_Acomodacao *capacidade;
    void configurar();
    void desconfigurar(){
        delete capacidade;
    }

    void casoSucesso();
    void casoFalha();

};


#endif //TRABALHO_1_CLION_TESTE_CAPACIDADE_DE_ACOMOCADAO_H
