//
// Created by paulo on 15-Sep-18.
//

#ifndef TRABALHO_1_CLION_TESTE_CIDADE_H
#define TRABALHO_1_CLION_TESTE_CIDADE_H
#include <iostream>
#include "../../Dominios/Cidade.h"
#include "../Teste.h"
#include "Teste_Dominios.h"
#include <stdexcept>

/**
 * @brief Classe que testa a classe Nome.
 * @details
 */
class Teste_Cidade: public Teste_Dominios{
public:
    void mensagemSucesso() override {
        std::cout << "Sucesso Cidade" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Cidade" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;


    Cidade *nome;
    void configurar() override;
    void desconfigurar() override{
        delete nome;
    }

    void casoSucesso() override;
    void casoFalha() override;

};


#endif //TRABALHO_1_CLION_TESTE_CIDADE_H
