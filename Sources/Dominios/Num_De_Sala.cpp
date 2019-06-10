//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Num_De_Sala.h"

void Num_De_Sala::setNumSala(std::string numero){
    if(validar(numero)){
        this->numSala = numero;
    } else{
        throw std::invalid_argument (numero + " Eh um numero de salas invalido");
    }
}

bool Num_De_Sala::validar(std::string numero){
    std::regex numRegex(R"(([1-9])|(10))");

    if(std::regex_match(numero, numRegex)){
        return true;
    } else{
        return false;
    }
}

std::istream& operator>>(std::istream& in, Num_De_Sala& numSala){
    std::string str;

    in >> str;

    numSala.setNumSala(str);

    return in;
}