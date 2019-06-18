//
// Created by paulo on 15-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Disponibilidade.h"

const std::string Teste_Disponibilidade::VALOR_VALIDO = "1";
const std::string Teste_Disponibilidade::VALOR_INVALIDO = "300";

void Teste_Disponibilidade::configurar(){
    disponibilidade = new Disponibilidade;
    estado = SUCESSO;
}

void Teste_Disponibilidade::casoSucesso(){
    try{
        disponibilidade->setDisponibilidade(VALOR_VALIDO);
        if(disponibilidade->getDisponibilidade() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Disponibilidade::casoFalha(){
    try{
        disponibilidade->setDisponibilidade(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}