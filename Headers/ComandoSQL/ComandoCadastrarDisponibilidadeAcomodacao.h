//
// Created by paulo on 18-Nov-18.
//

#ifndef TRABALHO_1_CLION_COMANDOCADASTRARDISPONIBILIDADEACOMODACAO_H
#define TRABALHO_1_CLION_COMANDOCADASTRARDISPONIBILIDADEACOMODACAO_H

#include "ComandoSQL.h"
#include "../Entidades/Acomodacao.h"

class ComandoCadastrarDisponibilidadeAcomodacao: public ComandoSQL {
public:
    ComandoCadastrarDisponibilidadeAcomodacao(const Identificador& identificadorAcomodacao, const Data& dataInicio, const Data& dataTermino, const Identificador& identificadorUsuario);
    void cadastrarDisponibilidadeAcomodacao(const Identificador& identificadorAcomodacao, const Data& dataInicio, const Data& dataTermino, const Identificador& identificadorUsuario);
    //void cadastrar();
    void cadastrar();
};


#endif //TRABALHO_1_CLION_COMANDOCADASTRARDISPONIBILIDADEACOMODACAO_H
