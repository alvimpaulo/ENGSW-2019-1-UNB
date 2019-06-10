//
// Created by paulo on 04-Sep-18.
//
#ifndef TRABALHO_1_CLION_Codigo_De_Ingresso_H
#define TRABALHO_1_CLION_Codigo_De_Ingresso_H

#include <string>
#include <regex>
#include <istream>

/**
 * @brief Domínio que armazena um código do ingresso.
 * @details Domínio que armazena um código do ingresso como uma string no formato XXXXX onde X é um dígito.
 */
class Codigo_De_Ingresso{
public:
    /**
     * @brief Construtor da classe.
     * @details Construdor da classe que cuida de atribuir um valor padrão ao código do ingresso na sua criação.
     */
    Codigo_De_Ingresso();

    /**
     * @brief Função que retorna o código do ingresso em forma de String.
     * @return Código do ingresso consistente com o padrão.
     */
    std::string getCodigoIngresso() const{
        return codigoIngresso;
    }
    /**
     * @brief Atribui um novo valor ao código do ingresso.
     * @details Atribui um novo valor caso esse valor seja consistente com o padrão, lança exceção em caso de falha.
     * @param codigoIngresso Código do ingresso a ser atribuído em formato String.
     */
    void setCodigoIngresso(std::string codigoIngresso);

    friend std::istream& operator>>(std::istream& in, Codigo_De_Ingresso& codigo);

private:
    std::string codigoIngresso;
};


#endif //TRABALHO_1_CLION_Codigo_De_Ingresso_H
