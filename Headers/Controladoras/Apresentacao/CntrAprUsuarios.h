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
    static const int OPCAO_EDITAR_USUARIO = 1;
    static const int OPCAO_DESCADASTRAR_USUARIO = 2;
    static const int OPCAO_CADASTRAR_CARTAO = 3;
    static const int OPCAO_DESCADASTRAR_CARTAO = 4;
    static const int OPCAO_CADASTRAR_CONTA = 5;
    static const int OPCAO_DESCADASTRAR_CONTA = 6;
    static const int OPCAO_SAIR = 7;

protected:
public:
    void cadastrar() override;
    void executar(Identificador &identificador) override;
    void setCntrsServUsuarios(InterServUsuarios *cntrsServUsuarios) override;
    void editar(Identificador &identificador);
    void descadastrar(Identificador &identificador);
    void cadastrarContaCorrente(Identificador &identificador);
    void cadastrarCartaoCredito(Identificador &identificador);
    void descadastrarContaCorrente(Identificador &identificador);
    void descadastrarCartaoCredito(Identificador &identificador);
    virtual ~CntrAprUsuarios();
};


#endif //TRABALHO_1_CLION_CNTRAPRUSUARIOS_H
