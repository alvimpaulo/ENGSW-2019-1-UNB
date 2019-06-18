//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Codigo_De_Evento.h"

const std::string Teste_Codigo_De_Evento::VALOR_VALIDO = "012";
const std::string Teste_Codigo_De_Evento::VALOR_CARACTERE_INVALIDO = "01F";
const std::string Teste_Codigo_De_Evento::VALOR_COMPRIMENTO_INVALIDO = "0124";

void Teste_Codigo_De_Evento::configurar(){
    codigoDeEvento = new Codigo_De_Evento;
    estado = SUCESSO;
}

void Teste_Codigo_De_Evento::casoSucesso(){
    try{
        codigoDeEvento->setCodigoEvento(VALOR_VALIDO);
        if(codigoDeEvento->getCodigoEvento() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        estado = FALHA;
    }
}

void Teste_Codigo_De_Evento::casoFalha(){
    casoFalhaCaratereInvalido();
    casoFalhaComprimentoInvalido();
}

void Teste_Codigo_De_Evento::casoFalhaCaratereInvalido(){
    try{
        codigoDeEvento->setCodigoEvento(VALOR_CARACTERE_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Codigo_De_Evento::casoFalhaComprimentoInvalido(){
    try{
        codigoDeEvento->setCodigoEvento(VALOR_COMPRIMENTO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}