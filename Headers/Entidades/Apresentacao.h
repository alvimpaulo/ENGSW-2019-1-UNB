//
// Created by paulo on 10/06/19.
//

#ifndef TRABALHO_1_CLION_APRESENTACAO_H
#define TRABALHO_1_CLION_APRESENTACAO_H

#include "../Dominios/Codigo_De_Apresentacao.h"
#include "../Dominios/Data.h"
#include "../Dominios/Horario.h"
#include "../Dominios/Preco.h"
#include "../Dominios/Num_De_Sala.h"
#include "../Dominios/Disponibilidade.h"


class Apresentacao {
public:
    /**
     * @brief Construtor da classe.
     * @details Quando uma instância dessa classe for criada, será armazenado um valor padrão de suas variáveis.
     */
    Apresentacao():codigoDeApresentacao(), data(), horario(), preco(), numDeSala(), disponibilidade(){}

    /**
     * @brief Atribui o codigo de apresentacao ao evento.
     * @param codigoDeApresentacao Novo codigo de apresentacao.
     */
    void setCodigoDeApresentacao(Codigo_De_Apresentacao codigoDeApresentacao){
        this->codigoDeApresentacao = codigoDeApresentacao;
    }

    /**
     * @brief Retorna o codigo de apresentacao do evento.
     * @return Codigo_De_Apresentacao contendo o codigo de apresentacao .
     */
    Codigo_De_Apresentacao getCodigoDeApresentacao(){
        return codigoDeApresentacao;
    }

    /**
     * @brief Atribui a data ao evento.
     * @param data Nova data.
     */
    void setData(Data data){
        this->data = data;
    }

    /**
     * @brief Retorna o data do evento.
     * @return Data contendo a data .
     */
    Data getData(){
        return data;
    }

    /**
     * @brief Atribui o horario ao evento.
     * @param horario Novo horario.
     */
    void setHorario(Horario horario){
        this->horario = horario;
    }

    /**
     * @brief Retorna o horario do evento.
     * @return Horario contendo o horario .
     */
    Horario getHorario(){
        return horario;
    }

    /**
     * @brief Atribui o preco ao evento.
     * @param preco Novo preco.
     */
    void setPreco(Preco preco){
        this->preco = preco;
    }

    /**
     * @brief Retorna o preco do evento.
     * @return Preco contendo o preco .
     */
    Preco getPreco(){
        return preco;
    }

    /**
     * @brief Atribui o numero de sala ao evento.
     * @param numDeSala Novo numero de sala.
     */
    void setNumDeSala(Num_De_Sala numDeSala){
        this->numDeSala = numDeSala;
    }

    /**
     * @brief Retorna o numero de sala do evento.
     * @return Num_De_Sala contendo o numero de sala .
     */
    Num_De_Sala getNumDeSala(){
        return numDeSala;
    }

    /**
     * @brief Atribui a disponibilidade ao evento.
     * @param disponibilidade Nova disponibilidade.
     */
    void setDisponibilidade(Disponibilidade disponibilidade){
        this->disponibilidade = disponibilidade;
    }

    /**
     * @brief Retorna o disponibilidade do evento.
     * @return Disponibilidade contendo a disponibilidade .
     */
    Disponibilidade getDisponibilidade(){
        return disponibilidade;
    }


protected:
private:
    Codigo_De_Apresentacao codigoDeApresentacao;
    Data data;
    Horario horario;
    Preco preco;
    Num_De_Sala numDeSala;
    Disponibilidade disponibilidade;
};


#endif //TRABALHO_1_CLION_APRESENTACAO_H
