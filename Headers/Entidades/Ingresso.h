//
// Created by paulo on 10/06/19.
//

#ifndef TRABALHO_1_CLION_INGRESSO_H
#define TRABALHO_1_CLION_INGRESSO_H

#include "../Dominios/Codigo_De_Ingresso.h"

/**
 * @brief Entidade que trata de um ingresso.
 */
class Ingresso {
public:

    /**
     * @brief Construtor que inicializa os domínios contidos nessa entidade.
     */
    Ingresso():codigoDeIngresso(){}

    /**
     * @brief Atribui um novo codigo de ingresso a entidade.
     * @param codigoDeIngresso Novo codigo de ingresso a ser atribuido ao ingresso.
     */
    void setCodigoDeIngresso(Codigo_De_Ingresso codigoDeIngresso){
        this->codigoDeIngresso = codigoDeIngresso;
    }

    /**
     * @brief Retorna o codigo de ingresso atual.
     * @return Codigo de ingresso a ser retornado.
     */
    Codigo_De_Ingresso getCodigoDeIngresso(){
        return codigoDeIngresso;
    }
private:
    Codigo_De_Ingresso codigoDeIngresso;

};


#endif //TRABALHO_1_CLION_INGRESSO_H
