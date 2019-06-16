//
// Created by paulo on 16/06/19.
//

#include "../../Headers/ComandoSQL/ComandoDescadastrarEvento.h"

void ComandoDescadastrarEvento::descadastrarEvento(const Codigo_De_Evento &codigoDeEvento, const Usuario &usuario) {
    listaResultado.clear();
    comandoSQL="SELECT Codigo,\n"
               "       Usuario\n"
               "  FROM Eventos\n"
               " WHERE Codigo = \"" + codigoDeEvento.getCodigoEvento() + "\" AND \n"
               "       Usuario = \"" + usuario.getCpf().getCpf() + "\" AND \n"
               "       Codigo IN (\n"
               "           SELECT Evento\n"
               "             FROM Apresentacoes\n"
               "            WHERE Codigo IN (\n"
               "                      SELECT Apresentacao\n"
               "                        FROM Ingressos\n"
               "                  )\n"
               "       );";
    this->executar();

    if(listaResultado.size() > 0){
        throw std::runtime_error("Existe ingresso vendido para apresentacao cadastrada no evento requisitado");
    } else{
        listaResultado.clear();
        comandoSQL = "DELETE FROM Apresentacoes\n"
                     "      WHERE Evento IN (\n"
                     "    SELECT Codigo\n"
                     "      FROM Eventos\n"
                     "     WHERE Usuario = \"" + usuario.getCpf().getCpf() + "\" AND \n"
                     "           Codigo = \"" + codigoDeEvento.getCodigoEvento() + "\"\n"
                     ");";
        this->executar();

        listaResultado.clear();
        comandoSQL = "DELETE FROM Eventos\n"
                     "      WHERE Codigo = \"" + codigoDeEvento.getCodigoEvento() + "\" AND \n"
                     "            Usuario = \"" + usuario.getCpf().getCpf() + "\";";
        this->executar();
    }

}
