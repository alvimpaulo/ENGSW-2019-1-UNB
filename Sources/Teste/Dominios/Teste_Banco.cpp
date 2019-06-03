//
// Created by paulo on 13-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Banco.h"

const std::string Teste_Banco::VALOR_VALIDO = "001";
const std::string Teste_Banco::VALOR_INVALIDO = "0001";


void Teste_Banco::configurar(){
    banco = new Banco;
    estado = SUCESSO;
}

void Teste_Banco::casoSucesso(){
    try{
        banco->setBancoNum(VALOR_VALIDO);
        if(banco->getBancoNum() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        return;
    }


}

void Teste_Banco::casoFalha(){
    try{
        banco->setBancoNum(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}
