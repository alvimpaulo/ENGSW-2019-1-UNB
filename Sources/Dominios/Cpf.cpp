//
// Created by paulo on 10/06/19.
//

#include "../../Headers/Dominios/Cpf.h"

void Cpf::setCpf(std::string cpf){
    std::regex cpfRegex(R"(\d{3}\.\d{3}\.\d{3}-\d{2})");

    if(std::regex_match(cpf, cpfRegex)){
        this->cpf = cpf;
    } else{
        throw std::invalid_argument("Cpf fora do padrao");
    }
}

Cpf::Cpf(){
    cpf = "000.000.000-00";
}

std::istream& operator>>(std::istream& in, Cpf& cpf){
    std::string str;

    in >> str;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cpf.setCpf(str);

    return in;
}
