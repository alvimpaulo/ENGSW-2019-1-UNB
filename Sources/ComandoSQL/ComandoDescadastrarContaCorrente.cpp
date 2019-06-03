//
// Created by Oscar Madureira on 20/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoDescadastrarContaCorrente.h"

void ComandoDescadastrarContaCorrente::descadastrarConta(const Num_Conta_Corrente &numContaCorrente) {
    listaResultado.clear();
    comandoSQL = ""
                 "DELETE FROM Conta_Corrente WHERE Numero = '"+numContaCorrente.getNum_Conta_Corrente()+"' AND NOT EXISTS (\n"
                 "\tSELECT Acomodacao FROM Reservas WHERE Acomodacao IN (\n"
                 "\t\tSELECT Identificador FROM Acomodacoes WHERE Usuario = (\n"
                 "\t\t\tSELECT Usuario FROM Conta_Corrente WHERE Numero = '" + numContaCorrente.getNum_Conta_Corrente() +"'\n"
                 "\t\t)"
                 "\t)"
                 ");";
    try{
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Não foi possível descadastrar conta corrente, pois existem acomodacoes, associadas a essa conta, que estao reservadas");
    }

}
