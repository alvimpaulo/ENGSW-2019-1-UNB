//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Preco.h"
#include "string"
#include <algorithm>

Preco::Preco(){
    preco = 0.0f;
}

void Preco::setPreco(std::string preco){
    std::replace(preco.begin(), preco.end(), ',', '.');
    if(validar(preco)){
        this->preco = (std::round(std::stof(preco) *100)/100.0);
    } else{
        throw (std::invalid_argument(preco + " nao eh um preco valido"));
    }
}

bool Preco::validar(std::string preco){
    std::replace(preco.begin(), preco.end(), ',', '.');
    std::regex nomeRegex(R"((\d+)((\,)|(\.))(\d+))");

    if(std::regex_match(preco, nomeRegex)){
        float tmpPreco = std::stof(preco);
        if(LIMITE_MINIMO_PRECO <= tmpPreco && tmpPreco <= LIMITE_MAXIMO_PRECO){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }
}

std::istream& operator>>(std::istream& in, Preco& preco){
    std::string str;

    in >> str;
    preco.setPreco(str);

    return in;
}