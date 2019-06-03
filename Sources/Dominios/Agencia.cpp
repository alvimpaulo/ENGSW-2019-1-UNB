//
// Created by paulo on 04-Sep-18.
//

#include <iostream>
#include "../../Headers/Dominios/Agencia.h"

Agencia::Agencia(){
    agenciaNum = "00000";
}

void Agencia::setAgenciaNum(std::string agenciaNum){
    std::regex agenciaNumRegex(R"(\d{5})");

    if(std::regex_match(agenciaNum, agenciaNumRegex)){
        this->agenciaNum = agenciaNum;
    } else{
        throw std::invalid_argument("Numero de agencia fora do padrao");
    }
}

std::istream& operator>>(std::istream& in, Agencia& agencia){
    std::string str;

    in >> str;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    agencia.setAgenciaNum(str);

    return in;
}