//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_DATA_DE_VALIDADE_H
#define TRABALHO_1_CLION_DATA_DE_VALIDADE_H

#include <regex>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

/**
 * @brief Domínio que armazena uma data de validade.
 * @details Domínio que armazena uma data de validade Essa classe armazena uma data de validade do cartão de crédito no formato “MM/AA”, onde MM  é um número entre 01 e 12 composto por 2 algarismos e AA é um número entre 00 e 99 composto número composto, também, por 2 algarismos.
 */
class Data_De_Validade{
public:
    /**
     * @brief Limite mínimo do ano.
     */
    static const int LIMITE_INFERIOR_ANO = 00;
    /**
     * @brief Limite máximo do ano.
     */
    static const int LIMITE_SUPERIOR_ANO = 99;
    /**
     * @brief Limite mínimo do mes.
     */
    static const int LIMITE_INFERIOR_MES = 01;
    /**
     * @brief Limite máximo do mes.
     */
    static const int LIMITE_SUPERIOR_MES = 12;

    /**
     * @brief Contrutor da classe.
     * @details Quando uma instância dessa classe for criada, será armazenado um valor padrão de uma data de validade.
     */
    Data_De_Validade();
    /**
     * @brief Atribui uma data de validade.
     * @details Atribui uma data de validade, se estiver no padrão da classe, e lança uma exceção, caso contrário.
     * @param data String data de validade no fomato "MM/AA"
     */
    void setData_De_Validade(std::string data);
    /**
     * @brief Atribui uma data de validade.
     * @details Atribui uma data de validade, se estiver no padrão da classe, e lança uma exceção, caso contrário.
     * @param dia String que representa o mês da data de validade.
     * @param mes String que representa o ano da data de validade.
     */
    void setData_De_Validade(std::string dia, std::string mes);
    /**
     * @brief Retorna uma string que contém a data de validade
     * @details Retorna uma string que contém a date de validade
     * @return String que contém a data de validade.
     */
    std::string getData_De_Validade() const{
        return data;
    }

    friend std::istream& operator>>(std::istream& in, Data_De_Validade& dataDeValidade);

protected:
private:
    std::string mes;
    std::string ano;
    std::string data;

    void setMes(std::string mes);
    std::string getMes() const;
    void setAno(std::string ano);
    std::string getAno() const;

    bool validar(std::string data);
    bool validarMes(std::string mes);
    bool validarAno(std::string ano);
};

#endif //TRABALHO_1_CLION_DATA_DE_VALIDADE_H
