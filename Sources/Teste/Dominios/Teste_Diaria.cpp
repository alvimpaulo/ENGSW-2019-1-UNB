//
// Created by oetch on 08/09/2018.
//

#include "../../../Headers/Teste/Dominios/Teste_Diaria.h"

const std::string Teste_Diaria::VALOR_VALIDO = "1224.50";
const std::string Teste_Diaria::VALOR_CARACTERE_INVALIDO = "1k.51";
const std::string Teste_Diaria::VALOR_INTERVALO_INVALIDO = "11000.99";

void Teste_Diaria::configurar(){
    diaria = new Diaria;
    estado = SUCESSO;
}

void Teste_Diaria::casoSucesso(){
    try{
        diaria->setDiaria(VALOR_VALIDO);
        if(diaria->getDiaria() != (std::round(std::stof(VALOR_VALIDO)*100)/100.0)){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        estado = FALHA;
    }
}

void Teste_Diaria::casoFalha(){
    casoFalhaCaratereInvalido();
    casoFalhaIntervaloInvalido();
}

void Teste_Diaria::casoFalhaCaratereInvalido(){
    try{
        diaria->setDiaria(VALOR_CARACTERE_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Diaria::casoFalhaIntervaloInvalido(){
    try{
        diaria->setDiaria(VALOR_INTERVALO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}