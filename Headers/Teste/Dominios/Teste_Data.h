//
// Created by oetch on 08/09/2018.
//

#ifndef TRABALHO_1_CLION_TESTE_DATA_H
#define TRABALHO_1_CLION_TESTE_DATA_H


#include <string>
#include "../../Dominios/Data.h"
#include "../Teste.h"
#include "Teste_Dominios.h"

/**
 * @brief Classe que testa a classe Data.
 * @details
 */
class Teste_Data: public Teste_Dominios{
public:
    void mensagemSucesso(){
        std::cout << "Sucesso Data" << std::endl;
    }
    void mensagemFalha(){
        std::cout << "Falha Data" << std::endl;
    }
protected:
private:
    static const std::string VALOR_VALIDO;
    static const std::string VALOR_CARACTERE_INVALIDO;
    static const std::string VALOR_COMPRIMENTO_INVALIDO;
    static const std::string VALOR_INTERVALO_ANO_INVALIDO;
    static const std::string VALOR_MES_INVALIDO;
    static const std::string VALOR_INTERVALO_DIA_MES_QUALQUER_INVALIDO;
    static const std::string VALOR_INTERVALO_DIA_FEVEREIRO_NORMAL_INVALIDO;
    static const std::string VALOR_INTERVALO_DIA_FEVEREIRO_BIXESTO_INVALIDO;

    Data *data;

    void configurar();
    void desconfigurar(){
        delete data;
    }

    void casoSucesso();
    void casoFalha();
    void casoFalhaCaratereInvalido();
    void casoFalhaComprimentoInvalido();
    void casoFalhaIntervaloAnoInvalido();
    void casoFalhaMesInvalido();
    void casoFalhaIntervaloDiaMesQualquerInvalido();
    void casoFalhaIntervaloDiaFevereiroNormalInvalido();
    void casoFalhaIntervaloDiaFevereiroBixestoInvalido();
};


#endif //TRABALHO_1_CLION_TESTE_DATA_H
