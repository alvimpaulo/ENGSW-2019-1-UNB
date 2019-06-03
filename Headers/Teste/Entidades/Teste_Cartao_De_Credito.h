//
// Created by oetch on 16/09/2018.
//

//
#ifndef TRABALHO_1_CLION_TESTE_CARTAO_DE_CREDITO_H
#define TRABALHO_1_CLION_TESTE_CARTAO_DE_CREDITO_H

#include "../Teste.h"
#include "../../Entidades/Cartao_De_Credito.h"
#include "Teste_Entidades.h"

/**
 * @brief Classe que testa a classe Cartao_De_Credito.
 * @details
 */
class Teste_Cartao_De_Credito: public Teste_Entidades{
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Cartao de Credito" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Cartao de Credito" << std::endl;
    }
private:

    Cartao_De_Credito *cartaoDeCredito;
    void configurar() override{
        cartaoDeCredito = new Cartao_De_Credito();
        estado = SUCESSO;
    }
    void desconfigurar() override{
        delete cartaoDeCredito;
    }
    void casoSucesso() override;
};


#endif //TRABALHO_1_CLION_TESTE_CARTAO_DE_CREDITO_H
