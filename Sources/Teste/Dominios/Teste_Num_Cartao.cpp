//
// Created by paulo on 15-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Num_Cartao.h"

const std::string Teste_Num_Cartao::VALOR_VALIDO = "7143345726342266";
const std::string Teste_Num_Cartao::VALOR_INVALIDO= "7143345726342265";

void Teste_Num_Cartao::configurar(){
    numCartao = new Num_Cartao_Credito;
    estado = SUCESSO;

}

void Teste_Num_Cartao::casoSucesso(){
    try{
        numCartao->setNum_Cartao(VALOR_VALIDO);
        if(numCartao->getNum_Cartao() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }


}

void Teste_Num_Cartao::casoFalha(){
    try{
        numCartao->setNum_Cartao(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}
