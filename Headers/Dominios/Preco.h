//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_PRECO_H
#define TRABALHO_1_CLION_PRECO_H

#include <regex>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>

/**
 * @brief Domínio que armazena o preço de um ingresso.
 * @details Domínio que armazena o preço de um ingresso, sendo que esse preço está entre R$0,00 e R$1000,00.
 */
class Preco{
public:
    /**
     * @brief Limite mínimo do preço.
     */
    static const constexpr float LIMITE_MINIMO_PRECO = 0.00f;
    /**
     * @brief Limite máximo do preço.
     */
    static const constexpr float LIMITE_MAXIMO_PRECO = 1000.00f;

    /**
     * @brief Contrutor da classe.
     * @details Quando uma instância dessa classe for criada, será armazenado um valor padrão do preço de um ingreeso.
     */
    Preco();
    /**
     * @brief Atribui um preço.
     * @details Atribui o preço de um ingresso no formato de uma string que contém um número decimal, esse número está entre 0,00 e 1000,00.
     * @param preco String que contém um número decimal, valor do ingresso.
     */
    void setPreco(std::string preco);
    /**
     * @brief Retorna um número que contém a data de validade.
     * @details Retorna um número que contém a data de validade.
     * @return Float com o valor da diária.
     */
    float getPreco() const{
        return preco;
    }


    friend std::istream& operator>>(std::istream& in, Preco& diaria);

protected:
private:
    float preco;

    bool validar(std::string preco);
};


#endif //TRABALHO_1_CLION_PRECO_H
