//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRAPRRESERVA_H
#define TRABALHO_1_CLION_CNTRAPRRESERVA_H


#include "../../Interfaces/Apresentacao/InterAprReserva.h"

class CntrAprReserva: public InterAprReserva {
private:
    static const int OPCAO_REALIZAR_RESERVA = 1;
    static const int OPCAO_CANCELAR_RESERVA = 2;
    static const int OPCAO_SAIR = 3;
    InterServReserva *cntrServReserva;
protected:
public:
    CntrAprReserva();
    void executar(Identificador &identificador) override;
    void setCntrsServReserva(InterServReserva *cntrsServReserva) override;
    void cancelarReserva(Identificador &identificadorUsuario);
    void realizarReserva(Identificador &identificadorUsuario);
    virtual ~CntrAprReserva();
};


#endif //TRABALHO_1_CLION_CNTRAPRRESERVA_H
