#include <iostream>
#include <fstream>
#include <vector>
#include "sqlite/sqlite3.h"
#include "Headers/Teste/Dominios/Teste_Data.h"
#include "Headers/Teste/Dominios/Teste_Data_De_Validade.h"
#include "Headers/Teste/Dominios/Teste_Diaria.h"
#include "Headers/Teste/Dominios/Teste_Estado.h"
//#include "Headers/Teste/Dominios/Teste_Tipo_Evento.h"
#include "Headers/Teste/Dominios/Teste_Banco.h"
#include "Headers/Teste/Dominios/Teste_Agencia.h"
//#include "Headers/Teste/Dominios/Teste_Capacidade_De_Evento.h"
#include "Headers/Teste/Dominios/Teste_Nome.h"
#include "Headers/Teste/Dominios/Teste_Identificador.h"
#include "Headers/Teste/Dominios/Teste_Num_Cartao.h"
#include "Headers/Teste/Dominios/Teste_Num_Conta_Corrente.h"
#include "Headers/Teste/Dominios/Teste_Senha.h"
//#include "Headers/Teste/Entidades/Teste_Evento.h"
#include "Headers/Teste/Entidades/Teste_Conta_Corrente.h"
#include "Headers/Teste/Entidades/Teste_Usuario.h"
#include "Headers/Teste/Entidades/Teste_Cartao_De_Credito.h"
#include "Headers/Interfaces/Servico/InterServAutenticacao.h"
#include "Headers/Controladoras/Servico/CntrServAutenticacao.h"
#include "Headers/Interfaces/Apresentacao/InterAprAutenticacao.h"
#include "Headers/Controladoras/Apresentacao/CntrAprAutenticacao.h"
#include "Headers/Interfaces/Apresentacao/InterAprUsuarios.h"
#include "Headers/Controladoras/Apresentacao/CntrAprUsuarios.h"

#include "Headers/Controladoras/Servico/CntrServEvento.h"
#include "Headers/Controladoras/Servico/CntrServVendas.h"
#include "Headers/Controladoras/Servico/CntrServUsuarios.h"
#include "Headers/Controladoras/Servico/CntrServAutenticacao.h"
#include "Headers/Controladoras/CntrInicio.h"
#include "Headers/Controladoras/Apresentacao/CntrAprEvento.h"
#include "Headers/Controladoras/Apresentacao/CntrAprVendas.h"

#define TESTES 0

int main(int argc, char **argv){
#if TESTES
    std::vector<Teste*> teste(17, nullptr);
    teste[0] = new Teste_Agencia;
    teste[1] = new Teste_Banco;
    teste[2] = new Teste_Capacidade_De_Evento;
    teste[3] = new Teste_Data;
    teste[4] = new Teste_Data_De_Validade;
    teste[5] = new Teste_Diaria;
    teste[6] = new Teste_Estado;
    teste[7] = new Teste_Identificador;
    teste[8] = new Teste_Nome;
    teste[9] = new Teste_Num_Cartao;
    teste[10] = new Teste_Num_Conta_Corrente;
    teste[11] = new Teste_Senha;
    teste[12] = new Teste_Tipo_Evento;
    teste[13] = new Teste_Evento;
    teste[14] = new Teste_Conta_Corrente;
    teste[15] = new Teste_Usuario;
    teste[16] = new Teste_Cartao_De_Credito;

    for(Teste *testePtr: teste){
        if(testePtr->rodar() == Teste::SUCESSO){
            testePtr->mensagemSucesso();
        } else{
            testePtr->mensagemFalha();
        }
    }

    for(Teste *testePtr: teste){
        delete testePtr;
    }
#endif

    auto *cntrAprUsuarios = new CntrAprUsuarios;
    cntrAprUsuarios->setCntrsServUsuarios(new CntrServUsuarios);
    auto *cntrAprEvento = new CntrAprEvento;
    cntrAprEvento->setCntrsServEvento(new CntrServEvento);
    auto *cntrAprVendas = new CntrAprVendas;
    cntrAprVendas->setCntrsServVendas(new CntrServVendas);
    auto *cntrAprAutenticacao = new CntrAprAutenticacao;
    cntrAprAutenticacao->setCntrsServAutenticacao(new CntrServAutenticacao);

    CntrInicio cntrInicio(cntrAprEvento, cntrAprAutenticacao, cntrAprVendas, cntrAprUsuarios);
    cntrInicio.iniciar();





    return 0;
}