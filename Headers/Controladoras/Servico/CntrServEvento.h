//
// Created by paulo on 15/06/19.
//

#ifndef TRABALHO_1_CLION_CNTRSERVEVENTO_H
#define TRABALHO_1_CLION_CNTRSERVEVENTO_H

#include "../../Interfaces/Servico/InterServEvento.h"
#include "../../ComandoSQL/ComandoCadastrarEvento.h"
#include "../../ComandoSQL/ComandoPesquisarEvento.h"
#include "../../ComandoSQL/ComandoDescadastrarEvento.h"
#include "../../ComandoSQL/ComandoEditarEvento.h"

class CntrServEvento : public InterServEvento{

    //Retorna os eventos que batem com a pesquisa.
    std::list<std::pair<Evento, Apresentacao>> pesquisar(
            const Data &dataInicio,
            const Data &dataTermino,
            const Cidade &cidade,
            const Estado &estado) override ;

    //Cadastra um novo evento para o usuario atual. Todos parametros sao obrigatorios.
    void cadastrarEvento(
            const Nome_De_Evento& nomeDeEvento,
            const std::list<Apresentacao>& apresentacoes,
            const Cidade& cidade,
            const Estado& estado,
            const Classe_De_Evento& classeDeEvento,
            const Faixa_Etaria& faixaEtaria,
            const Usuario& usuario ) override ;

    //descadastra um evento
    void descadastrarEvento(
            const Codigo_De_Evento& codigoDeEvento,
            const Usuario& usuario) override ;

    //edita um evento
    void editarEvento(const Evento &evento, const Usuario &usuario) override ;

};


#endif //TRABALHO_1_CLION_CNTRSERVEVENTO_H
