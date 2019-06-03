//
// Created by oetch on 08/09/2018.
//

#ifndef TRABALHO_1_CLION_TESTE_TIPO_ACOMODACA_H
#define TRABALHO_1_CLION_TESTE_TIPO_ACOMODACA_H


#include <string>
#include "../../Dominios/Tipo_Acomodacao.h"
#include "../Teste.h"
#include "Teste_Dominios.h"

/**
 * @brief Classe que testa a classe Tipo_Acomodacao.
 * @details
 */
class Teste_Tipo_Acomodacao: public Teste_Dominios{
public:
    void mensagemSucesso(){
        std::cout << "Sucesso Tipo de Acomodacao" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Tipo de Acomodacao" << std::endl;
    }
protected:
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_CARACTERE_INVALIDO;
    static const std::string VALOR_COMPRIMENTO_INVALIDO;

    Tipo_Acomodacao *tipo_acomodacao;

    void configurar();
    void desconfigurar(){
        delete tipo_acomodacao;
    }

    void casoSucesso();
    void casoFalha();
    void casoFalhaCaratereInvalido();
    void casoFalhaComprimentoInvalido();
};

#endif //TRABALHO_1_CLION_TESTE_TIPO_ACOMODACA_H
