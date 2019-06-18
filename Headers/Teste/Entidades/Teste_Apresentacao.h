//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_APRESENTACAO_H
#define TRABALHO_1_CLION_TESTE_APRESENTACAO_H

#include <iostream>
#include "../Teste.h"
#include "../../Entidades/Apresentacao.h"
#include "Teste_Entidades.h"

class Teste_Apresentacao : public Teste_Entidades {
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Apresentacao" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Apresentacao" << std::endl;
    }
    int rodar() override;
private:

    Apresentacao *apresentacao;
    void configurar() override{
        apresentacao = new Apresentacao();
        estado = SUCESSO;
    }
    void desconfigurar() override{
        delete apresentacao;
    }
    void casoSucesso() override;
};


#endif //TRABALHO_1_CLION_TESTE_APRESENTACAO_H
