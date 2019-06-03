//
// Created by Oscar Madureira on 20/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoDescadastrarUsuario.h"

void ComandoDescadastrarUsuario::descadastraUsuario(const Identificador &identificador) {
    listaResultado.clear();
    comandoSQL = ""
                 "DELETE FROM Usuarios WHERE Identificador = '" + identificador.getIdentificador() + "' AND NOT EXISTS (\n"
                 "\tSELECT Usuario FROM Reservas WHERE Acomodacao IN (\n"
                 "\t\tSELECT Acomodacao FROM Acomodacoes WHERE Usuario = '" + identificador.getIdentificador() + "'\n"
                 "\t)\n"
                 ");";
    try{
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Não foi possível descadastrar conta corrente");
    }

}
