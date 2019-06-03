//
// Created by paulo on 18-Nov-18.
//

#ifndef TRABALHO_1_CLION_COMANDODESCADASTRARACOMODACAO_H
#define TRABALHO_1_CLION_COMANDODESCADASTRARACOMODACAO_H

#include "ComandoSQL.h"
#include "../Entidades/Acomodacao.h"
class ComandoDescadastrarAcomodacao: public ComandoSQL {
public:
    ComandoDescadastrarAcomodacao(const Identificador &identificadorAcomodacao, const Identificador& identificadorUsuario);
};


#endif //TRABALHO_1_CLION_COMANDODESCADASTRARACOMODACAO_H
