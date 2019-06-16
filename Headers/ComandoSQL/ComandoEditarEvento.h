//
// Created by paulo on 16/06/19.
//

#ifndef TRABALHO_1_CLION_COMANDOEDITAREVENTO_H
#define TRABALHO_1_CLION_COMANDOEDITAREVENTO_H

#include "ComandoSQL.h"
#include "../Entidades/Evento.h"
#include "../Entidades/Usuario.h"


class ComandoEditarEvento : public ComandoSQL {
public:
    Evento getEvento(const Codigo_De_Evento& codigoDeEvento, const Usuario& usuario);
    void editarEvento(const Evento& evento, const Usuario& usuario);
};


#endif //TRABALHO_1_CLION_COMANDOEDITAREVENTO_H
