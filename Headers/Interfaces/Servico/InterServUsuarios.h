//
// Created by paulo on 17-Nov-18.
//

#ifndef TRABALHO_1_CLION_INTERSERVUSUARIOS_H
#define TRABALHO_1_CLION_INTERSERVUSUARIOS_H

#include "../../Entidades/Usuario.h"
#include "../../Entidades/Conta_Corrente.h"
#include "../../Entidades/Cartao_De_Credito.h"


class InterServUsuarios{
public:
    //cadastra um usuario no sistema
    virtual void cadastrarUsuario(const Cidade& nome, const Identificador& identificador, const Senha& senha) = 0;

    //Cadastra uma conta corrente para o usuario atual
    virtual void cadastrarContaCorrente(const Identificador &identificador, const Num_Conta_Corrente& numContaCorrente, const Agencia& agencia, const Codigo_De_Evento& banco) = 0;

    //Cadastra uma conta corrente para o usuario atual
    virtual void cadastrarCartaoCredito(const Identificador &identificador, const Num_Cartao_Credito& numCartaoCredito, const Data_De_Validade& dataDeValidade) = 0;

    //Descadastra um usuario, se for possivel
    virtual void descadastrarUsuario(const Identificador &identificador) = 0;

    //Descastra uma conta corrente do usuario atual
    virtual void descadastrarContaCorrente(const Num_Conta_Corrente& numContaCorrente) = 0;

    //Descadastra um cartao de credito do usuario atual
    virtual void descadastrarCartaoCredito(const Num_Cartao_Credito& numCartaoCredito) = 0;

    //Edita o nome e/ou senha do usuario atual
    virtual void editarUsuario(const Cidade& nome, const Senha& senha, const Identificador &identificador) = 0;

};


#endif //TRABALHO_1_CLION_INTERSERVUSUARIOS_H
