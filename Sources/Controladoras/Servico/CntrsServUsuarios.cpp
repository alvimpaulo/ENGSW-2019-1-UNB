//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Servico/CntrsServUsuarios.h"
#include "../../../Headers/ComandoSQL/ComandoCadastrarUsuario.h"
#include "../../../Headers/ComandoSQL/ComandoPesquisarAcomodacao.h"
#include "../../../Headers/ComandoSQL/ComandoDescadastrarUsuario.h"
#include "../../../Headers/ComandoSQL/ComandoDescadastrarContaCorrente.h"
#include "../../../Headers/ComandoSQL/ComandoDescadastrarCartaoCredito.h"
#include "../../../Headers/ComandoSQL/ComandoCadastrarContaCorrente.h"
#include "../../../Headers/ComandoSQL/ComandoCadastrarCartaoCredito.h"
#include "../../../Headers/ComandoSQL/ComandoEditarUsuario.h"


void CntrsServUsuarios::cadastrarUsuario(const Nome &nome, const Identificador &identificador, const Senha &senha) {
    ComandoCadastrarUsuario comandoSQL;
    comandoSQL.cadastrarUsuario(nome, identificador, senha);
}

void CntrsServUsuarios::cadastrarContaCorrente( const Identificador &identificador, const Num_Conta_Corrente &numContaCorrente,
        const Agencia &agencia, const Banco &banco) {
    ComandoCadastrarContaCorrente comandoSQL;
    comandoSQL.cadastrarContaCorrente(identificador, numContaCorrente, agencia, banco);
}

void CntrsServUsuarios::cadastrarCartaoCredito( const Identificador &identificador, const Num_Cartao_Credito &numCartaoCredito,
                                               const Data_De_Validade &dataDeValidade) {
    ComandoCadastrarCartaoCredito comandoSQL;
    comandoSQL.cadastrarCartaoCredito(identificador, numCartaoCredito, dataDeValidade);
}

void CntrsServUsuarios::descadastrarUsuario(const Identificador &identificador) {
    ComandoDescadastrarUsuario comandoSQL;
    comandoSQL.descadastraUsuario(identificador);
}

void CntrsServUsuarios::descadastrarContaCorrente(const Num_Conta_Corrente &numContaCorrente) {
    ComandoDescadastrarContaCorrente comandoSQL;
    comandoSQL.descadastrarConta(numContaCorrente);
}

void CntrsServUsuarios::descadastrarCartaoCredito(const Num_Cartao_Credito &numCartaoCredito) {
    ComandoDescadastrarCartaoCredito comandoSQL;
    comandoSQL.descadastrarCartao(numCartaoCredito);
}

void CntrsServUsuarios::editarUsuario(const Nome &nome, const Senha &senha, const Identificador &identificador) {
    ComandoEditarUsuario comandoEditarUsuario;
    comandoEditarUsuario.editarUsuario(nome, senha, identificador);
}
