//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_TIPO_ACOMODACAO_H
#define TRABALHO_1_CLION_TIPO_ACOMODACAO_H

#include <regex>
#include <stdexcept>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>

/**
 * @brief Domínio que armazena um tipo de acomodação.
 * @details Domínio que armazena um dos 3 tipos de acomodação: Apartamento, Casa ou Flat.
 */
class Tipo_Acomodacao{
public:
    /**
     * @brief Vetor que contém os tipos de acomodações.
     */
    static const std::vector<std::string> TIPOS_ACOMODACAO;

    /**
     * @brief Contrutor da classe.
     * @details Quando uma instância dessa classe for criada, será armazenado um valor padrão do tipo de acomodação.
     */
    Tipo_Acomodacao();
    /**
     * @brief Atribui um tipo de acomodação.
     * @details  Atribui um dos tipos de acomodações, se está contido no vetor Tipo_Acomodacao::TIPOS_ACOMODACAO, e lança uma exceção, caso contrário.
     * @param tipoAcomodacao String que contém um tipo de acomodação.
     */
    void setTipoAcomodacao(std::string tipoAcomodacao);
    /**
     * @brief Retorna uma string que contém um tipo de acomodação.
     * @details Retorna uma string que contém um tipo de acomodação.
     * @return String que contém um tipo de acomodação.
     */
    std::string getTipoAcomodacao() const{
        return TIPOS_ACOMODACAO[indiceTiposAcomodacao];
    }

    friend std::istream& operator>>(std::istream& in, Tipo_Acomodacao& tipoAcomodacao);


protected:
private:
    int indiceTiposAcomodacao;

    bool validar(std::string tipoAcomodacao);
};



#endif //TRABALHO_1_CLION_TIPO_ACOMODACAO_H
