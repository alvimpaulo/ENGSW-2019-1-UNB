//
// Created by paulo on 10/06/19.
//

#ifndef TRABALHO_1_CLION_HORARIO_H
#define TRABALHO_1_CLION_HORARIO_H

#include <string>
#include <regex>
#include <istream>

/**
 * @brief Domínio que armazena um horario.
 * @details Domínio que armazena um horario como uma string no formato HH:MM onde HH e um numero de 07 a 22 e MM e 00,15,30 ou 45.
 */
class Horario{
public:
    /**
     * @brief Construtor da classe.
     * @details Construdor da classe que cuida de atribuir um valor padrão ao horario na sua criação.
     */
    Horario();

    /**
     * @brief Função que retorna o horario em forma de String.
     * @return Horario consistente com o padrão.
     */
    std::string getHorario() const{
        return horario;
    }
    /**
     * @brief Atribui um novo valor ao horario.
     * @details Atribui um novo valor caso esse valor seja consistente com o padrão, lança exceção em caso de falha.
     * @param horario Horario a ser atribuído em formato String.
     */
    void setHorario(std::string horario);

    friend std::istream& operator>>(std::istream& in, Horario& horario);

private:
    std::string horario;
};


#endif //TRABALHO_1_CLION_HORARIO_H
