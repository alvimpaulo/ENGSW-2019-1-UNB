//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRSSERVUSUARIOS_H
#define TRABALHO_1_CLION_CNTRSSERVUSUARIOS_H


#include "../../Interfaces/Servico/InterServUsuarios.h"

class CntrsServUsuarios: public InterServUsuarios{
public:
    //cadastra um usuario no sistema
    void cadastrarUsuario(const Cpf& cpf, const Senha& senha) override;

    //Descadastra um usuario, se for possivel
    void descadastrarUsuario(const Usuario& usuario) override;

};


#endif //TRABALHO_1_CLION_CNTRSSERVUSUARIOS_H
