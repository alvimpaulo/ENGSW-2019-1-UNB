//
// Created by paulo on 04-Sep-18.
//
#ifndef TRABALHO_1_CLION_CODIGO_DE_SEGURANCA_H
#define TRABALHO_1_CLION_CODIGO_DE_SEGURANCA_H

#include <string>
#include <regex>
#include <istream>

/**
 * @brief Domínio que armazena um código de seguranca.
 * @details Domínio que armazena um código de seguranca como uma string no formato XXX onde X é um dígito.
 */
class Codigo_De_Seguranca{
public:
    /**
     * @brief Construtor da classe.
     * @details Construdor da classe que cuida de atribuir um valor padrão ao código de seguranca na sua criação.
     */
    Codigo_De_Seguranca();

    /**
     * @brief Função que retorna o código de seguranca em forma de String.
     * @return Código de seguranca consistente com o padrão.
     */
    std::string getCodigoSeguranca() const{
        return codigoSeguranca;
    }
    /**
     * @brief Atribui um novo valor ao código de seguranca.
     * @details Atribui um novo valor caso esse valor seja consistente com o padrão, lança exceção em caso de falha.
     * @param codigoSeguranca Código de seguranca a ser atribuído em formato String.
     */
    void setCodigoSeguranca(std::string codigoSeguranca);

    friend std::istream& operator>>(std::istream& in, Codigo_De_Seguranca& codigo);

private:
    std::string codigoSeguranca;
};


#endif //TRABALHO_1_CLION_CODIGO_DE_SEGURANCA_H
