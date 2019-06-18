//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Num_De_Sala.h"

const std::string Teste_Num_De_Sala::VALOR_VALIDO = "1";
const std::string Teste_Num_De_Sala::VALOR_INVALIDO = "11";

void Teste_Num_De_Sala::configurar(){
    numDeSala = new Num_De_Sala;
    estado = SUCESSO;
}

void Teste_Num_De_Sala::casoSucesso(){
    try{
        numDeSala->setNumSala(VALOR_VALIDO);
        if(numDeSala->getNumSala() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        estado = FALHA;
    }
}

void Teste_Num_De_Sala::casoFalha(){
    try{
        numDeSala->setNumSala(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

