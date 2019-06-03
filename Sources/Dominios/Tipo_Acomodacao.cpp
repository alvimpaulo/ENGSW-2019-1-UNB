//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Tipo_Acomodacao.h"

const std::vector<std::string> Tipo_Acomodacao::TIPOS_ACOMODACAO = {
        "Apartamento", "Casa", "Flat"
};

Tipo_Acomodacao::Tipo_Acomodacao(){
    indiceTiposAcomodacao = 0;
}

void Tipo_Acomodacao::setTipoAcomodacao(std::string tipoAcomodacao){

    std::transform(tipoAcomodacao.begin() + 1, tipoAcomodacao.end(), tipoAcomodacao.begin() + 1, ::tolower);
    tipoAcomodacao[0] = (char)std::toupper(tipoAcomodacao[0]);
    if(validar(tipoAcomodacao)){
        indiceTiposAcomodacao = std::find(TIPOS_ACOMODACAO.begin(), TIPOS_ACOMODACAO.end(), tipoAcomodacao) - TIPOS_ACOMODACAO.begin();
    } else{
        throw (std::invalid_argument(tipoAcomodacao + "nao eh um tipo de acomodacao valido"));
    }
}

bool Tipo_Acomodacao::validar(std::string tipoAcomodacao){

    std::regex nomeRegex(R"([A-Za-z]{4,11})");
    if(std::regex_match(tipoAcomodacao, nomeRegex)){
        if(std::find(TIPOS_ACOMODACAO.begin(), TIPOS_ACOMODACAO.end(), tipoAcomodacao) != TIPOS_ACOMODACAO.end()){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }
}
