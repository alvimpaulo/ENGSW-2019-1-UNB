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
    void setCntrsServAutenticacao(InterServEvento *cntrServEvento) override ;
    ~CntrAprEvento();

     void pesquisar();
     void cadastrar(const Usuario& usuario);
     void descadastrar(const Usuario& usuario);
     void editar(const Usuario& usuario);



};


#endif //TRABALHO_1_CLION_CNTRAPREVENTO_H
