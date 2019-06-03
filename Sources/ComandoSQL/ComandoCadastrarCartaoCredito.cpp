//
// Created by Oscar Madureira on 20/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoCadastrarCartaoCredito.h"

void ComandoCadastrarCartaoCredito::cadastrarCartaoCredito(const Identificador &identificador,
                                                           const Num_Cartao_Credito &numCartaoCredito,
                                                           const Data_De_Validade &dataDeValidade) {
    bool aux;

    listaResultado.clear();
    comandoSQL = "SELECT Usuario FROM Conta_Corrente WHERE Usuario = '"+identificador.getIdentificador()+"'\n";
    try {
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Nao foi possivel cadastrar o cartao de credito");
    }
    aux = listaResultado.empty();
    listaResultado.clear();
    comandoSQL = "SELECT Usuario FROM Cartao_Credito WHERE Usuario = '"+identificador.getIdentificador()+"'\n";
    try {
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Nao foi possivel cadastrar o cartao de credito");
    }
    aux = aux && listaResultado.empty();
    listaResultado.clear();

    if(aux){
        comandoSQL = "INSERT INTO Cartao_Credito (Numero, DataValidade, Usuario) VALUES(\n"
                     "\t'" + numCartaoCredito.getNum_Cartao() + "', '" + dataDeValidade.getData_De_Validade() + "', '" + identificador.getIdentificador()+ "'\n\n"
                     ");\n";

        try {
            this->executar();
        } catch(std::exception &e){
            throw std::runtime_error("Nao foi possivel cadastrar o cartao de credito");
        }
    } else{
        throw std::runtime_error("Nao foi possivel cadastrar o cartao de credito");
    }
}
