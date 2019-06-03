//
// Created by oetch on 08/09/2018.
//

#include "../../../Headers/Teste/Dominios/Teste_Data_De_Validade.h"


const std::string Teste_Data_De_Validade::VALOR_VALIDO = "12/99";
const std::string Teste_Data_De_Validade::VALOR_CARACTERE_INVALIDO = "*8/84";
const std::string Teste_Data_De_Validade::VALOR_COMPRIMENTO_INVALIDO = "10/2000";
const std::string Teste_Data_De_Validade::VALOR_INTERVALO_MES_INVALIDO = "31/ola/2001";

void Teste_Data_De_Validade::configurar(){
    data_de_validade = new Data_De_Validade;
    estado = SUCESSO;
}

void Teste_Data_De_Validade::casoSucesso(){
    try{
        data_de_validade->setData_De_Validade(VALOR_VALIDO);
        if(data_de_validade->getData_De_Validade() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        estado = FALHA;
    }
}

void Teste_Data_De_Validade::casoFalha(){
    casoFalhaCaratereInvalido();
    casoFalhaComprimentoInvalido();
    casoFalhaIntervaloMesInvalido();
}

void Teste_Data_De_Validade::casoFalhaCaratereInvalido(){
    try{
        data_de_validade->setData_De_Validade(VALOR_CARACTERE_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Data_De_Validade::casoFalhaComprimentoInvalido(){
    try{
        data_de_validade->setData_De_Validade(VALOR_COMPRIMENTO_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}

void Teste_Data_De_Validade::casoFalhaIntervaloMesInvalido(){
    try{
        data_de_validade->setData_De_Validade(VALOR_INTERVALO_MES_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}
