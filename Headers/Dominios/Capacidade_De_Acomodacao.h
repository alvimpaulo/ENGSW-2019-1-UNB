//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_CAPACIDADE_DE_ACOMODACAO_H
#define TRABALHO_1_CLION_CAPACIDADE_DE_ACOMODACAO_H
#include <string>
#include <regex>
#include <stdexcept>

/**
 * @brief Classe que armazena a capacidade de acomodação.
 * @details Classe que armazena em forma de String, a capacidade de acomodação, sendo essa um numero entre 1 a 9.
 */
class Capacidade_De_Acomodacao{
public:
    /**
     * @brief Retorna o valor da capacidade de acomodação.
     */
    std::string getCapacidade_de_Acomodacao() const{
        return capacidade_de_acomodacao;
    }
    /**
     * @brief Atribui um novo valor à capacidade de acomodação.
     * @details Testa a nova capacidade contra o padrão e atribui um novo valor à capacidade em caso de sucesso ou lança uma exceção em caso de falha.
     * @param Capacidade String contendo o novo valor a ser testado.
     */
    void setCapacidade_De_Acomodacao(std::string capacidade_de_acomodacao);


    friend std::istream& operator>>(std::istream& in, Capacidade_De_Acomodacao& capacidadeDeAcomodacao);

private:
    bool validar(std::string capacidade);
    std::string capacidade_de_acomodacao;
};


#endif //TRABALHO_1_CLION_CAPACIDADE_DE_ACOMODACAO_H
