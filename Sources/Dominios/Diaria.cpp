//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Diaria.h"

Diaria::Diaria(){
    diaria = 0.0f;
}

void Diaria::setDiaria(std::string diaria){
    if(validar(diaria)){
        this->diaria = (std::round(std::stof(diaria)*100)/100.0);
    } else{
        throw (std::invalid_argument(diaria + "nao eh uma diaria valida"));
    }
}

bool Diaria::validar(std::string diaria){
    std::regex nomeRegex(R"((\d+)(\.)(\d+))");

    if(std::regex_match(diaria, nomeRegex)){
        float tmpDiaria = std::stof(diaria);
        if(LIMITE_MINIMO_DIARIA <= tmpDiaria && tmpDiaria <= LIMITE_MAXIMO_DIARIA){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }
}

std::istream& operator>>(std::istream& in, Diaria& diaria){
    std::string str;

    in >> str;
    diaria.setDiaria(str);

    return in;
}