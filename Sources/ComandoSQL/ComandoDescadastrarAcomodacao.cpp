//
// Created by paulo on 18-Nov-18.
//

#include "../../Headers/ComandoSQL/ComandoDescadastrarAcomodacao.h"

ComandoDescadastrarAcomodacao::ComandoDescadastrarAcomodacao(const Identificador &identificadorAcomodacao, const Identificador& identificadorUsuario) {
    listaResultado.clear();
    comandoSQL = "select * from Reservas where Acomodacao = '" + identificadorAcomodacao.getIdentificador() + "'";
    try{
        executar();
    } catch (std::exception &exception){
        std::cout << exception.what() << std::endl;
    }
    if(listaResultado.empty()){
        comandoSQL = "delete from Acomodacoes where Identificador = '" + identificadorAcomodacao.getIdentificador() + "' and Usuario = '" + identificadorUsuario.getIdentificador() + "'";
        try {
            executar();
        } catch (std::exception &exception){
            std::cout << exception.what() << std::endl;
        }

    } else{
        listaResultado.clear();
        throw std::invalid_argument("Acomodacao ja possui reservas.");
    }

}
