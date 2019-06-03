//
// Created by paulo on 17-Nov-18.
//

#ifndef TRABALHO_1_CLION_INTERVALO_DATAS_H
#define TRABALHO_1_CLION_INTERVALO_DATAS_H

#include "../Dominios/Data.h"

class Intervalo_Datas {

public:
    /**
    * @brief Atribui a data de início de locação da acomodação.
    * @details Atribui a data de início de locação da acomodação.
    * @param dataInicio Data que contém a data de início a ser atribuída.
    */
    void setDataInicio(Data &dataInicio){
        this->dataInicio = dataInicio;
    }
    /**
     * @brief Retorna a data de início de locação da acomodação.
     * @return Data contendo a data de início de locação da acomodação.
     */
    Data getDataInicio() const{
        return dataInicio;
    }

    /**
     * @brief Atribui a data de término de locação da acomodação.
     * @details Atribui a data de término de locação da acomodação.
     * @param dataTermino Data que contém a data de término a ser atribuída.
     */
    void setDataTermino(Data &dataTermino){
        this->dataTermino = dataTermino;
    }
    /**
     * @brief Retorna a data de término de locação da acomodação.
     * @return Data contendo a data de término de locação da acomodação.
     */
    Data getDataTermino() const{
        return dataTermino;
    }

    friend bool operator==(const Intervalo_Datas& intervalo1, const Intervalo_Datas& intervalo2);

private:
    Data dataInicio;
    Data dataTermino;
};


#endif //TRABALHO_1_CLION_INTERVALO_DATAS_H
