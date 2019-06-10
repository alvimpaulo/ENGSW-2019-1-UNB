//
// Created by paulo on 10/06/19.
//

#include "../../Headers/Dominios/Classe_De_Evento.h"

void Classe_De_Evento::setClasseEvento(std::string classeEvento){
    std::regex classeEventoRegex(R"([1234])");

    if(std::regex_match(classeEvento, classeEventoRegex)){
        this->classeEvento = classeEvento;
    } else{
        throw std::invalid_argument("Classe de evento fora do padrao");
    }
}

Classe_De_Evento::Classe_De_Evento(){
    classeEvento = "0";
}

std::istream& operator>>(std::istream& in, Classe_De_Evento& classeEvento){
    std::string str;

    in >> str;
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    classeEvento.setClasseEvento(str);

    return in;
}
