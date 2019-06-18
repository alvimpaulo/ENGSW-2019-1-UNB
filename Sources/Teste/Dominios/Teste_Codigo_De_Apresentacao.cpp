//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Codigo_De_Apresentacao.h"

const std::string Teste_Codigo_De_Apresentacao::VALOR_VALIDO = "0123";
const std::string Teste_Codigo_De_Apresentacao::VALOR_CARACTERE_INVALIDO = "01F3";
const std::string Teste_Codigo_De_Apresentacao::VALOR_COMPRIMENTO_INVALIDO = "01234";

void Teste_Codigo_De_Apresentacao::configurar(){
    codigoDeApresentacao = new Codigo_De_Apresentacao;
    estado = SUCESSO;
}

void Teste_Codigo_De_Apresentacao::casoSucesso(){
    try{
        codigoDeApresentacao->setCodigoApresentacao(VALOR_VALIDO);
        if(codigoDeApresentacao->getCodigoApresentacao() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        estado = FALHA;
    }
}

void Teste_Codigo_De_Apresentacao::casoFalha(){
    casoFalhaCaratereInvalido();
    casoFalhaComprimentoInvalido();
}

void Teste_Codigo_De_Apresentacao::casoFalhaCaratereInvalido(){
    try{
        codigoDeApresentacao->setCodigoApresentacao(VALOR_CARACTERE_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Codigo_De_Apresentacao::casoFalhaComprimentoInvalido(){
    try{
        codigoDeApresentacao->setCodigoApresentacao(VALOR_COMPRIMENTO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}