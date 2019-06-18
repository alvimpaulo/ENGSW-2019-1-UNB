//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_HORARIO_H
#define TRABALHO_1_CLION_TESTE_HORARIO_H

#include "../../Dominios/Horario.h"
#include "Teste_Dominios.h"
#include "../Teste.h"
#include "iostream"

class Teste_Horario : public Teste_Dominios {
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Horario" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Horario" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;


    Horario *horario;
    void configurar() override;
    void desconfigurar() override{
        delete horario;
    }

    void casoSucesso() override;
    void casoFalha() override;
};


#endif //TRABALHO_1_CLION_TESTE_HORARIO_H
