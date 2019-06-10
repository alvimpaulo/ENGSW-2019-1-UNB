//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Codigo_De_Apresentacao.h"


void Codigo_De_Apresentacao::setCodigoApresentacao(std::string codigoApresentacao){
    std::regex codigoApresentacaoRegex(R"(\d{4})");

    if(std::regex_match(codigoApresentacao, codigoApresentacaoRegex)){
        this->codigoApresentacao = codigoApresentacao;
    } else{
        throw std::invalid_argument("Codigo de apresentacao fora do padrao");
    }
}

Codigo_De_Apresentacao::Codigo_De_Apresentacao(){
    codigoApresentacao = "0000";
}

std::istream& operator>>(std::istream& in, Codigo_De_Apresentacao& codigo){
    std::string str;

    in >> str;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    codigo.setCodigoApresentacao(str);

    return in;
}
