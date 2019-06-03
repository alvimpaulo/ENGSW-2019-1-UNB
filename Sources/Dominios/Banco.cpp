//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Banco.h"


void Banco::setBancoNum(std::string bancoNum){
    std::regex bancoNumRegex(R"(\d{3})");

    if(std::regex_match(bancoNum, bancoNumRegex)){
        this->bancoNum = bancoNum;
    } else{
        throw std::invalid_argument("Numero do banco fora do padrao");
    }
}

Banco::Banco(){
    bancoNum = "000";
}

std::istream& operator>>(std::istream& in, Banco& banco){
    std::string str;

    in >> str;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    banco.setBancoNum(str);

    return in;
}
