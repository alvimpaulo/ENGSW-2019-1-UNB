//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_CODIGO_DE_APRESENTACAO_H
#define TRABALHO_1_CLION_TESTE_CODIGO_DE_APRESENTACAO_H

#include <string>
#include <iostream>
#include "../../Dominios/Codigo_De_Apresentacao.h"
#include "../Teste.h"
#include "Teste_Dominios.h"

/**
 * @brief Classe que testa a classe Codigo_De_Apresentacao .
 * @details
 */
class Teste_Codigo_De_Apresentacao: public Teste_Dominios{
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Codigo de Apresentacao" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha codigo de Apresentacao" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_CARACTERE_INVALIDO;
    static const std::string VALOR_COMPRIMENTO_INVALIDO;

    Codigo_De_Apresentacao *codigoDeApresentacao;
    void configurar() override;
    void desconfigurar() override{
        delete codigoDeApresentacao;
    }

    void casoSucesso() override;
    void casoFalha() override;
    void casoFalhaCaratereInvalido();
    void casoFalhaComprimentoInvalido();
};


#endif //TRABALHO_1_CLION_TESTE_CODIGO_DE_APRESENTACAO_H
