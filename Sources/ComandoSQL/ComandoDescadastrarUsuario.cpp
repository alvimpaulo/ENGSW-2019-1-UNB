//
// Created by Oscar Madureira on 20/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoDescadastrarUsuario.h"

void ComandoDescadastrarUsuario::descadastraUsuario(const Usuario& usuario) {
    listaResultado.clear();

    try{

        comandoSQL = "SELECT *\n"
                     "  FROM Eventos\n"
                     " WHERE usuario = '" + usuario.getCpf().getCpf() + "';";
        this->executar();
        if(listaResultado.size() > 0){
            throw std::runtime_error("Usuario possui evento cadastrado");
        } else{
            listaResultado.clear();
            comandoSQL = "DELETE FROM Ingressos\n"
                         "      WHERE Usuario = '" + usuario.getCpf().getCpf() + "' AND \n"
                         "            NOT EXISTS (\n"
                         "                    SELECT Usuario\n"
                         "                      FROM Eventos\n"
                         "                     WHERE Usuario = '" + usuario.getCpf().getCpf() + "'\n"
                          "                );";
            this->executar();
            listaResultado.clear();

            comandoSQL = "DELETE FROM CartoesDeCredito\n"
                         "      WHERE Usuario = '" + usuario.getCpf().getCpf() + "' AND \n"
                         "            NOT EXISTS (\n"
                         "                    SELECT Usuario\n"
                         "                      FROM Eventos\n"
                         "                     WHERE Usuario = '" + usuario.getCpf().getCpf() + "'\n"
                        "                )";

            this->executar();

            listaResultado.clear();
            comandoSQL = "DELETE FROM Usuarios\n"
                         "      WHERE cpf = '" + usuario.getCpf().getCpf() + "' AND \n"
                         "            NOT EXISTS (\n"
                         "                    SELECT Usuario\n"
                         "                      FROM Eventos\n"
                         "                     WHERE Usuario = '" + usuario.getCpf().getCpf() + "'\n"
                        "                );";

            this->executar();
            listaResultado.clear();
        }



    } catch(std::exception &e){
        throw std::runtime_error("Não foi possível descadastrar usuario");
    }

}
