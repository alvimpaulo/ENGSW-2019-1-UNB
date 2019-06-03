//
// Created by paulo on 13-Sep-18.
//

#ifndef TRABALHO_1_CLION_TESTE_BANCO_H
#define TRABALHO_1_CLION_TESTE_BANCO_H

#include <iostream>
#include "../../Dominios/Banco.h"
#include "../Teste.h"
#include "Teste_Dominios.h"
#include <stdexcept>

/**
 * @brief Classe que testa a classe Banco.
 * @details
 */
class Teste_Banco: public Teste_Dominios{
public:
    void mensagemSucesso(){
        std::cout << "Sucesso Banco" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Banco" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;

    Banco *banco;
    void configurar() override;
    void desconfigurar() override{
        delete banco;
    }

    void casoSucesso() override;
    void casoFalha() override;
};


#endif //TRABALHO_1_CLION_TESTE_BANCO_H
