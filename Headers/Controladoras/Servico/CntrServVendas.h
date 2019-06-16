//
// Created by paulo on 14/06/19.
//

#ifndef TRABALHO_1_CLION_CNTRSERVVENDAS_H
#define TRABALHO_1_CLION_CNTRSERVVENDAS_H

#include "../../Interfaces/Servico/InterServVendas.h"
#include "../../ComandoSQL/ComandoSolicitarInformacaoDeVendas.h"
#include "../../ComandoSQL/ComandoComprarIngresso.h"

class CntrServVendas: public InterServVendas {
public:
    std::list<std::string>
    comprarIngresso(const Usuario &usuario, const Codigo_De_Apresentacao &codigoDeApresentacao, int qtdIngresso) override ;

    std::list< std::pair<std::string, std::list<std::string> > > solicitarInformacaoDeVendas(const Codigo_De_Evento &codigoDeEvento, const Usuario &usuario) override;
};


#endif //TRABALHO_1_CLION_CNTRSERVVENDAS_H
