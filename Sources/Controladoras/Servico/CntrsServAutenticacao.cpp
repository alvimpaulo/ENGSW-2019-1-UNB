//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Servico/CntrsServAutenticacao.h"
#include "../../../Headers/ComandoSQL/ComandoAutenticar.h"

void CntrsServAutenticacao::autenticar(const Identificador& identificador, const Senha& senha){
    ComandoAutenticar SQLAutenticar;
    if(senha.getSenha() != SQLAutenticar.getSenha(identificador)){
        throw std::runtime_error("Identificador ou Senha incorretos");
    }
}