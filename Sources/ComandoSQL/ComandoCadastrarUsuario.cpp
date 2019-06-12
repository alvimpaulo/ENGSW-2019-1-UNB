//
// Created by Oscar Madureira on 18/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoCadastrarUsuario.h"

void ComandoCadastrarUsuario::cadastrarUsuario(const Cpf& cpf, const Senha &senha) {
    listaResultado.clear();
    comandoSQL = "INSERT INTO Usuarios (Cpf, Senha)\nVALUES ('"
       + cpf.getCpf()
       +"', '"
       +senha.getSenha()
       +"');";
    try{
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Não foi possível cadastrar o usuario");
    }
}
