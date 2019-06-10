//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_FAIXA_ETARIA_H
#define TRABALHO_1_CLION_FAIXA_ETARIA_H

#include <regex>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <locale>
#include <iostream>

/**
 * @brief Domínio que armazena a faixa etaria de um evento.
 * @details Domínio que armazena a faixa etaria de um evento.
 */
class Faixa_Etaria{
public:
    /**
     * @brief Vetor que contém as faixas etarias.
     */
    static const std::vector<std::string> FAIXA_ETARIA;

    /**
     * @brief Contrutor da classe.
     * @details Quando uma instância dessa classe for criada, será armazenado um valor padrão da faixa etaria.
     */
    Faixa_Etaria();
    /**
     * @brief Atribui uma faixa etaria.
     * @details Atribui uma faixa etaria, caso esteja presente no vetor Faixa_Etaria::FAIXA_ETARIA, ou lança um exceção, caso contrário.
     * @param faixaEtaria String que contém a faixa etaria de um evento.
     */
    void setFaixaEtaria(std::string faixaEtaria);
    /**
     * @brief Retorna uma string que contém a faixa etaria de evento.
     * @details Retorna uma string que contém faixa etaria de evento.
     * @return String que contém a faixa etaria de um evento.
     */
    std::string getFaixaEtaria() const{
        return FAIXA_ETARIA[indiceFaixaEtaria];
    }

    friend std::istream& operator>>(std::istream& in, Faixa_Etaria& faixaEtaria);

protected:
private:
    int indiceFaixaEtaria;

    bool validar(std::string faixaEtaria);
};


#endif //TRABALHO_1_CLION_FAIXA_ETARIA_H
