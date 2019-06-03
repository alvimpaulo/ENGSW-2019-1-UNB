//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Identificador.h"



bool Identificador::validar(std::string identificador){
    std::regex identificadorRegex(R"([a-z]{5})");

    if(std::regex_match(identificador, identificadorRegex)){
        return true;
    } else{
        return false;
    }
}

void Identificador::setIdentificador(std::string identificador){
    if(validar(identificador)){
        this->identificador = identificador;
    } else{
        throw std::invalid_argument(identificador + " Esta fora do padrao de identificador");
    }
}

std::istream& operator>>(std::istream& in, Identificador& identificador){
    std::string str;

    in >> str;
    identificador.setIdentificador(str);

    return in;
}

Identificador::Identificador() {
    setIdentificador("abcde");

}
