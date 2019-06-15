//
// Created by Oscar Madureira on 18/11/2018.
//

#ifndef TRABALHO_1_CLION_COMANDOCADASTRARUSUARIO_H
#define TRABALHO_1_CLION_COMANDOCADASTRARUSUARIO_H


#include "../Entidades/Usuario.h"
#include "../Entidades/Cartao_De_Credito.h"
#include "ComandoSQL.h"

class ComandoCadastrarUsuario: public ComandoSQL{
public:
    void cadastrarUsuario(const Usuario& usuario, const Cartao_De_Credito& cartaoDeCredito);
};


#endif //TRABALHO_1_CLION_COMANDOCADASTRARUSUARIO_H
