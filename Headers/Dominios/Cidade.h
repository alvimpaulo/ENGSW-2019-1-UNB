//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_CIDADE_H
#define TRABALHO_1_CLION_CIDADE_H

#include <regex>
#include <stdexcept>
#include <string>
#include <iostream>

/**
 * @brief Domínio que armazena o nome de uma cidade.
 * @details Domínio que armazena o nome de uma cidade conforme o padrão XXXXXXXXXXXXXXX onde X pode ser uma letra, espaço ou ponto.
 * Não podendo haver espaços seguidos e todos os pontos são precedidos por letras.
 */
class Cidade{
public:

    /**
     * @brief Construtor da classe.
     * @details Atribui um valor padrão para o nome de uma nova classe.
     */
    Cidade();

    /**
     * @brief Tenta atribuir um novo nome.
     * @details Testa o novo nome contra o padrão e atribui o novo nome à classe em caso de sucesso. Lança exceção em caso de falha.
     * @param Nome String contendo o novo nome a ser testado.
     */
    void setCidade(std::string cidade);

    /**
     * @brief Retorna o nome armazenado na classe.
     * @return String contendo o nome armazenado.
     */
    std::string getCidade() const{
        return cidade;
    }

    friend std::istream& operator>>(std::istream& in, Cidade& nome);

protected:
private:
    std::string cidade;

};


#endif //TRABALHO_1_CLION_CIDADE_H
