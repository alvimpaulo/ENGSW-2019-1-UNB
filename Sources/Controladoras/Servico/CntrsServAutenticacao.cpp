//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Servico/CntrsServAutenticacao.h"
#include "../../../Headers/ComandoSQL/ComandoAutenticar.h"


void CntrsServAutenticacao::autenticar(const Usuario& usuario) {
    ComandoAutenticar SQLAutenticar;
    if(usuario.getSenha().getSenha() != SQLAutenticar.getSenha(usuario)){
        throw std::runtime_error("Cpf ou Senha incorretos");
    }
}
