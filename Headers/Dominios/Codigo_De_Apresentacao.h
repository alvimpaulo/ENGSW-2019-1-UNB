//
// Created by paulo on 04-Sep-18.
//
#ifndef TRABALHO_1_CLION_Codigo_De_Apresentacao_H
#define TRABALHO_1_CLION_Codigo_De_Apresentacao_H

#include <string>
#include <regex>
#include <istream>

/**
 * @brief Domínio que armazena um código da apresentacao.
 * @details Domínio que armazena um código da apresentacao como uma string no formato XXXX onde X é um dígito.
 */
class Codigo_De_Apresentacao{
public:
    /**
     * @brief Construtor da classe.
     * @details Construdor da classe que cuida de atribuir um valor padrão ao código da apresentacao na sua criação.
     */
    Codigo_De_Apresentacao();

    /**
     * @brief Função que retorna o código da apresentacao em forma de String.
     * @return Código da apresentacao consistente com o padrão.
     */
    std::string getCodigoApresentacao() const{
        return codigoApresentacao;
    }
    /**
     * @brief Atribui um novo valor ao código da apresentacao.
     * @details Atribui um novo valor caso esse valor seja consistente com o padrão, lança exceção em caso de falha.
     * @param codigoApresentacao Código da apresentacao a ser atribuído em formato String.
     */
    void setCodigoApresentacao(std::string codigoApresentacao);

    friend std::istream& operator>>(std::istream& in, Codigo_De_Apresentacao& codigo);

private:
    std::string codigoApresentacao;
};


#endif //TRABALHO_1_CLION_Codigo_De_Apresentacao_H
