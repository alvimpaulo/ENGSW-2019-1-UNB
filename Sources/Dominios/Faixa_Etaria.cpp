//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Faixa_Etaria.h"


const std::vector<std::string> Faixa_Etaria::FAIXA_ETARIA = {
        "L", "10", "12", "14", "16", "18"
};

Faixa_Etaria::Faixa_Etaria(){
    indiceFaixaEtaria = 0;
}

void Faixa_Etaria::setFaixaEtaria(std::string faixaEtaria){
    if(validar(faixaEtaria)){
        this->indiceFaixaEtaria = std::find(FAIXA_ETARIA.begin(), FAIXA_ETARIA.end(), faixaEtaria) - FAIXA_ETARIA.begin();
    } else{
        throw (std::invalid_argument(faixaEtaria + "nao eh uma faixa etaria valida"));
    }
}

bool Faixa_Etaria::validar(std::string faixaEtaria){
    std::regex nomeRegex(R"(L|(1[02468]))");
    if(std::regex_match(faixaEtaria, nomeRegex)){
        if(std::find(FAIXA_ETARIA.begin(), FAIXA_ETARIA.end(), faixaEtaria) != FAIXA_ETARIA.end()){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }
}

std::istream& operator>>(std::istream& in, Faixa_Etaria& faixaEtaria){
    std::string str;

    in >> str;
    faixaEtaria.setFaixaEtaria(str);

    return in;
}