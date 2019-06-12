//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRAPRUSUARIOS_H
#define TRABALHO_1_CLION_CNTRAPRUSUARIOS_H


#include "../../Interfaces/Servico/InterServUsuarios.h"
#include "../../Interfaces/Apresentacao/InterAprUsuarios.h"
#include "../Servico/CntrsServUsuarios.h"

class CntrAprUsuarios: public InterAprUsuarios{
private:
    InterServUsuarios *cntrServUsuario;
    static const int OPCAO_NAO = 0;
    static const int OPCAO_SIM = 1;
    static const int OPCAO_DESCADASTRAR_USUARIO = 1;
    static const int OPCAO_SAIR = 2;

protected:
public:
    void cadastrar() override;
    void executar(Usuario& usuario) override;
    void setCntrsServUsuarios(InterServUsuarios *cntrsServUsuarios) override;

    void descadastrar(Usuario& usuario);

    virtual ~CntrAprUsuarios();
};


#endif //TRABALHO_1_CLION_CNTRAPRUSUARIOS_H
