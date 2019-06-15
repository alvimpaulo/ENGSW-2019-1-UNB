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

    std::list<Cpf> solicitarInformacaoDeVendas(const Codigo_De_Evento &codigoDeEvento) override;
};


#endif //TRABALHO_1_CLION_CNTRSERVVENDAS_H
