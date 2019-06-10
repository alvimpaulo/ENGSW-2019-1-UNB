//
// Created by paulo on 10/06/19.
//

#ifndef TRABALHO_1_CLION_DISPONIBILIDADE_H
#define TRABALHO_1_CLION_DISPONIBILIDADE_H

#include <string>
#include <regex>
#include <stdexcept>

/**
 * @brief Classe que armazena a disponibilidade.
 * @details Classe que armazena em forma de String,  disponibilidade, sendo essa disponibilidade entre 1 e 250.
 */
class Disponibilidade{
public:
    /**
     * @brief Retorna o valor da disponibilidade.
     */
    std::string getDisponibilidade() const{
        return disponibilidade;
    }
    /**
     * @brief Atribui um novo valor a disponibilidade .
     * @details Testa a disponibilidade contra o padrão e atribui um novo valor ao disponibilidade de sala em caso de sucesso ou lança uma exceção em caso de falha.
     * @param Capacidade String contendo o novo valor a ser testado.
     */
    void setDisponibilidade(std::string disponibilidade);


    friend std::istream& operator>>(std::istream& in, Disponibilidade& disponibilidade);

private:
    bool validar(std::string disponibilidade);
    std::string disponibilidade;
};




#endif //TRABALHO_1_CLION_DISPONIBILIDADE_H
