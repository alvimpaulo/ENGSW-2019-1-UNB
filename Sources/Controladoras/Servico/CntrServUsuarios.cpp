//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Servico/CntrServUsuarios.h"
#include "../../../Headers/ComandoSQL/ComandoCadastrarUsuario.h"
#include "../../../Headers/ComandoSQL/ComandoDescadastrarUsuario.h"


void CntrServUsuarios::cadastrarUsuario(const Usuario& usuario, const Cartao_De_Credito& cartaoDeCredito) {
    ComandoCadastrarUsuario comandoSQL;
    comandoSQL.cadastrarUsuario(usuario, cartaoDeCredito);
}

void CntrServUsuarios::descadastrarUsuario(const Usuario& usuario) {
    ComandoDescadastrarUsuario comandoSQL;
    comandoSQL.descadastraUsuario(usuario);
}

