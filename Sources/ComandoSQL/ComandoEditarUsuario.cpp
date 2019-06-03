//
// Created by Oscar Madureira on 20/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoEditarUsuario.h"

void ComandoEditarUsuario::editarUsuario(const Nome &nome, const Senha &senha, const Identificador &identificador) {
    listaResultado.clear();
    comandoSQL = ""
                 "UPDATE Usuarios\n"
                 "SET Nome = '" + nome.getNome() + "', Senha= '" + senha.getSenha() +"'\n"
                 "WHERE Identificador = '" + identificador.getIdentificador() + "';";

    try {
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Nao foi possivel editar o usuario");
    }
}
