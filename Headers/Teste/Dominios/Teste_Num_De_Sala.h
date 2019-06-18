//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_NUM_DE_SALA_H
#define TRABALHO_1_CLION_TESTE_NUM_DE_SALA_H

#include <string>
#include <iostream>
#include "../../Dominios/Num_De_Sala.h"
#include "../Teste.h"
#include "Teste_Dominios.h"

class Teste_Num_De_Sala : public Teste_Dominios {
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Numero de sala" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Numero de sala" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;

    Num_De_Sala *numDeSala;
    void configurar() override;
    void desconfigurar() override{
        delete numDeSala;
    }

    void casoSucesso() override;
    void casoFalha() override;
    void casoFalhaCaratereInvalido();
    void casoFalhaComprimentoInvalido();

};


#endif //TRABALHO_1_CLION_TESTE_NUM_DE_SALA_H
