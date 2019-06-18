//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_INGRESSO_H
#define TRABALHO_1_CLION_TESTE_INGRESSO_H

#include <iostream>
#include "../Teste.h"
#include "../../Entidades/Ingresso.h"
#include "Teste_Entidades.h"

class Teste_Ingresso: public Teste_Entidades {
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Ingresso" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Ingresso" << std::endl;
    }
    int rodar() override;
private:

    Ingresso *ingresso;
    void configurar() override{
        ingresso = new Ingresso();
        estado = SUCESSO;
    }
    void desconfigurar() override{
        delete ingresso;
    }
    void casoSucesso() override;
};


#endif //TRABALHO_1_CLION_TESTE_INGRESSO_H
