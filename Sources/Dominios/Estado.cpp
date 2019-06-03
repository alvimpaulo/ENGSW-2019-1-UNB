//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Estado.h"


const std::vector<std::string> Estado::NOME_ESTADOS = {
        "AC", "AL", "AP", "AM",
        "BA", "CE", "DF", "ES",
        "GO", "MA", "MT", "MS",
        "MG", "PA", "PB", "PR",
        "PE", "PI", "RJ", "RN",
        "RS", "RO", "RR", "SC",
        "SP", "SE", "TO"
};

Estado::Estado(){
    indiceEstado = 0;
}

void Estado::setEstado(std::string estado){
    std::transform(estado.begin(), estado.end(), estado.begin(), ::toupper);
    if(validar(estado)){
        this->indiceEstado = std::lower_bound(NOME_ESTADOS.begin(), NOME_ESTADOS.end(), estado) - NOME_ESTADOS.begin();
    } else{
        throw (std::invalid_argument(estado + "nao eh uma sigla de estado valida"));
    }
}

bool Estado::validar(std::string estado){
    int indiceEstado;

    indiceEstado = std::lower_bound(NOME_ESTADOS.begin(), NOME_ESTADOS.end(), estado) - NOME_ESTADOS.begin();

    if(NOME_ESTADOS[indiceEstado] == estado){
        return true;
    } else{
        return false;
    }
}

std::istream& operator>>(std::istream& in, Estado& estado){
    std::string str;

    in >> str;
    estado.setEstado(str);

    return in;
}