//
// Created by oetch on 08/09/2018.
//

#ifndef TRABALHO_1_CLION_TESTE_ESTADO_H
#define TRABALHO_1_CLION_TESTE_ESTADO_H


#include "../../Dominios/Estado.h"
#include "../Teste.h"
#include "Teste_Dominios.h"

/**
 * @brief Classe que testa a classe Estado.
 * @details
 */
class Teste_Estado: public Teste_Dominios{
public:
    void mensagemSucesso(){
        std::cout << "Sucesso Estado" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Estado" << std::endl;
    }
protected:
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_CARACTERE_INVALIDO;
    static const std::string VALOR_COMPRIMENTO_INVALIDO;

    Estado *UF;

    void configurar();
    void desconfigurar(){
        delete UF;
    }

    void casoSucesso();
    void casoFalha();
    void casoFalhaCaratereInvalido();
    void casoFalhaComprimentoInvalido();
};


#endif //TRABALHO_1_CLION_TESTE_ESTADO_H
