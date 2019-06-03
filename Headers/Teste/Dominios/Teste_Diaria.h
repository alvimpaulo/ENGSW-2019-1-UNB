//
// Created by oetch on 08/09/2018.
//

#ifndef TRABALHO_1_CLION_TESTE_DIARIA_H
#define TRABALHO_1_CLION_TESTE_DIARIA_H


#include <string>
#include "../../Dominios/Diaria.h"
#include "../Teste.h"
#include "Teste_Dominios.h"

/**
 * @brief Classe que testa a classe Diaria.
 * @details
 */
class Teste_Diaria: public Teste_Dominios{
public:
    void mensagemSucesso(){
        std::cout << "Sucesso Diaria" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Diaria" << std::endl;
    }
protected:
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_CARACTERE_INVALIDO;
    static const std::string VALOR_INTERVALO_INVALIDO;

    Diaria *diaria;

    void configurar();
    void desconfigurar(){
        delete diaria;
    }

    void casoSucesso();
    void casoFalha();
    void casoFalhaCaratereInvalido();
    void casoFalhaIntervaloInvalido();
};

#endif //TRABALHO_1_CLION_TESTE_DIARIA_H
