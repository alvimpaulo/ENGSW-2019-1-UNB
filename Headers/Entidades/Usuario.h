//
// Created by oetch on 16/09/2018.
//


#ifndef TRABALHO_1_CLION_USUARIO_H
#define TRABALHO_1_CLION_USUARIO_H

#include "../../Headers/Dominios/Nome.h"
#include "../../Headers/Dominios/Identificador.h"
#include "../../Headers/Dominios/Senha.h"

/**
 * @brief Entidade que trata de um usuário.
 * @details Entidade que trata de um usuário contendo os domínios Nome, Identificador e Senha.
 */
class Usuario{
public:

    /**
     * @brief Construtor que inicializa os domínios contidos nessa entidade.
     */
    Usuario():nome(),identificador(),senha(){}

    /**
     * @brief Atribui um novo nome (Domínio) à conta corrente,
     * @param nome Novo nome a ser atribuído à conta.
     */
    void setNome(Nome nome){
        this->nome = nome;
    }

    /**
     * @brief Retorna o nome (domínio) atual da conta corrente.
     * @return Nome (Domínio) a ser retornado.
     */
    Nome getNome(){
        return nome;
    }

    /**
     * @brief Atribui um novo identificador (Domínio) à conta corrente,
     * @param identificador Novo identificador a ser atribuído à conta.
     */
    void setIdentificador(Identificador identificador){
        this->identificador = identificador;
    }

    /**
     * @brief Retorna o identificador (domínio) atual da conta corrente.
     * @return Identificador (Domínio) a ser retornado.
     */
    Identificador getIdentificador(){
        return identificador;
    }

    /**
    * @brief Atribui uma nova senha (Domínio) à conta corrente,
    * @param senha Nova senha a ser atribuída à conta.
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
    Nome nome;
    Identificador identificador;
    Senha senha;
};


#endif //TRABALHO_1_CLION_USUARIO_H
