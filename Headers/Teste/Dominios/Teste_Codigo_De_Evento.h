//
// Created by paulo on 17/06/19.
//

#ifndef TRABALHO_1_CLION_TESTE_CODIGO_DE_EVENTO_H
#define TRABALHO_1_CLION_TESTE_CODIGO_DE_EVENTO_H

#include <string>
#include <iostream>
#include "../Teste.h"
#include "Teste_Dominios.h"
#include "../../Dominios/Codigo_De_Evento.h"

class Teste_Codigo_De_Evento: public Teste_Dominios {
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Codigo de evento" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Codigo de evento" << std::endl;
    }
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_CARACTERE_INVALIDO;
    static const std::string VALOR_COMPRIMENTO_INVALIDO;

    Codigo_De_Evento *codigoDeEvento;
    void configurar() override;
    void desconfigurar() override{
        delete codigoDeEvento;
    }

    void casoSucesso() override;
    void casoFalha() override;
    void casoFalhaCaratereInvalido();
    void casoFalhaComprimentoInvalido();
};


#endif //TRABALHO_1_CLION_TESTE_CODIGO_DE_EVENTO_H
