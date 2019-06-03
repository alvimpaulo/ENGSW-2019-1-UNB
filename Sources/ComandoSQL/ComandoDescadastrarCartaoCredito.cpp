//
// Created by Oscar Madureira on 20/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoDescadastrarCartaoCredito.h"

void ComandoDescadastrarCartaoCredito::descadastrarCartao(const Num_Cartao_Credito &numCartaoCredito) {
    listaResultado.clear();
    comandoSQL = ""
                 "DELETE FROM Cartao_Credito WHERE Numero = '" + numCartaoCredito.getNum_Cartao() + "' AND NOT EXISTS (\n"
                 "  SELECT Usuario FROM Reservas WHERE Usuario = (\n"
                 "    SELECT Usuario FROM Conta_Corrente WHERE Numero = '" + numCartaoCredito.getNum_Cartao() + "'\n"
                 "  )\n"
                 ");";
    try{
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Não foi possível descadastrar o cartao de credito, pois existem reservas com esse cartao");
    }
}
