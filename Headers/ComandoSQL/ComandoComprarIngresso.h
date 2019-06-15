//
// Created by paulo on 15/06/19.
//

#ifndef TRABALHO_1_CLION_COMANDOCOMPRARINGRESSO_H
#define TRABALHO_1_CLION_COMANDOCOMPRARINGRESSO_H

#include "ComandoSQL.h"
#include "../Entidades/Apresentacao.h"
#include "../Entidades/Usuario.h"

class ComandoComprarIngresso : public ComandoSQL{
public:
    ComandoComprarIngresso();


    std::list<std::string> comprarIngresso(const Usuario &usuario, int qtdIngresso,
                                           const Codigo_De_Apresentacao &codigoDeApresentacao);

private:
    std::string getLastIngresso();


};


#endif //TRABALHO_1_CLION_COMANDOCOMPRARINGRESSO_H
