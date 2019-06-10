//
// Created by oetch on 16/09/2018.
//

#include "../../../Headers/Teste/Entidades/Teste_Conta_Corrente.h"

void Teste_Conta_Corrente::casoSucesso(){
    Num_Conta_Corrente numContaCorrente;
    Agencia agencia;
    Codigo_De_Evento banco;
    try{
        contaCorrente->setNumero(numContaCorrente);
        contaCorrente->setAgencia(agencia);
        contaCorrente->setBanco(banco);
    } catch(std::exception &exception){
        std::cout << exception.what() << std::endl;
        this->estado = FALHA;
    }


}
