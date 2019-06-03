//
// Created by paulo on 15-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Identificador.h"

const std::string Teste_Identificador::VALOR_VALIDO = "abcde";
const std::string Teste_Identificador::VALOR_INVALIDO = "abcdef";

void Teste_Identificador::configurar(){
    identificador = new Identificador;
    estado = SUCESSO;

}

void Teste_Identificador::casoSucesso(){
    try{
        identificador->setIdentificador(VALOR_VALIDO);
        if(identificador->getIdentificador() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }
}

void Teste_Identificador::casoFalha(){
    try{
        identificador->setIdentificador(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}
