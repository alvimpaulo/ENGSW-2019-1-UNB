//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Num_Conta_Corrente.h"

bool Num_Conta_Corrente::validar(std::string numConta){
    std::regex contaRegex(R"(\d{6})");

    if(std::regex_match(numConta, contaRegex)){
        return true;
    } else{
        return false;
    }
}

void Num_Conta_Corrente::setNum_Conta_Corrente(std::string numConta){
    if(validar(numConta)){
        this->numConta = numConta;
    } else{
        throw std::invalid_argument(numConta + " Nao eh um numero de conta valido");
    }

}

Num_Conta_Corrente::Num_Conta_Corrente(){
    numConta = "000000";

}

std::istream& operator>>(std::istream& in, Num_Conta_Corrente& numContaCorrente){
    std::string str;

    in >> str;
    numContaCorrente.setNum_Conta_Corrente(str);

    return in;
}
