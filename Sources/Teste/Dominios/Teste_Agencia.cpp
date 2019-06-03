//
// Created by oetch on 08/09/2018.
//


#include "../../../Headers/Teste/Dominios/Teste_Agencia.h"
#include "../../../Headers/Dominios/Agencia.h"

const std::string Teste_Agencia::VALOR_VALIDO = "01234";
const std::string Teste_Agencia::VALOR_CARACTERE_INVALIDO = "01F34";
const std::string Teste_Agencia::VALOR_COMPRIMENTO_INVALIDO = "012345";

void Teste_Agencia::configurar(){
    agencia = new Agencia;
    estado = SUCESSO;
}

void Teste_Agencia::casoSucesso(){
    try{
        agencia->setAgenciaNum(VALOR_VALIDO);
        if(agencia->getAgenciaNum() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        estado = FALHA;
    }
}

void Teste_Agencia::casoFalha(){
    casoFalhaCaratereInvalido();
    casoFalhaComprimentoInvalido();
}

void Teste_Agencia::casoFalhaCaratereInvalido(){
    try{
        agencia->setAgenciaNum(VALOR_CARACTERE_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Agencia::casoFalhaComprimentoInvalido(){
    try{
        agencia->setAgenciaNum(VALOR_COMPRIMENTO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}