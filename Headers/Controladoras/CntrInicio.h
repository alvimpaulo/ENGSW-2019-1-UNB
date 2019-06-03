//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRINICIO_H
#define TRABALHO_1_CLION_CNTRINICIO_H

#include "../Interfaces/Apresentacao/InterAprAutenticacao.h"
#include "../Interfaces/Apresentacao/InterAprReserva.h"
#include "../Interfaces/Apresentacao/InterAprAcomodacao.h"
#include "../Interfaces/Apresentacao/InterAprUsuarios.h"

class CntrInicio {
public:
    CntrInicio(InterAprReserva *cntrAprReserva, InterAprAutenticacao *cntrAprAutenticacao,
                   InterAprAcomodacao *cntrAprAcomodacao, InterAprUsuarios *cntrAprUsuarios);

    void iniciar();

    void setCntrAprReserva(InterAprReserva *cntrAprReserva){
        this->cntrAprReserva = cntrAprReserva;
    }

    void setCntrAprAutenticacao(InterAprAutenticacao *cntrAprAutenticacao){
        this->cntrAprAutenticacao = cntrAprAutenticacao;
    }

    void setCntrAprAcomodacao(InterAprAcomodacao *cntrAprAcomodacao){
        this->cntrAprAcomodacao = cntrAprAcomodacao;
    }

    void setCntrAprUsuarios(InterAprUsuarios *cntrAprUsuarios){
        this->cntrAprUsuarios = cntrAprUsuarios;
    }

    void setUsuario(Usuario *usuario){
        this->usuario = usuario;
    }

    Usuario* getUsuario(){
        return this->usuario;
    }

    ~CntrInicio();


private:
    InterAprReserva *cntrAprReserva;
    InterAprAutenticacao *cntrAprAutenticacao;
    InterAprAcomodacao *cntrAprAcomodacao;
    InterAprUsuarios *cntrAprUsuarios;
    Usuario *usuario;


};


#endif //TRABALHO_1_CLION_CNTRINICIO_H
