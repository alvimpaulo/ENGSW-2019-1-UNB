//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_CLASSE_DE_EVENTO_H
#define TRABALHO_1_CLION_TESTE_CLASSE_DE_EVENTO_H

#include <iostream>
#include "../Teste.h"
#include "Teste_Dominios.h"
#include "../../Dominios/Classe_De_Evento.h"
#include <stdexcept>

class Teste_Classe_De_Evento : public Teste_Dominios{
public:
    void mensagemSucesso() override {
        std::cout << "Sucesso Classe de evento" << std::endl;
    }
    void mensagemFalha() override {
        std::cout << "Falha Classe de evento" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;

    Classe_De_Evento *classeDeEvento;
    void configurar() override ;
    void desconfigurar() override {
        delete classeDeEvento;
    }

    void casoSucesso() override ;
    void casoFalha() override ;
};


#endif //TRABALHO_1_CLION_TESTE_CLASSE_DE_EVENTO_H
