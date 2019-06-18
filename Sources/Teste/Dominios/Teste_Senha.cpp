//
// Created by paulo on 16-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Senha.h"

const std::string Teste_Senha::VALOR_VALIDO = "Paulo1";
const std::string Teste_Senha::VALOR_INVALIDO = "OscPau";

void Teste_Senha::configurar(){
    senha = new Senha;
    estado = SUCESSO;

}

void Teste_Senha::casoSucesso(){
    try{
        senha->setSenha(VALOR_VALIDO);
        if(senha->getSenha() != VALOR_VALIDO)
            estado = FALHA;
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Senha::casoFalha(){
    try{
        senha->setSenha(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}