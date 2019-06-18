//
// Created by paulo on 04-Sep-18.
//

// codigo para a validação: (( (?! ))|(\w)){20}

#include "../../Headers/Dominios/Nome_De_Evento.h"

Nome_De_Evento::Nome_De_Evento(){
    nomeDeEvento = "NomeNaoDefinidoMesmo";
}

void Nome_De_Evento::setNome_De_Evento(std::string nomeDeEvento){
    std::regex nomeRegex(R"((( (?! ))|(\w)){20})");
    std::smatch results;

    if(std::regex_match(nomeDeEvento, nomeRegex)){
        this->nomeDeEvento = nomeDeEvento;
    } else{
        throw (std::invalid_argument("Nome De Evento Invalido"));
    }

}

std::istream& operator>>(std::istream& in, Nome_De_Evento& nome){
    std::string str;

    in >> str;

    nome.setNome_De_Evento(str);

    return in;
}