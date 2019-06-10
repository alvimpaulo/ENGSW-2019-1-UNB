//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Codigo_De_Ingresso.h"


void Codigo_De_Ingresso::setCodigoIngresso(std::string codigoIngresso){
    std::regex codigoIngressoRegex(R"(\d{5})");

    if(std::regex_match(codigoIngresso, codigoIngressoRegex)){
        this->codigoIngresso = codigoIngresso;
    } else{
        throw std::invalid_argument("Codigo de ingresso fora do padrao");
    }
}

Codigo_De_Ingresso::Codigo_De_Ingresso(){
    codigoIngresso = "00000";
}

std::istream& operator>>(std::istream& in, Codigo_De_Ingresso& codigo){
    std::string str;

    in >> str;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    codigo.setCodigoIngresso(str);

    return in;
}
