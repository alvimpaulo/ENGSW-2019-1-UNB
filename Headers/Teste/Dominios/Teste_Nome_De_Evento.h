//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_NOME_DE_EVENTO_H
#define TRABALHO_1_CLION_TESTE_NOME_DE_EVENTO_H

#include "../../Dominios/Nome_De_Evento.h"
#include "../Teste.h"
#include "Teste_Dominios.h"

class Teste_Nome_De_Evento : public Teste_Dominios{
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Cidade" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Cidade" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_INVALIDO;


    Nome_De_Evento *nomeDeEvento;
    void configurar() override ;
    void desconfigurar() override{
        delete nomeDeEvento;
    }

    void casoSucesso() override ;
    void casoFalha() override ;
};


#endif //TRABALHO_1_CLION_TESTE_NOME_DE_EVENTO_H
