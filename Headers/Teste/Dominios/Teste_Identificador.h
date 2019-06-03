//
// Created by paulo on 15-Sep-18.
//

#ifndef TRABALHO_1_CLION_TESTE_IDENTIFICADOR_H
#define TRABALHO_1_CLION_TESTE_IDENTIFICADOR_H

#include <iostream>
#include "../../Dominios/Identificador.h"
#include "../Teste.h"
#include "Teste_Dominios.h"
#include <stdexcept>

/**
 * @brief Classe que testa a classe Identificador.
 * @details
 */
class Teste_Identificador: public Teste_Dominios{
public:
    void mensagemSucesso(){
        std::cout << "Sucesso Identificador" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Identificador" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;


    Identificador *identificador;
    void configurar();
    void desconfigurar(){
        delete identificador;
    }

    void casoSucesso();
    void casoFalha();
};


#endif //TRABALHO_1_CLION_TESTE_IDENTIFICADOR_H
