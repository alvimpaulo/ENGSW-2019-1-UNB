//
// Created by paulo on 22-Nov-18.
//

#include "../../Headers/ComandoSQL/ComandoChecarContaCorrente.h"

ComandoChecarContaCorrente::ComandoChecarContaCorrente(const Identificador& identificadorUsuario) {
    comandoSQL = "select * from Conta_Corrente where Usuario = '" + identificadorUsuario.getIdentificador() + "'";
}

bool ComandoChecarContaCorrente::existeConta() {
    executar();
    if(listaResultado.empty()){
        return false;
    } else{
        listaResultado.clear();
        return true;
    }
}
