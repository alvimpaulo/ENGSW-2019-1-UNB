//
// Created by oetch on 08/09/2018.
//

#include "../../../Headers/Teste/Dominios/Teste_Estado.h"

const std::string Teste_Estado::VALOR_VALIDO = "BA";
const std::string Teste_Estado::VALOR_CARACTERE_INVALIDO = "D5";
const std::string Teste_Estado::VALOR_COMPRIMENTO_INVALIDO = "PRO";

void Teste_Estado::configurar(){
    UF = new Estado;
    estado = SUCESSO;
}

void Teste_Estado::casoSucesso(){
    try{
        UF->setEstado(VALOR_VALIDO);
        if(UF->getEstado() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        estado = FALHA;
    }
}

void Teste_Estado::casoFalha(){
    casoFalhaCaratereInvalido();
    casoFalhaComprimentoInvalido();
}

void Teste_Estado::casoFalhaCaratereInvalido(){
    try{
        UF->setEstado(VALOR_CARACTERE_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Estado::casoFalhaComprimentoInvalido(){
    try{
        UF->setEstado(VALOR_COMPRIMENTO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}