//
// Created by oetch on 08/09/2018.
//


#include "../../../Headers/Teste/Dominios/Teste_Codigo_De_Ingresso.h"

const std::string Teste_Codigo_De_Ingresso::VALOR_VALIDO = "01234";
const std::string Teste_Codigo_De_Ingresso::VALOR_CARACTERE_INVALIDO = "01F34";
const std::string Teste_Codigo_De_Ingresso::VALOR_COMPRIMENTO_INVALIDO = "012345";

void Teste_Codigo_De_Ingresso::configurar(){
    codigoDeIngresso = new Codigo_De_Ingresso;
    estado = SUCESSO;
}

void Teste_Codigo_De_Ingresso::casoSucesso(){
    try{
        codigoDeIngresso->setCodigoIngresso(VALOR_VALIDO);
        if(codigoDeIngresso->getCodigoIngresso() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        estado = FALHA;
    }
}

void Teste_Codigo_De_Ingresso::casoFalha(){
    casoFalhaCaratereInvalido();
    casoFalhaComprimentoInvalido();
}

void Teste_Codigo_De_Ingresso::casoFalhaCaratereInvalido(){
    try{
        codigoDeIngresso->setCodigoIngresso(VALOR_CARACTERE_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Codigo_De_Ingresso::casoFalhaComprimentoInvalido(){
    try{
        codigoDeIngresso->setCodigoIngresso(VALOR_COMPRIMENTO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}