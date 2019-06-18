//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_EVENTO_H
#define TRABALHO_1_CLION_TESTE_EVENTO_H

#include <iostream>
#include "../Teste.h"
#include "../../Entidades/Evento.h"
#include "Teste_Entidades.h"

class Teste_Evento : public Teste_Entidades {
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Evento" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Evento" << std::endl;
    }
    int rodar() override;
private:

    Evento *evento;
    void configurar() override{
        evento = new Evento();
        estado = SUCESSO;
    }
    void desconfigurar() override{
        delete evento;
    }
    void casoSucesso() override;
};


#endif //TRABALHO_1_CLION_TESTE_EVENTO_H
