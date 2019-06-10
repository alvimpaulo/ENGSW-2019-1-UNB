//
// Created by paulo on 04-Sep-18.
//
#ifndef TRABALHO_1_CLION_CODIGO_DE_EVENTO_H
#define TRABALHO_1_CLION_CODIGO_DE_EVENTO_H

#include <string>
#include <regex>
#include <istream>

/**
 * @brief Domínio que armazena um código do evento.
 * @details Domínio que armazena um código do evento como uma string no formato XXX onde X é um dígito.
 */
class Codigo_De_Evento{
public:
    /**
     * @brief Construtor da classe.
     * @details Construdor da classe que cuida de atribuir um valor padrão ao código do evento na sua criação.
     */
    Codigo_De_Evento();

    /**
     * @brief Função que retorna o código do evento em forma de String.
     * @return Código do evento consistente com o padrão.
     */
    std::string getCodigoEvento() const{
        return codigoEvento;
    }
    /**
     * @brief Atribui um novo valor ao código do evento.
     * @details Atribui um novo valor caso esse valor seja consistente com o padrão, lança exceção em caso de falha.
     * @param codigoEvento Código do evento a ser atribuído em formato String.
     */
    void setCodigoEvento(std::string codigoEvento);

    friend std::istream& operator>>(std::istream& in, Codigo_De_Evento& codigo);

private:
    std::string codigoEvento;
};


#endif //TRABALHO_1_CLION_CODIGO_DE_EVENTO_H
