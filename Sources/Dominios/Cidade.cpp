//
// Created by paulo on 04-Sep-18.
//

// codigo para a validação: (( (?! ))|(\b\.)|(\w)){15}
// https://regexr.com/3uum7

#include "../../Headers/Dominios/Cidade.h"

Cidade::Cidade(){
    cidade = "NomeNaoDefinido";
}

void Cidade::setCidade(std::string cidade){
    std::regex nomeRegex(R"((( (?! ))|(\b\.)|([a-zA-Z])){15})");
    std::smatch results;

    if(std::regex_match(cidade, nomeRegex)){
        this->cidade = cidade;
    } else{
        throw (std::invalid_argument("Nome De Cidade Invalido"));
    }

}

std::istream& operator>>(std::istream& in, Cidade& nome){
    std::string str;

    in >> str;

    nome.setCidade(str);

    return in;
}