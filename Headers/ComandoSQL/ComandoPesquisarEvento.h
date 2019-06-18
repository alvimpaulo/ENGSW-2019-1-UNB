//
// Created by paulo on 16/06/19.
//

#ifndef TRABALHO_1_CLION_COMANDOPESQUISAREVENTO_H
#define TRABALHO_1_CLION_COMANDOPESQUISAREVENTO_H

#include "ComandoSQL.h"
#include "../Entidades/Evento.h"
#include "../Entidades/Apresentacao.h"
#include "../Dominios/Data.h"
class ComandoPesquisarEvento : public ComandoSQL{
public:
    std::list<std::pair<Evento, Apresentacao> >
    pesquisarEvento(const Data &dataInicio, const Data &dataTermino, const Cidade &cidade, const Estado &estado);
};


#endif //TRABALHO_1_CLION_COMANDOPESQUISAREVENTO_H
