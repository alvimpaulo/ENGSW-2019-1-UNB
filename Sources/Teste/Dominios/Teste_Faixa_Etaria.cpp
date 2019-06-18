//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Faixa_Etaria.h"

const std::string Teste_Faixa_Etaria::VALOR_VALIDO = "L";
const std::string Teste_Faixa_Etaria::VALOR_INVALIDO = "20";

void Teste_Faixa_Etaria::configurar(){
    faixaEtaria = new Faixa_Etaria;
    estado = SUCESSO;
}

void Teste_Faixa_Etaria::casoSucesso(){
    try{
        faixaEtaria->setFaixaEtaria(VALOR_VALIDO);
        if(faixaEtaria->getFaixaEtaria() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Faixa_Etaria::casoFalha(){
    try{
        faixaEtaria->setFaixaEtaria(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}