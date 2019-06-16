//
// Created by paulo on 16/06/19.
//

#ifndef TRABALHO_1_CLION_COMANDODESCADASTRAREVENTO_H
#define TRABALHO_1_CLION_COMANDODESCADASTRAREVENTO_H

#include "ComandoSQL.h"
#include "../Entidades/Evento.h"
#include "../Entidades/Usuario.h"

class ComandoDescadastrarEvento: public ComandoSQL {
public:
    void descadastrarEvento(const Codigo_De_Evento& codigoDeEvento, const Usuario& usuario);
};


#endif //TRABALHO_1_CLION_COMANDODESCADASTRAREVENTO_H
