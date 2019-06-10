//
// Created by paulo on 10/06/19.
//

#ifndef TRABALHO_1_CLION_CPF_H
#define TRABALHO_1_CLION_CPF_H


#include <string>
#include <regex>
#include <istream>

/**
 * @brief Domínio que armazena um cpf.
 * @details Domínio que armazena um cpf como uma string no formato XXX.XXX.XXX-XX onde X é um dígito.
 */
class Cpf{
public:
    /**
     * @brief Construtor da classe.
     * @details Construdor da classe que cuida de atribuir um valor padrão ao cpf na sua criação.
     */
    Cpf();

    /**
     * @brief Função que retorna o cpf em forma de String.
     * @return Cpf consistente com o padrão.
     */
    std::string getCpf() const{
        return cpf;
    }
    /**
     * @brief Atribui um novo valor ao cpf.
     * @details Atribui um novo valor caso esse valor seja consistente com o padrão, lança exceção em caso de falha.
     * @param cpf Cpf a ser atribuído em formato String.
     */
    void setCpf(std::string cpf);

    friend std::istream& operator>>(std::istream& in, Cpf& cpf);

private:
    std::string cpf;
};

#endif //TRABALHO_1_CLION_CPF_H
