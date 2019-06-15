//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRSERVUSUARIOS_H
#define TRABALHO_1_CLION_CNTRSERVUSUARIOS_H


#include "../../Interfaces/Servico/InterServUsuarios.h"

class CntrServUsuarios: public InterServUsuarios{
public:
    //cadastra um usuario no sistema
    void cadastrarUsuario(const Usuario& usuario, const Cartao_De_Credito& cartaoDeCredito) override;

    //Descadastra um usuario, se for possivel
    void descadastrarUsuario(const Usuario& usuario) override;

};


#endif //TRABALHO_1_CLION_CNTRSERVUSUARIOS_H
