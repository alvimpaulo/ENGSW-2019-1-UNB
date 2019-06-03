//
// Created by oetch on 16/09/2018.
//

//
#ifndef TRABALHO_1_CLION_TESTE_ACOMODACAO_H
#define TRABALHO_1_CLION_TESTE_ACOMODACAO_H

#include <iostream>
#include <stdexcept>
#include <exception>
#include "../../Entidades/Acomodacao.h"
#include "../Teste.h"
#include "Teste_Entidades.h"

/**
 * @brief Classe que testa a classe Acomodacao.
 * @details
 */
class Teste_Acomodacao: public Teste_Entidades{
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Acomodacao" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Acomodacao" << std::endl;
    }
private:

    Acomodacao *acomodacao;

    void configurar() override;
    void desconfigurar() override{
        delete acomodacao;
    }
    void casoSucesso() override;

};


#endif //TRABALHO_1_CLION_TESTE_ACOMODACAO_H
