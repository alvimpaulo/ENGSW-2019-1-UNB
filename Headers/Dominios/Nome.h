//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_NOME_H
#define TRABALHO_1_CLION_NOME_H

#include <regex>
#include <stdexcept>
#include <string>
#include <iostream>

/**
 * @brief Domínio que armazena o nome do usuário.
 * @details Domínio que armazena o nome do usuário conforme o padrão XXXXXXXXXXXXXXX onde X pode ser uma letra, espaçe ou ponto.
 * Não podendo haver espaços seguidos e todos os pontos são precedidos por letras.
 */
class Nome{
public:

    /**
     * @brief Construtor da classe.
     * @details Atribui um valor padrão para o nome de uma nova classe.
     */
    Nome();

    /**
     * @brief Tenta atribuir um novo nome.
     * @details Testa o novo nome contra o padrão e atribui o novo nome à classe em caso de sucesso. Lança exceção em caso de falha.
     * @param Nome String contendo o novo nome a ser testado.
     */
    void setNome(std::string novoNome);

    /**
     * @brief Retorna o nome armazenado na classe.
     * @return String contendo o nome armazenado.
     */
    std::string getNome() const{
        return nome;
    }

    friend std::istream& operator>>(std::istream& in, Nome& nome);

protected:
private:
    std::string nome;

};


#endif //TRABALHO_1_CLION_NOME_H
