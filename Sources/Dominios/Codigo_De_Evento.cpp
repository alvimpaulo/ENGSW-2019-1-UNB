//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Codigo_De_Evento.h"


void Codigo_De_Evento::setCodigoEvento(std::string codigoEvento){
    std::regex codigoEventoRegex(R"(\d{3})");

    if(std::regex_match(codigoEvento, codigoEventoRegex)){
        this->codigoEvento = codigoEvento;
    } else{
        throw std::invalid_argument("Codigo de evento fora do padrao");
    }
}

Codigo_De_Evento::Codigo_De_Evento(){
    codigoEvento = "000";
}

std::istream& operator>>(std::istream& in, Codigo_De_Evento& codigo){
    std::string str;

    in >> str;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    codigo.setCodigoEvento(str);

    return in;
}
