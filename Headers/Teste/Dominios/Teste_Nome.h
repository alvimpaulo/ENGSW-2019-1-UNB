//
// Created by paulo on 15-Sep-18.
//

#ifndef TRABALHO_1_CLION_TESTE_NOME_H
#define TRABALHO_1_CLION_TESTE_NOME_H
#include <iostream>
#include "../../Dominios/Cidade.h"
#include "../Teste.h"
#include "Teste_Dominios.h"
#include <stdexcept>

/**
 * @brief Classe que testa a classe Nome.
 * @details
 */
class Teste_Nome: public Teste_Dominios{
public:
    void mensagemSucesso(){
        std::cout << "Sucesso Cidade" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Cidade" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;


    Cidade *nome;
    void configurar();
    void desconfigurar(){
        delete nome;
    }

    void casoSucesso();
    void casoFalha();

};


#endif //TRABALHO_1_CLION_TESTE_NOME_H
