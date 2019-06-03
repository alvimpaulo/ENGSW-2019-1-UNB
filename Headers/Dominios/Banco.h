//
// Created by paulo on 04-Sep-18.
//
#ifndef TRABALHO_1_CLION_BANCO_H
#define TRABALHO_1_CLION_BANCO_H

#include <string>
#include <regex>
#include <istream>

/**
 * @brief Domínio que armazena um banco.
 * @details Domínio que armazena um número de banco como uma string no formato XXX onde X é um dígito.
 */
class Banco{
public:
    /**
     * @brief Construtor da classe.
     * @details Construdor da classe que cuida de atribuir um valor padrão ao número do banco na sua criação.
     */
    Banco();

    /**
     * @brief Função que retorna o número do banco em forma de String.
     * @return Número do banco consistente com o padrão.
     */
    std::string getBancoNum() const{
        return bancoNum;
    }
    /**
     * @brief Atribui um novo valor ao número do banco.
     * @details Atribui um novo valor caso esse valor seja consistente com o padrão, lança exceção em caso de falha.
     * @param bancoNum Novo número a ser atribuído em formato String.
     */
    void setBancoNum(std::string bancoNum);

    friend std::istream& operator>>(std::istream& in, Banco& banco);

private:
    std::string bancoNum;
};


#endif //TRABALHO_1_CLION_BANCO_H
