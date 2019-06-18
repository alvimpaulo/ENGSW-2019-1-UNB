#include <iostream>
#include <fstream>
#include <vector>
#include "sqlite/sqlite3.h"

#include "Headers/Teste/Dominios/Teste_Codigo_De_Ingresso.h"
#include "Headers/Teste/Dominios/Teste_Codigo_De_Apresentacao.h"
#include "Headers/Teste/Dominios/Teste_Codigo_De_Evento.h"
#include "Headers/Teste/Dominios/Teste_Nome_De_Evento.h"
#include "Headers/Teste/Dominios/Teste_Data.h"
#include "Headers/Teste/Dominios/Teste_Horario.h"
#include "Headers/Teste/Dominios/Teste_Preco.h"
#include "Headers/Teste/Dominios/Teste_Num_De_Sala.h"
#include "Headers/Teste/Dominios/Teste_Cidade.h"
#include "Headers/Teste/Dominios/Teste_Estado.h"
#include "Headers/Teste/Dominios/Teste_Disponibilidade.h"
#include "Headers/Teste/Dominios/Teste_Classe_De_Evento.h"
#include "Headers/Teste/Dominios/Teste_Faixa_Etaria.h"
#include "Headers/Teste/Dominios/Teste_Cpf.h"
#include "Headers/Teste/Dominios/Teste_Senha.h"
#include "Headers/Teste/Dominios/Teste_Num_Cartao.h"
#include "Headers/Teste/Dominios/Teste_Codigo_De_Seguranca.h"
#include "Headers/Teste/Dominios/Teste_Data_De_Validade.h"

#include "Headers/Teste/Entidades/Teste_Evento.h"
#include "Headers/Teste/Entidades/Teste_Usuario.h"
#include "Headers/Teste/Entidades/Teste_Apresentacao.h"
#include "Headers/Teste/Entidades/Teste_Ingresso.h"
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

#define TESTES 1

int main(int argc, char **argv){
#if TESTES
    std::vector<Teste*> teste(23, nullptr);
    teste[0] = new Teste_Codigo_De_Evento;
    teste[1] = new Teste_Codigo_De_Apresentacao;
    teste[2] = new Teste_Codigo_De_Ingresso;
    teste[3] = new Teste_Nome_De_Evento;
    teste[4] = new Teste_Data;
    teste[5] = new Teste_Horario;
    teste[6] = new Teste_Preco;
    teste[7] = new Teste_Num_De_Sala;
    teste[8] = new Teste_Cidade;
    teste[9] = new Teste_Estado;
    teste[10] = new Teste_Disponibilidade;
    teste[11] = new Teste_Classe_De_Evento;
    teste[12] = new Teste_Faixa_Etaria;
    teste[13] = new Teste_Cpf;
    teste[14] = new Teste_Senha;
    teste[15] = new Teste_Num_Cartao;
    teste[16] = new Teste_Codigo_De_Seguranca;
    teste[17] = new Teste_Data_De_Validade;

    teste[18] = new Teste_Usuario;
    teste[19] = new Teste_Evento;
    teste[20] = new Teste_Apresentacao;
    teste[21] = new Teste_Ingresso;
    teste[22] = new Teste_Cartao_De_Credito;

    for(Teste *testePtr: teste){
        if(testePtr){
            if(testePtr->rodar() == Teste::SUCESSO){
                testePtr->mensagemSucesso();
            } else{
                testePtr->mensagemFalha();
            }
        }
    }

    for(Teste *testePtr: teste){
        delete testePtr;
    }
#endif

    auto *cntrAprUsuarios = new CntrAprUsuarios;
    cntrAprUsuarios->setCntrsServUsuarios(new CntrServUsuarios);
    auto *cntrAprEvento = new CntrAprEvento;
    cntrAprEvento->setCntrServEvento(new CntrServEvento);
    auto *cntrAprVendas = new CntrAprVendas;
    cntrAprVendas->setCntrServVendas(new CntrServVendas);
    auto *cntrAprAutenticacao = new CntrAprAutenticacao;
    cntrAprAutenticacao->setCntrServAutenticacao(new CntrServAutenticacao);

    CntrInicio cntrInicio(cntrAprEvento, cntrAprAutenticacao, cntrAprVendas, cntrAprUsuarios);
    cntrInicio.iniciar();





    return 0;
}