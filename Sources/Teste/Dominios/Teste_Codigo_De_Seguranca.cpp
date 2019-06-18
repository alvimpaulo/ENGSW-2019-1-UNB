//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Codigo_De_Seguranca.h"

const std::string Teste_Codigo_De_Seguranca::VALOR_VALIDO = "001";
const std::string Teste_Codigo_De_Seguranca::VALOR_INVALIDO = "1010";

void Teste_Codigo_De_Seguranca::configurar(){
    codigoDeSeguranca = new Codigo_De_Seguranca;
    estado = SUCESSO;
}

void Teste_Codigo_De_Seguranca::casoSucesso(){
    try{
        codigoDeSeguranca->setCodigoSeguranca(VALOR_VALIDO);
        if(codigoDeSeguranca->getCodigoSeguranca() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Codigo_De_Seguranca::casoFalha(){
    try{
        codigoDeSeguranca->setCodigoSeguranca(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}