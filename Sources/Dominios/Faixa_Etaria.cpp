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
    std::transform(faixaEtaria.begin(), faixaEtaria.end(), faixaEtaria.begin(), ::toupper);
    if(validar(faixaEtaria)){
        this->indiceFaixaEtaria = std::lower_bound(FAIXA_ETARIA.begin(), FAIXA_ETARIA.end(), faixaEtaria) - FAIXA_ETARIA.begin();
    } else{
        throw (std::invalid_argument(faixaEtaria + "nao eh uma faixa etaria valida"));
    }
}

bool Faixa_Etaria::validar(std::string faixaEtaria){
    int indiceFaixaEtaria;

    indiceFaixaEtaria = std::lower_bound(FAIXA_ETARIA.begin(), FAIXA_ETARIA.end(), faixaEtaria) - FAIXA_ETARIA.begin();

    if(FAIXA_ETARIA[indiceFaixaEtaria] == faixaEtaria){
        return true;
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