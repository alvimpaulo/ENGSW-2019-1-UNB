//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Codigo_De_Seguranca.h"


void Codigo_De_Seguranca::setCodigoSeguranca(std::string codigoSeguranca){
    std::regex codigoSegurancaRegex(R"(\d{3})");

    if(std::regex_match(codigoSeguranca, codigoSegurancaRegex)){
        this->codigoSeguranca = codigoSeguranca;
    } else{
        throw std::invalid_argument("Codigo de evento fora do padrao");
    }
}

Codigo_De_Seguranca::Codigo_De_Seguranca(){
    codigoSeguranca = "000";
}

std::istream& operator>>(std::istream& in, Codigo_De_Seguranca& codigo){
    std::string str;

    in >> str;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    codigo.setCodigoSeguranca(str);

    return in;
}
