//
// Created by oetch on 16/09/2018.
//
#ifndef TRABALHO_1_CLION_ACOMODACAO_H
#define TRABALHO_1_CLION_ACOMODACAO_H

#include "../../Headers/Dominios/Identificador.h"
#include "../../Headers/Dominios/Tipo_Acomodacao.h"
#include "../Dominios/Num_De_Sala.h"
#include "../../Headers/Dominios/Data.h"
#include "../Dominios/Cidade.h"
#include "../../Headers/Dominios/Estado.h"
#include "../Dominios/Preco.h"
#include <list>
#include "Intervalo_Datas.h"
#include <algorithm>

/**
 * @brief Entidade que armazena uma acomodação.
 * @brief Entidade que armazena uma acomodação.
 */
class Acomodacao{
public:
    /**
     * @brief Construtor da classe.
     * @details Quando uma instância dessa classe for criada, será armazenado um valor padrão de suas variáveis.
     */
    Acomodacao():identificador(),tipo(),capacidade(),cidade(),estado(),diaria(), disponibilidades(), reservas(){}

    /**
     * @brief Atribui o identificador da acomodação.
     * @details Atribui o identificador da acomodação.
     * @param identificador Identificador que será atribuído.
     */
    void setIdentificador(Identificador &identificador){
        this->identificador = identificador;
    }
    /**
     * @brief Retorna o número do identificador da acomodação.
     * @return Identificador contendo o número do identificador da acomodação.
     */
    Identificador getIdentificador() const{
        return identificador;
    }

    /**
     * @brief Atribui o tipo da acomodação.
     * @details Atribui o tipo da acomodação.
     * @param tipo Tipo_Acomodacao que será atribuído.
     */
    void setTipo(Tipo_Acomodacao &tipo){
        this->tipo = tipo;
    }
    /**
     * @brief Retorna o tipo da acomodação.
     * @return Tipo_Acomodacao contendo o tipo da acomodação.
     */
    Tipo_Acomodacao getTipo() const{
        return tipo;
    }

    /**
     * @brief Atribui a capacidade da acomodação.
     * @details Atribui a capacidade da acomodação.
     * @param capacidade Capacidade_De_Acomodacao que será atribuída.
     */
    void setCapacidade(Num_De_Sala &capacidade){
        this->capacidade = capacidade;
    }
    /**
     * @brief Retorna a capacidade da acomodação.
     * @return Capacidade_De_Acomodacao contendo a capacidade de acomodação.
     */
    Num_De_Sala getCapacidade() const{
        return capacidade;
    }



    /**
     * @brief Atribui o nome da cidade onde a acomodação é localizada.
     * @details Atribui o nome da cidade onde a acomodação é localizada.
     * @param cidade Nome que contém o nome da cidade a ser atribuído.
     */
    void setCidade(Cidade &cidade){
        this->cidade = cidade;
    }
    /**
     * @brief Retorna o nome da cidade onde a acomodação é localizada.
     * @return Nome contendo o nome da cidade onde a acomodação é localizada.
     */
    Cidade getCidade() const{
        return cidade;
    }

    /**
     * @brief Atribui o estado onde a acomodação é localizada.
     * @details Atribui o estado  onde a acomodação é localizada.
     * @param estado Estado que contém a sigla do estado a ser atribuída.
     */
    void setEstado(Estado &estado){
        this->estado = estado;
    }
    /**
     * @brief Retorna a sigla do estado onde a acomodação é localizada.
     * @return Estado contendo a sigla do estado onde a acomodação é localizada.
     */
    Estado getEstado() const{
        return estado;
    }

    /**
     * @brief Atribui o diária da acomodação.
     * @details Atribui o diária da acomodação.
     * @param diaria Diaria que contém o valor da diária a ser atribuída.
     */
    void setDiaria(Preco &diaria){
        this->diaria = diaria;
    }
    /**
     * @brief Retorna a diária da acomodação.
     * @return Diaria contendo a diária da acomodação.
     */
    Preco getDiaria() const{
        return diaria;
    }

    void addDisponibilidade(const Intervalo_Datas &disponibilidade) {
        this->disponibilidades.push_back(disponibilidade);
    }
    std::list<Intervalo_Datas> getDisponibilidades(){
        return disponibilidades;
    }
    void removeDisponibilidade(Intervalo_Datas disponibilidade);


    void addReserva(const Intervalo_Datas &reserva){
        this->reservas.push_back(reserva);
    }
    std::list<Intervalo_Datas> getReserva(){
        return reservas;
    }
    void removeReserva(Intervalo_Datas reserva);


protected:
private:
    Identificador identificador;
    Tipo_Acomodacao tipo;
    Num_De_Sala capacidade;
    Cidade cidade;
    Estado estado;
    Preco diaria;
    std::list<Intervalo_Datas> disponibilidades;
    std::list<Intervalo_Datas> reservas;

};


#endif //TRABALHO_1_CLION_ACOMODACAO_H
