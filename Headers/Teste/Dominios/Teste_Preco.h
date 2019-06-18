//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_PRECO_H
#define TRABALHO_1_CLION_TESTE_PRECO_H

#include "../../Dominios/Preco.h"
#include "Teste_Dominios.h"
#include "../Teste.h"
#include "iostream"

class Teste_Preco : public Teste_Dominios {
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Preco" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Preco" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;


    Preco *preco;
    void configurar() override;
    void desconfigurar() override{
        delete preco;
    }

    void casoSucesso() override;
    void casoFalha() override;
};


#endif //TRABALHO_1_CLION_TESTE_PRECO_H
