//
// Created by oetch on 08/09/2018.
//

#include "../../../Headers/Teste/Dominios/Teste_Data.h"


const std::string Teste_Data::VALOR_VALIDO = "29/02/2012";
const std::string Teste_Data::VALOR_CARACTERE_INVALIDO = "2T/01/2055";
const std::string Teste_Data::VALOR_COMPRIMENTO_INVALIDO = "21/06/201500";
const std::string Teste_Data::VALOR_MES_INVALIDO = "31/ola/2001";

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
    casoFalhaMesInvalido();
}

void Teste_Data::casoFalhaCaratereInvalido(){
    try{
        data->setData(VALOR_CARACTERE_INVALIDO);
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