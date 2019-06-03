//
// Created by paulo on 18-Nov-18.
//

#ifndef TRABALHO_1_CLION_COMANDOEDITARACOMODACAO_H
#define TRABALHO_1_CLION_COMANDOEDITARACOMODACAO_H

#include "ComandoSQL.h"
#include "../Entidades/Acomodacao.h"

class ComandoEditarAcomodacao : public ComandoSQL {
public:
    ComandoEditarAcomodacao(const Identificador& identificadorAcomodacao, const Acomodacao& acomodacao);
};


#endif //TRABALHO_1_CLION_COMANDOEDITARACOMODACAO_H
