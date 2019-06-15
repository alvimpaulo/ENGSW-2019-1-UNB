//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRINICIO_H
#define TRABALHO_1_CLION_CNTRINICIO_H

#include "../Interfaces/Apresentacao/InterAprAutenticacao.h"
#include "../Interfaces/Apresentacao/InterAprUsuarios.h"
#include "../Interfaces/Apresentacao/InterAprVendas.h"
#include "../Interfaces/Apresentacao/InterAprEvento.h"


class CntrInicio {
public:
    CntrInicio(InterAprEvento* cntrAprEvento, InterAprAutenticacao *cntrAprAutenticacao,
               InterAprVendas* cntrAprVendas, InterAprUsuarios *cntrAprUsuarios);

    void iniciar();

    void setCntrAprEvento(InterAprEvento *cntrAprEvento){
        this->cntrAprEvento = cntrAprEvento;
    }

    void setCntrAprAutenticacao(InterAprAutenticacao *cntrAprAutenticacao){
        this->cntrAprAutenticacao = cntrAprAutenticacao;
    }

    void setCntrAprVendas(InterAprVendas *cntrAprVendas){
        this->cntrAprVendas = cntrAprVendas;
    }

    void setCntrAprUsuarios(InterAprUsuarios *cntrAprUsuarios){
        this->cntrAprUsuarios = cntrAprUsuarios;
    }

    void setUsuario(Usuario usuario){
        this->usuario = usuario;
    }

    Usuario getUsuario(){
        return this->usuario;
    }

    ~CntrInicio();


private:
    InterAprEvento *cntrAprEvento;
    InterAprAutenticacao *cntrAprAutenticacao;
    InterAprVendas *cntrAprVendas;
    InterAprUsuarios *cntrAprUsuarios;
    Usuario usuario;


};


#endif //TRABALHO_1_CLION_CNTRINICIO_H
