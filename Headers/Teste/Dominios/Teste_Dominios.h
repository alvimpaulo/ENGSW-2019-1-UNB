//
// Created by oetch on 30/09/2018.
//

#ifndef TRABALHO_1_CLION_TESTE_DOMINIOS_H
#define TRABALHO_1_CLION_TESTE_DOMINIOS_H


#include "../Teste.h"

class Teste_Dominios: public Teste{
public:
    int rodar() override;
protected:
private:
    virtual void casoSucesso() = 0;
    virtual void casoFalha() = 0;
    virtual void configurar() = 0;
    virtual void desconfigurar() = 0;
};


#endif //TRABALHO_1_CLION_TESTE_DOMINIOS_H
