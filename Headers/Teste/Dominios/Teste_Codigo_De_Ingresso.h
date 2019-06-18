//
// Created by paulo on 08-Sep-18.
//

#ifndef TRABALHO_1_CLION_TESTE_CODIGO_DE_INGRESSO_H
#define TRABALHO_1_CLION_TESTE_CODIGO_DE_INGRESSO_H
#include <string>
#include <iostream>
#include "../../Dominios/Codigo_De_Ingresso.h"
#include "../Teste.h"
#include "Teste_Dominios.h"

/**
 * @brief Classe que testa a classe Codigo de Ingresso.
 * @details
 */
class Teste_Codigo_De_Ingresso: public Teste_Dominios{
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Codigo de Ingresso" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Codigo de Ingresso" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_CARACTERE_INVALIDO;
    static const std::string VALOR_COMPRIMENTO_INVALIDO;

    Codigo_De_Ingresso *codigoDeIngresso;
    void configurar() override;
    void desconfigurar() override{
        delete codigoDeIngresso;
    }

    void casoSucesso() override;
    void casoFalha() override;
    void casoFalhaCaratereInvalido();
    void casoFalhaComprimentoInvalido();
};
#endif //TRABALHO_1_CLION_TESTE_CODIGO_DE_INGRESSO_H
