//
// Created by Oscar Madureira on 18/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoCadastrarUsuario.h"

void ComandoCadastrarUsuario::cadastrarUsuario(const Cidade &nome, const Identificador &identificador, const Senha &senha) {
    listaResultado.clear();
    comandoSQL = "INSERT INTO Usuarios (Cidade, Identificador, Senha)\nVALUES ('"
       + nome.getCidade()
       +"', '"
       +identificador.getIdentificador()
       +"', '"
       +senha.getSenha()
       +"');";
    try{
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Não foi possível cadastrar o usuario");
    }
}
