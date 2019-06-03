//
// Created by paulo on 21-Nov-18.
//

#ifndef TRABALHO_1_CLION_COMANDODESCADASTRARDISPONIBILIDADE_H
#define TRABALHO_1_CLION_COMANDODESCADASTRARDISPONIBILIDADE_H

#include "ComandoSQL.h"
#include "../Entidades/Acomodacao.h"

class ComandoDescadastrarDisponibilidade : public ComandoSQL{
public:
    ComandoDescadastrarDisponibilidade(const Identificador &identificadorAcomodacao,
                                           const Identificador &identificadorUsuario,
                                           const Data &dataInicio,
                                           const Data &dataTermino);
};


#endif //TRABALHO_1_CLION_COMANDODESCADASTRARDISPONIBILIDADE_H
