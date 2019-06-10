//
// Created by paulo on 10/06/19.
//

#include "../../Headers/Dominios/Disponibilidade.h"

void Disponibilidade::setDisponibilidade(std::string disponibilidade){
    if(validar(disponibilidade)){
        this->disponibilidade = disponibilidade;
    } else{
        throw std::invalid_argument (disponibilidade + " Eh uma disponibilidade invalida");
    }
}

bool Disponibilidade::validar(std::string disponibilidade){
    std::regex numRegex(R"(([012][0-5][0])|(\d\d)|(\d))");

    if(std::regex_match(disponibilidade, numRegex)){
        return true;
    } else{
        return false;
    }
}

std::istream& operator>>(std::istream& in, Disponibilidade& numSala){
    std::string str;

    in >> str;

    numSala.setDisponibilidade(str);

    return in;
}