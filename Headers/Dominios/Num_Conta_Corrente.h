//
// Created by paulo on 04-Sep-18.
//
#ifndef TRABALHO_1_CLION_NUM_CONTA_CORRENTE_H
#define TRABALHO_1_CLION_NUM_CONTA_CORRENTE_H

#include <string>
#include <regex>
#include <stdexcept>

/**
 * @brief Domínio que armazena o número da conta corrente de um usuáio.
 * @details @brief Domínio que armazena o número da conta corrente de um usuáio dentro do padrão XXXXXX onde X é um dígito.
 */
class Num_Conta_Corrente{
public:

    /**
     * @brief Contrutor da classe.
     * @details Contrutor da classe que armazena o valor padrão de "000000" como número da conta.
     */
    Num_Conta_Corrente();

    /**
     * @brief Retorna o número da conta.
     * @return Número da conta em String.
     */
    std::string getNum_Conta_Corrente() const{
        return numConta;
    }

    /**
     * @brief Tenta atribuir um novo valor ao número da conta.
     * @details Testa o novo número da conta contra o padrão e o atribui esse novo valor em caso de sucesso. Lança exceção em caso de falha.
     * @param NumConta Novo número da conta para se atribuir.
     */
    void setNum_Conta_Corrente(std::string numConta);

    friend std::istream& operator>>(std::istream& in, Num_Conta_Corrente& numContaCorrente);

private:
    bool validar(std::string numConta);
    std::string numConta;
};


#endif //TRABALHO_1_CLION_NUM_CONTA_CORRENTE_H
