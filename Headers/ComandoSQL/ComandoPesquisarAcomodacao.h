//
// Created by paulo on 18-Nov-18.
//

#ifndef TRABALHO_1_CLION_COMANDOPESQUISARACOMODACAO_H
#define TRABALHO_1_CLION_COMANDOPESQUISARACOMODACAO_H

#include "ComandoSQL.h"
#include "../Controladoras/Servico/CntrServAcomodacao.h"
class ComandoPesquisarAcomodacao : public ComandoSQL {
public:
    ComandoPesquisarAcomodacao(const Data& dataInicio, const Data& dataTermino, const Num_De_Sala& capacidadeDeAcomodacao, const Cidade& cidade, const Estado& estado);
    std::list<Acomodacao> getResultado(const Data &dataInicio, const Data &dataTermino);
};


#endif //TRABALHO_1_CLION_COMANDOPESQUISARACOMODACAO_H
