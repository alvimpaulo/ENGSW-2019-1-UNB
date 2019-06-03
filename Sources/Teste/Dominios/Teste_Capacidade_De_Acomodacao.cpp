//
// Created by paulo on 15-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Capacidade_De_Acomodacao.h"

const std::string Teste_Capacidade_De_Acomodacao::VALOR_VALIDO = "1";
const std::string Teste_Capacidade_De_Acomodacao::VALOR_INVALIDO = "0";

void Teste_Capacidade_De_Acomodacao::configurar(){
    capacidade = new Capacidade_De_Acomodacao;
    estado = SUCESSO;
}

void Teste_Capacidade_De_Acomodacao::casoSucesso(){
    try{
        capacidade->setCapacidade_De_Acomodacao(VALOR_VALIDO);
        if(capacidade->getCapacidade_de_Acomodacao() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Capacidade_De_Acomodacao::casoFalha(){
    try{
        capacidade->setCapacidade_De_Acomodacao(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}