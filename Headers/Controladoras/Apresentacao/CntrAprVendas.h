//
// Created by paulo on 14/06/19.
//

#ifndef TRABALHO_1_CLION_CNTRAPRVENDAS_H
#define TRABALHO_1_CLION_CNTRAPRVENDAS_H

#include "../../Interfaces/Apresentacao/InterAprVendas.h"
#include "../../Entidades/Ingresso.h"

class CntrAprVendas: public InterAprVendas {
private:
    InterServVendas* cntrServVendas;
    static const int OPCAO_COMPRAR_INGRESSOS = 1;
    static const int OPCAO_SOLICITAR_INFORMACAO_VENDAS = 2;
    static const int OPCAO_SAIR_VENDAS = 3;
public:
     void executar(Usuario& usuario) override;
     void setCntrServVendas(InterServVendas *cntrServVendas) override;
     void comprarIngressos(const Usuario& usuario);
     void solicitarInformacaoVendas(const Usuario& usuario);
};

#endif //TRABALHO_1_CLION_CNTRAPRVENDAS_H
