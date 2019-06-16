//
// Created by paulo on 10/06/19.
//

#ifndef TRABALHO_1_CLION_EVENTO_H
#define TRABALHO_1_CLION_EVENTO_H

#include "../Dominios/Codigo_De_Evento.h"
#include "../Dominios/Nome_De_Evento.h"
#include "../Dominios/Cidade.h"
#include "../Dominios/Estado.h"
#include "../Dominios/Classe_De_Evento.h"
#include "../Dominios/Faixa_Etaria.h"

class Evento {
public:
    /**
    * @brief Construtor da classe.
    * @details Quando uma instância dessa classe for criada, será armazenado um valor padrão de suas variáveis.
    */
    Evento():codigoDeEvento(), nomeDeEvento(), cidade(), estado(), classeDeEvento(), faixaEtaria(){}

    /**
     * @brief Atribui o codigo de evento ao evento.
     * @param codigoDeEvento Novo codigo de evento.
     */
    void setCodigoDeEvento(Codigo_De_Evento codigoDeEvento){
        this->codigoDeEvento = codigoDeEvento;
    }

    /**
     * @brief Retorna o codigo de evento do evento.
     * @return Codigo_De_Evento contendo o codigo de evento .
     */
    Codigo_De_Evento getCodigoDeEvento() const {
        return codigoDeEvento;
    }

    /**
     * @brief Atribui o nome de evento ao evento.
     * @param nomeDeEvento Novo nome de evento.
     */
    void setNomeDeEvento(Nome_De_Evento nomeDeEvento){
        this->nomeDeEvento = nomeDeEvento;
    }

    /**
     * @brief Retorna o nome de evento do evento.
     * @return Nome_De_Evento contendo o nome de evento.
     */
    Nome_De_Evento getNomeDeEvento() const {
        return nomeDeEvento;
    }


    /**
     * @brief Atribui a cidade ao evento.
     * @param nomeDeEvento Nova cidade.
     */
    void setCidade(Cidade cidade){
        this->cidade = cidade;
    }

    /**
     * @brief Retorna a cidade do evento.
     * @return Cidade contendo a cidade de evento.
     */
    Cidade getCidade() const {
        return cidade;
    }

    /**
     * @brief Atribui o estado ao evento.
     * @param estado Novo estado.
     */
    void setEstado(Estado estado){
        this->estado = estado;
    }

    /**
     * @brief Retorna o estado do evento.
     * @return Estado contendo o estado .
     */
    Estado getEstado() const {
        return estado;
    }

    /**
     * @brief Atribui a classe de evento ao evento.
     * @param classeDeEvento Nova classe de evento.
     */
    void setClasseDeEvento(Classe_De_Evento classeDeEvento){
        this->classeDeEvento = classeDeEvento;
    }

    /**
     * @brief Retorna a classe de evento do evento.
     * @return Classe_De_Evento contendo a classe de evento .
     */
    Classe_De_Evento getClasseDeEvento() const {
        return classeDeEvento;
    }

    /**
     * @brief Atribui a faixa etaria ao evento.
     * @param faixaEtaria Nova faixa etaria.
     */
    void setFaixaEtaria(Faixa_Etaria faixaEtaria){
        this->faixaEtaria = faixaEtaria;
    }

    /**
     * @brief Retorna a faixa etaria do evento.
     * @return Faixa_Etaria contendo o faixa etaria .
     */
    Faixa_Etaria getFaixaEtaria() const {
        return faixaEtaria;
    }


protected:
private:
    Codigo_De_Evento codigoDeEvento;
    Nome_De_Evento nomeDeEvento;
    Cidade cidade;
    Estado estado;
    Classe_De_Evento classeDeEvento;
    Faixa_Etaria faixaEtaria;
};


#endif //TRABALHO_1_CLION_EVENTO_H
