//
// Created by oetch on 16/09/2018.
//

#include "../../../Headers/Teste/Entidades/Teste_Cartao_De_Credito.h"

void Teste_Cartao_De_Credito::casoSucesso(){
    Num_Cartao_Credito numCartaoCredito;
    Data_De_Validade dataDeValidade;
    Codigo_De_Seguranca codigoDeSeguranca;

    try{
        cartaoDeCredito->setNumero(numCartaoCredito);
        cartaoDeCredito->setDataDeValidade(dataDeValidade);
        cartaoDeCredito->setCodigoDeSeguranca(codigoDeSeguranca);
    } catch(std::exception &exception){
        std::cout<<exception.what() << std::endl;
        estado = FALHA;
    }

}
