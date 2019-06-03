//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Capacidade_De_Acomodacao.h"

void Capacidade_De_Acomodacao::setCapacidade_De_Acomodacao(std::string capacidade_de_acomodacao){
    if(validar(capacidade_de_acomodacao)){
        this->capacidade_de_acomodacao = capacidade_de_acomodacao;
    } else{
        throw std::invalid_argument (capacidade_de_acomodacao + " Eh um numero da capacidade invalido");
    }
}

bool Capacidade_De_Acomodacao::validar(std::string capacidade){
    std::regex capacidadeRegex(R"([1-9])");

    if(std::regex_match(capacidade, capacidadeRegex)){
        return true;
    } else{
        return false;
    }
}

std::istream& operator>>(std::istream& in, Capacidade_De_Acomodacao& capacidadeDeAcomodacao){
    std::string str;

    in >> str;

    capacidadeDeAcomodacao.setCapacidade_De_Acomodacao(str);

    return in;
}