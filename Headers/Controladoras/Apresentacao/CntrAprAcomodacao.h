//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRAPRACOMODACAO_H
#define TRABALHO_1_CLION_CNTRAPRACOMODACAO_H


#include "../../Dominios/Identificador.h"
#include "../../Interfaces/Apresentacao/InterAprAcomodacao.h"

class CntrAprAcomodacao: public InterAprAcomodacao{
private:
    InterServAcomodacao* cntrsServAcomodacao;
    static const int OPCAO_CADASTRAR_ACOMODACAO = 1;
    static const int OPCAO_DESCADASTRAR_ACOMODACAO = 2;
    static const int OPCAO_CADASTRAR_DISPONIBILIDADE = 3;
    static const int OPCAO_DESCADASTRAR_DISPONIBILIDADE = 4;
    static const int OPCAO_PESQUISAR_ACOMODACAO = 5;
    static const int OPCAO_SAIR_ACOMODACAO = 6;
protected:
public:
    CntrAprAcomodacao();
    void executar(Identificador &identificadorUsuario) override;
    void pesquisar(Identificador &identificador);
    void cadastrar(const Identificador &identificadorUsuario);
    void cadastrarDisponibilidade(const Identificador &identificadorUsuario);
    void descadastrar(const Identificador &identificadorUsuario);
    void descadastrarDisponibilidade(const Identificador &identificadorUsuario);
    void setCntrsServAcomodacao(InterServAcomodacao *cntrsServAcomodacao) override;
    virtual ~CntrAprAcomodacao();
};


#endif //TRABALHO_1_CLION_CNTRAPRACOMODACAO_H
