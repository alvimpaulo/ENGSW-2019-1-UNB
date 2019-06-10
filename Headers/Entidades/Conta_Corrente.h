//
// Created by oetch on 16/09/2018.
//

#ifndef TRABALHO_1_CLION_CONTA_CORRENTE_H
#define TRABALHO_1_CLION_CONTA_CORRENTE_H

#include "../../Headers/Dominios/Num_Conta_Corrente.h"
#include "../../Headers/Dominios/Agencia.h"
#include "../Dominios/Codigo_De_Evento.h"

/**
 * @brief Entidade que trata de uma conta conrrente.
 * @details Entidade que trata de uma conta conrrente contendo os domínios Numero de conta conrrente, Agência e banco.
 */
class Conta_Corrente{
public:
    /**
     * @brief Construtor que inicializa os domínios contidos nessa entidade.
     */
    Conta_Corrente():numero(),agencia(),banco(){}

    /**
     * @brief Atribui um novo número (Domínio) à conta corrente,
     * @param numero Novo número a ser atribuido à conta.
     */
    void setNumero(Num_Conta_Corrente numero){
        this->numero = numero;
    }

    /**
     * @brief Retorna o número (domínio) atual da conta corrente.
     * @return Numero (Domínio) a ser retornado.
     */
    Num_Conta_Corrente getNumero() const{
        return numero;
    }

    /**
     * @brief Atribui uma nova Agência (Domínio) à conta corrente,
     * @param agencia Nova agência a ser atribuido à conta.
     */
    void setAgencia(Agencia agencia){
        this->agencia = agencia;
    }

    /**
     * @brief Retorna a agência (domínio) atual da conta corrente.
     * @return Agência (Domínio) a ser retornada.
     */
    Agencia getAgencia() const{
        return agencia;
    }

    /**
     * @brief Atribui um novo banco (Domínio) à conta corrente,
     * @param banco Novo banco a ser atribuido à conta.
     */
    void setBanco(Codigo_De_Evento banco){
        this->banco = banco;
    }

    /**
     * @brief Retorna o banco (domínio) atual da conta corrente.
     * @return Banco (Domínio) a ser retornada.
     */
    Codigo_De_Evento getBanco() const{
        return banco;
    }

protected:
private:
    Num_Conta_Corrente numero;
    Agencia agencia;
    Codigo_De_Evento banco;
};


#endif //TRABALHO_1_CLION_CONTA_CORRENTE_H
