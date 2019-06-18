//
// Created by paulo on 10/06/19.
//
// Regex: ((0[7-9])|(1\d)|(2[0-2])):((00)|(15)|(30)|(45))
// regexr.com/4fgn3

#include "../../Headers/Dominios/Horario.h"

void Horario::setHorario(std::string horario){
    std::regex horarioRegex(R"(((0[7-9])|(1\d)|(2[0-2])):((00)|(15)|(30)|(45)))");

    if(std::regex_match(horario, horarioRegex)){
        this->horario = horario;
    } else{
        throw std::invalid_argument("Horario fora do padrao");
    }
}

Horario::Horario(){
    horario = "07:00";
}

std::istream& operator>>(std::istream& in, Horario& horario){
    std::string str;

    in >> str;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    horario.setHorario(str);

    return in;
}