//
// Created by paulo on 04-Sep-18.
//

#ifndef TRABALHO_1_CLION_AGENCIA_H
#define TRABALHO_1_CLION_AGENCIA_H


#include <string>
#include <stdexcept>
#include <regex>
/**
 * @brief Domínio que armazena uma agência.
 * @details Domínio que armazena o número de uma agência conforme o padrão "XXXXX" onde X é um dígito (0-9).
 */
class Agencia{
public:
    /**
     * @brief Construtor da classe.
     * @details Faz com que no mommento da criação da classe, uma string padrão seja armazenada ("00000").
     */
    Agencia();
    /**
     * @brief Retorna o número da agência como string.
     * @return String contendo o número da agência
     */
    std::string getAgenciaNum() const{
        return agenciaNum;
    }
    /**
     * @brief Atribui um valor ao número da agência.
     * @details Valida-se a string passada para ver se está conforme o padrão da classe. Lança exceção em caso de falha.
     * @param AgenciaNum String que é testada contra o padrão e será armazenada em caso de sucesso.
     */
    void setAgenciaNum(std::string agenciaNum);

    friend std::istream& operator>>(std::istream& in, Agencia& agencia);

protected:

private:
    std::string agenciaNum;
};


#endif //TRABALHO_1_CLION_AGENCIA_H
