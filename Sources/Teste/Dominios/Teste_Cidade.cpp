//
// Created by paulo on 15-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Cidade.h"

const std::string Teste_Cidade::VALOR_VALIDO = "paulandia do su";
const std::string Teste_Cidade::VALOR_INVALIDO = "paulandia do norte";

void Teste_Cidade::configurar(){
    nome = new Cidade;
    estado = SUCESSO;

}

void Teste_Cidade::casoSucesso(){
    try{
        nome->setCidade(VALOR_VALIDO);
        if(nome->getCidade() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Cidade::casoFalha(){
    try{
        nome->setCidade(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}