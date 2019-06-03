#include <iostream>
#include <fstream>
#include <vector>
#include "sqlite/sqlite3.h"
#include "Headers/Teste/Dominios/Teste_Data.h"
#include "Headers/Teste/Dominios/Teste_Data_De_Validade.h"
#include "Headers/Teste/Dominios/Teste_Diaria.h"
#include "Headers/Teste/Dominios/Teste_Estado.h"
#include "Headers/Teste/Dominios/Teste_Tipo_Acomodacao.h"
#include "Headers/Teste/Dominios/Teste_Banco.h"
#include "Headers/Teste/Dominios/Teste_Agencia.h"
#include "Headers/Teste/Dominios/Teste_Capacidade_De_Acomodacao.h"
#include "Headers/Teste/Dominios/Teste_Nome.h"
#include "Headers/Teste/Dominios/Teste_Identificador.h"
#include "Headers/Teste/Dominios/Teste_Num_Cartao.h"
#include "Headers/Teste/Dominios/Teste_Num_Conta_Corrente.h"
#include "Headers/Teste/Dominios/Teste_Senha.h"
#include "Headers/Teste/Entidades/Teste_Acomodacao.h"
#include "Headers/Teste/Entidades/Teste_Conta_Corrente.h"
#include "Headers/Teste/Entidades/Teste_Usuario.h"
#include "Headers/Teste/Entidades/Teste_Cartao_De_Credito.h"
#include "Headers/Controladoras/Servico/CntrsServAcomodacao.h"
#include "Headers/Interfaces/Servico/InterServAutenticacao.h"
#include "Headers/Controladoras/Servico/CntrsServAutenticacao.h"
#include "Headers/Interfaces/Apresentacao/InterAprAutenticacao.h"
#include "Headers/Controladoras/Apresentacao/CntrAprAutenticacao.h"
#include "Headers/Interfaces/Apresentacao/InterAprUsuarios.h"
#include "Headers/Controladoras/Apresentacao/CntrAprUsuarios.h"

#include "Headers/Controladoras/Servico/CntrsServAcomodacao.h"
#include "Headers/Controladoras/Servico/CntrsServReserva.h"
#include "Headers/Controladoras/Servico/CntrsServUsuarios.h"
#include "Headers/Controladoras/Servico/CntrsServAutenticacao.h"
#include "Headers/Controladoras/CntrInicio.h"
#include "Headers/Controladoras/Apresentacao/CntrAprAcomodacao.h"
#include "Headers/Controladoras/Apresentacao/CntrAprReserva.h"

#define TESTES 0

int main(int argc, char **argv){
#if TESTES
    std::vector<Teste*> teste(17, nullptr);
    teste[0] = new Teste_Agencia;
    teste[1] = new Teste_Banco;
    teste[2] = new Teste_Capacidade_De_Acomodacao;
    teste[3] = new Teste_Data;
    teste[4] = new Teste_Data_De_Validade;
    teste[5] = new Teste_Diaria;
    teste[6] = new Teste_Estado;
    teste[7] = new Teste_Identificador;
    teste[8] = new Teste_Nome;
    teste[9] = new Teste_Num_Cartao;
    teste[10] = new Teste_Num_Conta_Corrente;
    teste[11] = new Teste_Senha;
    teste[12] = new Teste_Tipo_Acomodacao;
    teste[13] = new Teste_Acomodacao;
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
    cntrAprUsuarios->setCntrsServUsuarios(new CntrsServUsuarios);
    auto *cntrAprAcomodacao = new CntrAprAcomodacao;
    cntrAprAcomodacao->setCntrsServAcomodacao(new CntrsServAcomodacao);
    auto *cntrAprReserva = new CntrAprReserva;
    cntrAprReserva->setCntrsServReserva(new CntrsServReserva);
    auto *cntrAprAutenticacao = new CntrAprAutenticacao;
    cntrAprAutenticacao->setCntrsServAutenticacao(new CntrsServAutenticacao);

    CntrInicio cntrInicio(cntrAprReserva, cntrAprAutenticacao, cntrAprAcomodacao, cntrAprUsuarios);
    cntrInicio.iniciar();





    return 0;
}