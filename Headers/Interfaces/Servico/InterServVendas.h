//
// Created by paulo on 12/06/19.
//

#ifndef TRABALHO_1_CLION_INTERSERVVENDAS_H
#define TRABALHO_1_CLION_INTERSERVVENDAS_H

#include "../../Entidades/Apresentacao.h"
#include "../../Entidades/Evento.h"
#include "../../Entidades/Usuario.h"
#include "list"

class InterServVendas {
public:
    virtual std::list<std::string>
    comprarIngresso(const Usuario &usuario, const Codigo_De_Apresentacao &codigoDeApresentacao, int qtdIngresso) = 0;
    virtual std::list<Cpf> solicitarInformacaoDeVendas(const Codigo_De_Evento &codigoDeEvento) = 0;

};


#endif //TRABALHO_1_CLION_INTERSERVVENDAS_H
