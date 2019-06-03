//
// Created by paulo on 04-Sep-18.
//

// codigo para a validação: (( (?! ))|(\b\.)|(\w)){15}
// https://regexr.com/3uum7

#include "../../Headers/Dominios/Nome.h"

Nome::Nome(){
    nome = "NomeNaoDefinido";
}

void Nome::setNome(std::string nome){
    std::regex nomeRegex(R"((( (?! ))|(\b\.)|([a-zA-Z])){15})");
    std::smatch results;

    if(std::regex_match(nome, nomeRegex)){
        this->nome = nome;
    } else{
        throw (std::invalid_argument("Nome Invalido"));
    }

}

std::istream& operator>>(std::istream& in, Nome& nome){
    std::string str;

    in >> str;

    nome.setNome(str);

    return in;
}