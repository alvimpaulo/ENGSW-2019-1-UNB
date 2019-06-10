//
// Created by paulo on 10/06/19.
//

#ifndef TRABALHO_1_CLION_CLASSE_DE_EVENTO_H
#define TRABALHO_1_CLION_CLASSE_DE_EVENTO_H


#include <string>
#include <regex>
#include <istream>

/**
 * @brief Domínio que armazena uma classe de evento.
 * @details Domínio que armazena uma classe de evento como uma string no formato X onde X é 1(TEATRO), 2(ESPORTE), 3(SHOW NACIONAL) ou 4(SHOW INTERNACIONAL).
 */
class Classe_De_Evento{
public:
    /**
     * @brief Construtor da classe.
     * @details Construdor da classe que cuida de atribuir um valor padrão a classe de evento na sua criação.
     */
    Classe_De_Evento();

    /**
     * @brief Função que retorna a classe de evento em forma de String.
     * @return Clase de evento consistente com o padrão.
     */
    std::string getClasseEvento() const{
        return classeEvento;
    }
    /**
     * @brief Atribui um novo valor a classe de evento.
     * @details Atribui um novo valor caso esse valor seja consistente com o padrão, lança exceção em caso de falha.
     * @param classeEvento Classe de evento a ser atribuído em formato String.
     */
    void setClasseEvento(std::string classeEvento);

    friend std::istream& operator>>(std::istream& in, Classe_De_Evento& classeEvento);

private:
    std::string classeEvento;
};

#endif //TRABALHO_1_CLION_CLASSE_DE_EVENTO_H
