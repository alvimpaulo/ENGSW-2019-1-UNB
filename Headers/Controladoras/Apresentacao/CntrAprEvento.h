//
// Created by paulo on 14/06/19.
//

#ifndef TRABALHO_1_CLION_CNTRAPREVENTO_H
#define TRABALHO_1_CLION_CNTRAPREVENTO_H

#include "../../Interfaces/Apresentacao/InterAprEvento.h"

class CntrAprEvento : public InterAprEvento {
private:
    InterServEvento* cntrServEvento;
    static const int OPCAO_CADASTRAR_EVENTO = 1;
    static const int OPCAO_DESCADASTRAR_EVENTO = 2;
    static const int OPCAO_EDITAR_EVENTO = 3;
    static const int OPCAO_PESQUISAR_EVENTO = 4;
    static const int OPCAO_SAIR_EVENTO = 5;
public:
    CntrAprEvento();
     void executar(Usuario& usuario) override;
    void setCntrServEvento(InterServEvento *cntrServEvento) override ;
    ~CntrAprEvento();

     void pesquisar() override ;
     void cadastrar(const Usuario& usuario) override ;
     void descadastrar(const Usuario& usuario) override ;
     void editar(const Usuario& usuario) override ;



};


#endif //TRABALHO_1_CLION_CNTRAPREVENTO_H
