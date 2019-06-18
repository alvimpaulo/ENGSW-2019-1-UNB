//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Preco.h"

const std::string Teste_Preco::VALOR_VALIDO = "10.10";
const std::string Teste_Preco::VALOR_INVALIDO = "1001.00";

void Teste_Preco::configurar(){
    preco = new Preco;
    estado = SUCESSO;

}

void Teste_Preco::casoSucesso(){
    try{
        preco->setPreco(VALOR_VALIDO);
        if(preco->getPreco() != std::stof(VALOR_VALIDO)){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Preco::casoFalha(){
    try{
        preco->setPreco(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}