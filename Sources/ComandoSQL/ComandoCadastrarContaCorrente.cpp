//
// Created by Oscar Madureira on 20/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoCadastrarContaCorrente.h"

void ComandoCadastrarContaCorrente::cadastrarContaCorrente(const Identificador &identificador,
                                                           const Num_Conta_Corrente &numContaCorrente,
                                                           const Agencia &agencia, const Banco &banco) {
    listaResultado.clear();
    bool aux;

    comandoSQL = "SELECT Usuario FROM Conta_Corrente WHERE Usuario = '"+identificador.getIdentificador()+"'\n";
    try {
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Nao foi possivel cadastrar a conta corrente");
    }
    aux = listaResultado.empty();
    listaResultado.clear();
    comandoSQL = "SELECT Usuario FROM Cartao_Credito WHERE Usuario = '"+identificador.getIdentificador()+"'\n";
    try {
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Nao foi possivel cadastrar a conta corrente");
    }
    aux = aux && listaResultado.empty();
    listaResultado.clear();

    if(aux){
        comandoSQL = "insert into Conta_Corrente (Numero, Agencia, Banco, Usuario) values(\n"
                     "\t'" + numContaCorrente.getNum_Conta_Corrente() + "', '" + agencia.getAgenciaNum() + "', '" + banco.getBancoNum() + "', '" + identificador.getIdentificador()+ "'\n"
                     "\t);\n";

        try {
            this->executar();
        } catch(std::exception &e){
            throw std::runtime_error("Nao foi possivel cadastrar a conta corrente");
        }
    } else{
        throw std::runtime_error("Nao foi possivel cadastrar a conta corrente");
    }
}
