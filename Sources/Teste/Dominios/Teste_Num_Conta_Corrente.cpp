//
// Created by paulo on 16-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Num_Conta_Corrente.h"

const std::string Teste_Num_Conta_Corrente::VALOR_VALIDO = "000123";
const std::string Teste_Num_Conta_Corrente::VALOR_INVALIDO = "0123";

void Teste_Num_Conta_Corrente::configurar(){
    numContaCorrente = new Num_Conta_Corrente;
    estado = SUCESSO;

}

void Teste_Num_Conta_Corrente::casoSucesso(){
    try{
        numContaCorrente->setNum_Conta_Corrente(VALOR_VALIDO);
        if(numContaCorrente->getNum_Conta_Corrente() != VALOR_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Num_Conta_Corrente::casoFalha(){
    try{
        numContaCorrente->setNum_Conta_Corrente(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}
