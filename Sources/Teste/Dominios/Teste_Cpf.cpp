//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Cpf.h"

const std::string Teste_Cpf::VALOR_VALIDO = "000.000.000-09";
const std::string Teste_Cpf::VALOR_INVALIDO = "000,000.000-101";

void Teste_Cpf::configurar(){
    cpf = new Cpf;
    estado = SUCESSO;
}

void Teste_Cpf::casoSucesso(){
    try{
        cpf->setCpf(VALOR_VALIDO);
        if(cpf->getCpf() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Cpf::casoFalha(){
    try{
        cpf->setCpf(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}