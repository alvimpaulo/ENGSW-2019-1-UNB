//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_Nome_De_Evento_H
#define TRABALHO_1_CLION_Nome_De_Evento_H

#include <regex>
#include <stdexcept>
#include <string>
#include <iostream>

/**
 * @brief Domínio que armazena o nome de um evento.
 * @details Domínio que armazena o nome de um evento conforme o padrão XXXXXXXXXXXXXXXXXXXX onde X pode ser uma letra, digito ou espaço.
 * Não podendo haver espaços seguidos.
 */
class Nome_De_Evento{
public:

    /**
     * @brief Construtor da classe.
     * @details Atribui um valor padrão para o nome de uma nova classe.
     */
    Nome_De_Evento();

    /**
     * @brief Tenta atribuir um novo nome.
     * @details Testa o novo nome contra o padrão e atribui o novo nome à classe em caso de sucesso. Lança exceção em caso de falha.
     * @param nomeDeEvento String contendo o novo nome a ser testado.
     */
    void setNome_De_Evento(std::string nomeDeEvento);

    /**
     * @brief Retorna o nome armazenado na classe.
     * @return String contendo o nome armazenado.
     */
    std::string getNome_De_Evento() const{
        return nomeDeEvento;
    }

    friend std::istream& operator>>(std::istream& in, Nome_De_Evento& nome);

protected:
private:
    std::string nomeDeEvento;

};


#endif //TRABALHO_1_CLION_Nome_De_Evento_H
