//
// Created by paulo on 15-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Capacidade_De_Acomodacao.h"

const std::string Teste_Capacidade_De_Acomodacao::VALOR_VALIDO = "1";
const std::string Teste_Capacidade_De_Acomodacao::VALOR_INVALIDO = "0";

void Teste_Capacidade_De_Acomodacao::configurar(){
    capacidade = new Num_De_Sala;
    estado = SUCESSO;
}

void Teste_Capacidade_De_Acomodacao::casoSucesso(){
    try{
        capacidade->setNumSala(VALOR_VALIDO);
        if(capacidade->getNumSala() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Capacidade_De_Acomodacao::casoFalha(){
    try{
        capacidade->setNumSala(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}