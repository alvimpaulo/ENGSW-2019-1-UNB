//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Servico/CntrsServUsuarios.h"
#include "../../../Headers/ComandoSQL/ComandoCadastrarUsuario.h"
#include "../../../Headers/ComandoSQL/ComandoDescadastrarUsuario.h"


void CntrsServUsuarios::cadastrarUsuario(const Cpf& cpf, const Senha& senha) {
    ComandoCadastrarUsuario comandoSQL;
    comandoSQL.cadastrarUsuario(cpf, senha);
}

void CntrsServUsuarios::descadastrarUsuario(const Usuario& usuario) {
    ComandoDescadastrarUsuario comandoSQL;
    comandoSQL.descadastraUsuario(usuario);
}

