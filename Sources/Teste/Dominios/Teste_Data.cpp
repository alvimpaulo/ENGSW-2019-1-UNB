//
// Created by oetch on 08/09/2018.
//

#include "../../../Headers/Teste/Dominios/Teste_Data.h"


const std::string Teste_Data::VALOR_VALIDO = "29/fev/2012";
const std::string Teste_Data::VALOR_CARACTERE_INVALIDO = "2T/jan/2055";
const std::string Teste_Data::VALOR_COMPRIMENTO_INVALIDO = "21/ago/201500";
const std::string Teste_Data::VALOR_INTERVALO_ANO_INVALIDO = "30/mai/3000";
const std::string Teste_Data::VALOR_MES_INVALIDO = "31/ola/2001";
const std::string Teste_Data::VALOR_INTERVALO_DIA_MES_QUALQUER_INVALIDO = "32/jan/2001";
const std::string Teste_Data::VALOR_INTERVALO_DIA_FEVEREIRO_NORMAL_INVALIDO = "29/fev/2011";
const std::string Teste_Data::VALOR_INTERVALO_DIA_FEVEREIRO_BIXESTO_INVALIDO = "30/fev/2010";

void Teste_Data::configurar(){
    data = new Data;
    estado = SUCESSO;
}

void Teste_Data::casoSucesso(){
    try{
        data->setData(VALOR_VALIDO);
        if(data->getData() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        estado = FALHA;
    }
}

void Teste_Data::casoFalha(){
    casoFalhaCaratereInvalido();
    casoFalhaComprimentoInvalido();
    casoFalhaIntervaloAnoInvalido();
    casoFalhaMesInvalido();
    casoFalhaIntervaloDiaMesQualquerInvalido();
    casoFalhaIntervaloDiaFevereiroNormalInvalido();
    casoFalhaIntervaloDiaFevereiroBixestoInvalido();
}

void Teste_Data::casoFalhaCaratereInvalido(){
    try{
        data->setData(VALOR_CARACTERE_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Data::casoFalhaIntervaloAnoInvalido(){
    try{
        data->setData(VALOR_INTERVALO_ANO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Data::casoFalhaMesInvalido(){
    try{
        data->setData(VALOR_MES_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Data::casoFalhaComprimentoInvalido(){
    try{
        data->setData(VALOR_COMPRIMENTO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Data::casoFalhaIntervaloDiaMesQualquerInvalido(){
    try{
        data->setData(VALOR_INTERVALO_DIA_MES_QUALQUER_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Data::casoFalhaIntervaloDiaFevereiroNormalInvalido(){
    try{
        data->setData(VALOR_INTERVALO_DIA_FEVEREIRO_NORMAL_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Data::casoFalhaIntervaloDiaFevereiroBixestoInvalido(){
    try{
        data->setData(VALOR_INTERVALO_DIA_FEVEREIRO_BIXESTO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}