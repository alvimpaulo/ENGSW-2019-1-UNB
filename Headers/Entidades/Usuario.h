//
// Created by oetch on 16/09/2018.
//


#ifndef TRABALHO_1_CLION_USUARIO_H
#define TRABALHO_1_CLION_USUARIO_H

#include "../../Headers/Dominios/Cpf.h"
#include "../../Headers/Dominios/Senha.h"

/**
 * @brief Entidade que trata de um usuário.
 * @details Entidade que trata de um usuário contendo os domínios Cpf e Senha.
 */
class Usuario{
public:

    /**
     * @brief Construtor que inicializa os domínios contidos nessa entidade.
     */
    Usuario():cpf(),senha(){}

    /**
     * @brief Atribui um novo cpf ao usuario.
     * @param cpf Novo cpf a ser atribuido ao usuario.
     */
    void setCpf(Cpf cpf){
        this->cpf = cpf;
    }

    /**
     * @brief Retorna o cpf atual do usuario.
     * @return Cpf a ser retornado
     */
    Cpf getCpf() const {
        return cpf;
    }

    /**
    * @brief Atribui uma nova senha (Domínio) ao usuario,
    * @param senha Nova senha a ser atribuída ao usuario.
    */
    void setSenha(Senha senha){
        this->senha = senha;
    }

    /**
     * @brief Retorna a senha (domínio) atual da conta corrente.
     * @return Senha (Domínio) a ser retornada.
     */
    Senha getSenha(){
        return senha;
    }

protected:
private:
    Cpf cpf;
    Senha senha;
};


#endif //TRABALHO_1_CLION_USUARIO_H
