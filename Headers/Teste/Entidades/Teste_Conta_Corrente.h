//
// Created by oetch on 16/09/2018.
//

//
#ifndef TRABALHO_1_CLION_TESTE_CONTA_CORRENTE_H
#define TRABALHO_1_CLION_TESTE_CONTA_CORRENTE_H

#include <iostream>
#include "../Teste.h"
#include "../../Entidades/Conta_Corrente.h"
#include "Teste_Entidades.h"

/**
 * @brief Classe que testa a classe Conta_Corrente.
 * @details
 */
class Teste_Conta_Corrente: public Teste_Entidades{
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Conta Corrente" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Conta Corrente" << std::endl;
    }

private:

    Conta_Corrente *contaCorrente;

    void configurar() override{
        contaCorrente = new Conta_Corrente();
        estado = SUCESSO;
    }
    void desconfigurar() override{
        delete contaCorrente;
    }
    void casoSucesso() override;
    void casoFalha(){}
};


#endif //TRABALHO_1_CLION_TESTE_CONTA_CORRENTE_H
