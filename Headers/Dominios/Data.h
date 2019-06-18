//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_DATA_H
#define TRABALHO_1_CLION_DATA_H

#include <regex>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

/**
 * @brief Domínio que armazena uma data.
 * @details  Domínio armazena uma data conforme o formato "DD/MMM/AAAA", onde DD é um número de 01 a 31, MMM é a inicial dos meses do ano (jan, fev, mar, abr, mai, jun, jul, ago, set, out, nov ou dez) e AAAA é um número de 2000 a 2099.
 */
class Data{
public:
    /**
     * @brief Limite mínimo do dia.
     */
    static const int LIMITE_INFERIOR_DIA = 1;
    /**
     * @brief Limites máximo do dia.
     */
    static const std::vector<int> LIMITE_SUPERIOR_DIA;

    /**
     * @brief Contrutor da classe.
     * @details Quando uma instância dessa classe for criada, será armazenado um valor padrão de uma data.
     */
    Data();
    /**
     * @brief Atribui uma data.
     * @details Atribui uma data, caso esteja no padrão da classe, e lança uma exceção, caso contrário.
     * @param data String que deve conter uma no formato padrão.

     */
    void setData(std::string data);
    /**
     * @brief Atribui uma data.
     * @details Atribui uma data, caso esteja no padrão da classe, e lança uma exceção, caso contrário.
     * @param dia String contendo o dia da data.
     * @param mes String contendo o mes da data.
     * @param ano String contendo o ano da data.
     */
    void setData(std::string dia, std::string mes, std::string ano);
    /**
     * @brief Retorna uma string que contém a data.
     * @return data String que contém a data.
     */
    std::string getData() const{
        return data;
    }

    /**
     * @brief Compara duas datas.
     * @details Compara duas datas, data1 e data2, e retorna true se a data1 vem antes da data2.
     * @param data1 Instância da class Data.
     * @param data2 Instância da class Data.
     * @return Booleano true, se a data1 vem antes da data2, ou false, caso contrário.
     */
    friend bool operator<(const Data& data1, const Data& data2);
    /**
     * @brief Compara duas datas.
     * @details Compara duas datas, data1 e data2, e retorna true se a data1 vem depois da data2.
     * @param data1 Instância da class Data.
     * @param data2 Instância da class Data.
     * @return Booleano true, se a data1 vem depois da data2, ou false, caso contrário.
     */
    friend bool operator>(const Data& data1, const Data& data2);


    friend std::istream& operator>>(std::istream& in, Data& data);

    friend bool operator==(const Data& data1, const Data& data2);
    friend bool operator<=(const Data& data1, const Data& data2);
    friend bool operator>=(const Data& data1, const Data& data2);

protected:
private:
    std::string dia;
    std::string mes;
    std::string ano;
    std::string data;


    void setDia(std::string dia);
    std::string getDia() const;
    void setMes(std::string mes);
    std::string getMes() const;
    void setAno(std::string ano);
    std::string getAno() const;

    bool validar(std::string data);
    bool validarDia(std::string dia);
    bool validarMes(std::string mes);
    bool validarAno(std::string ano);
};



#endif //TRABALHO_1_CLION_DATA_H
