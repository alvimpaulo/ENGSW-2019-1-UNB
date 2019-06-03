//
// Created by paulo on 04-Sep-18.
//
#ifndef TRABALHO_1_CLION_NUM_CARTAO_CREDITO_H
#define TRABALHO_1_CLION_NUM_CARTAO_CREDITO_H

#include <string>
#include <regex>
#include <stdexcept>

/**
 * @brief Domínio que armazena o número do cartão de crédito do usuário.
 * @details Domínio que armazena o número do cartão de crédito do usuário com base no padrão XXXXXXXXXXXXXXXX onde X é um digito e esse número é válido com base no algoritmo de Luhn.
 */
class Num_Cartao_Credito{
public:

    /**
     * @brief Construtor do domínio.
     * @details Construtor que atribui o valor padrão de "0000000000000000" ao número do cartão de crédito.
     */
    Num_Cartao_Credito();

    /**
     * @brief Retorna o número do cartão.
     * @return Número do cartão em Srting.
     */
    std::string getNum_Cartao() const{
        return numCartao;
    }

    /**
     * @brief Tenta atribuir um novo valor ao número de cartão da classe.
     * @details Testa o novo numero do cartão contra o padrão e atribui esse novo número em caso de sucesso. Lança exceção em caso de falha.
     * @param NumCartao
     */
    void setNum_Cartao(std::string numCartao);

    friend std::istream& operator>>(std::istream& in, Num_Cartao_Credito& numCartaoCredito);

private:
    bool validar(std::string numCartao);
    std::string numCartao;
};


#endif //TRABALHO_1_CLION_NUM_CARTAO_CREDITO_H
