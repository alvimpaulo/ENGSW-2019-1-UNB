//
// Created by paulo on 14/06/19.
//

#ifndef TRABALHO_1_CLION_COMANDOSOLICITARINFORMACAODEVENDAS_H
#define TRABALHO_1_CLION_COMANDOSOLICITARINFORMACAODEVENDAS_H

#include "../Entidades/Evento.h"
#include "../Entidades/Usuario.h"
#include "ComandoSQL.h"

class ComandoSolicitarInformacaoDeVendas: public ComandoSQL{
public:
    explicit ComandoSolicitarInformacaoDeVendas(const Codigo_De_Evento& codigoDeEvento);
    std::list<Cpf> getCpfs();

};


#endif //TRABALHO_1_CLION_COMANDOSOLICITARINFORMACAODEVENDAS_H
