//
// Created by paulo on 10/06/19.
//

#ifndef TRABALHO_1_CLION_INTERSERVEVENTO_H
#define TRABALHO_1_CLION_INTERSERVEVENTO_H


#include "../../Entidades/Evento.h"
#include "../../Entidades/Apresentacao.h"
#include "../../Entidades/Usuario.h"
#include <list>

class InterServEvento {
public:
    //Retorna os eventos que batem com a pesquisa.
    virtual std::list<Evento> pesquisar(
            const Data& dataInicio,
            const Data& dataTermino,
            const Cidade& cidade,
            const Estado& estado) = 0;

    //Cadastra um novo evento para o usuario atual. Todos parametros sao obrigatorios.
    virtual void cadastrarEvento(
            const Codigo_De_Evento& codigoDeEvento,
            const Nome_De_Evento& nomeDeEvento,
            const std::list<Apresentacao>& apresentacoes,
            const Cidade& cidade,
            const Estado& estado,
            const Classe_De_Evento& classeDeEvento,
            const Faixa_Etaria& faixaEtaria,
            const Usuario& usuario ) = 0;

    //descadastra um evento
    virtual void descadastrarEvento(
            const Codigo_De_Evento& codigoDeEvento,
            const Usuario& usuario) = 0;

    //edita um evento
    virtual void editarEvento(
            const Codigo_De_Evento& codigoDeEvento,
            const Evento& evento,
            const Usuario& usuario) = 0;
};
#endif //TRABALHO_1_CLION_INTERSERVEVENTO_H
