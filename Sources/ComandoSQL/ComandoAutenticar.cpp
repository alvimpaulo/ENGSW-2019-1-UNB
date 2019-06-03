//
// Created by Oscar Madureira on 18/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoAutenticar.h"

std::string ComandoAutenticar::getSenha(Identificador identificador) {
    listaResultado.clear();
    std::string resposta;

    comandoSQL = "SELECT Senha FROM Usuarios WHERE Identificador = '" + identificador.getIdentificador() + "'";

    this->executar();

    if(listaResultado.empty()){
        throw std::runtime_error("Identificador ou Senha incorretos");
    }

    resposta = listaResultado.front().getValorColuna();
    listaResultado.clear();
    return resposta;
}
