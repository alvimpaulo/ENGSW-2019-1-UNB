//
// Created by Oscar Madureira on 18/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoAutenticar.h"

std::string ComandoAutenticar::getSenha(const Usuario& usuario) {
    listaResultado.clear();
    std::string resposta;

    comandoSQL = "SELECT Senha FROM Usuarios WHERE Cpf = '" + usuario.getCpf().getCpf() + "'";

    this->executar();

    if(listaResultado.empty()){
        throw std::runtime_error("Cpf ou Senha incorretos");
    }

    resposta = listaResultado.front().getValorColuna();
    listaResultado.clear();
    return resposta;
}
