//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_NUM_DE_SALA_H
#define TRABALHO_1_CLION_NUM_DE_SALA_H
#include <string>
#include <regex>
#include <stdexcept>

/**
 * @brief Classe que armazena o numero de salas.
 * @details Classe que armazena em forma de String, o numero de salas, sendo esse um numero entre 1 a 10.
 */
class Num_De_Sala{
public:
    /**
     * @brief Retorna o valor de numero de salas.
     */
    std::string getNumSala() const{
        return numSala;
    }
    /**
     * @brief Atribui um novo valor ao numero de salas.
     * @details Testa o novo numero de salas contra o padrão e atribui um novo valor ao numero de sala em caso de sucesso ou lança uma exceção em caso de falha.
     * @param Capacidade String contendo o novo valor a ser testado.
     */
    void setNumSala(std::string numero);


    friend std::istream& operator>>(std::istream& in, Num_De_Sala& numSala);

private:
    bool validar(std::string numero);
    std::string numSala;
};


#endif //TRABALHO_1_CLION_NUM_DE_SALA_H
