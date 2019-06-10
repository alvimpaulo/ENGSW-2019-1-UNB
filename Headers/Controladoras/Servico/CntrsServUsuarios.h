//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRSSERVUSUARIOS_H
#define TRABALHO_1_CLION_CNTRSSERVUSUARIOS_H


#include "../../Interfaces/Servico/InterServUsuarios.h"

class CntrsServUsuarios: public InterServUsuarios{
public:
    //cadastra um usuario no sistema
    void cadastrarUsuario(const Cidade& nome, const Identificador& identificador, const Senha& senha) override;

    //Cadastra uma conta corrente para o usuario atual
    void cadastrarContaCorrente(const Identificador &identificador, const Num_Conta_Corrente& numContaCorrente, const Agencia& agencia, const Codigo_De_Evento& banco) override;

    //Cadastra uma conta corrente para o usuario atual
    void cadastrarCartaoCredito(const Identificador &identificador, const Num_Cartao_Credito& numCartaoCredito, const Data_De_Validade& dataDeValidade) override;

    //Descadastra um usuario, se for possivel
    void descadastrarUsuario(const Identificador &identificador) override;

    //Descastra uma conta corrente do usuario atual
    void descadastrarContaCorrente(const Num_Conta_Corrente& numContaCorrente) override;

    //Descadastra um cartao de credito do usuario atual
    void descadastrarCartaoCredito(const Num_Cartao_Credito& numCartaoCredito) override;

    //Edita o nome e/ou senha do usuario atual
    void editarUsuario(const Cidade& nome, const Senha& senha, const Identificador &identificador) override;

};


#endif //TRABALHO_1_CLION_CNTRSSERVUSUARIOS_H
