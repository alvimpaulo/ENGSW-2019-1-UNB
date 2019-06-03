//
// Created by paulo on 17-Nov-18.
//

#ifndef TRABALHO_1_CLION_INTERSERVACOMODACAO_H
#define TRABALHO_1_CLION_INTERSERVACOMODACAO_H

#include "../../Entidades/Acomodacao.h"
#include <list>

class InterServAcomodacao {
public:
    //Retorna as acomodacoes que batem com a pesquisa
    virtual std::list<Acomodacao> pesquisar(const Data& dataInicio, const Data& dataTermino, const Capacidade_De_Acomodacao& capacidadeDeAcomodacao, const Nome& cidade, const Estado& estado) = 0;

    //Cadastra uma nova acomodacao para o usuario atual. Todos parametros sao obrigatorios
    virtual void cadastrar(const Identificador& identificadorAcomodacao, const Tipo_Acomodacao& tipoAcomodacao, const Capacidade_De_Acomodacao& capacidadeDeAcomodacao, const Diaria& diaria, const Nome& cidade, const Estado& estad, const Identificador& identificadorUsuario) = 0;

    //Cadastra uma nova disponibilidade em uma acomodacao pelo seu identificador
    virtual void cadastrarDisponibilidade(const Identificador &identificadorAcomodacao, const Data &dataInicio,
                                          const Data &dataTermino, const Identificador &identificadorUsuario) = 0;

    //Descadastra uma nova disponibilidade em uma acomodacao pelo seu identificador
    virtual void descadastrarDisponibilidade(const Identificador &identificadorAcomodacao,
                                             const Identificador &identificadorUsuario, const Data &dataInicio,
                                             const Data &dataTermino) = 0;

    //recebe o identificador da acomodacao e descadastra ela, caso seja possivel.
    virtual void descadastrar(const Identificador& identificadorAcomodacao, const Identificador& identificadorUsuario) = 0;

};


#endif //TRABALHO_1_CLION_INTERSERVACOMODACAO_H
