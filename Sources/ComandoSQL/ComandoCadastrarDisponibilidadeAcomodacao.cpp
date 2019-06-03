#include "../../Headers/ComandoSQL/ComandoCadastrarDisponibilidadeAcomodacao.h"

ComandoCadastrarDisponibilidadeAcomodacao::ComandoCadastrarDisponibilidadeAcomodacao(
        const Identificador &identificadorAcomodacao, const Data &dataInicio, const Data &dataTermino, const Identificador& identificadorUsuario) {
    listaResultado.clear();
    comandoSQL = "insert into Disponibilidade (DataInicio, DataTermino, Acomodacao, Usuario) values (";
    comandoSQL += "'" + dataInicio.getData() + "'";
    comandoSQL += ", '" + dataTermino.getData() + "'";
    comandoSQL += ", '" + identificadorAcomodacao.getIdentificador() + "'";
    comandoSQL += ", '" + identificadorUsuario.getIdentificador() + "');";
}

void ComandoCadastrarDisponibilidadeAcomodacao::cadastrarDisponibilidadeAcomodacao(
        const Identificador &identificadorAcomodacao, const Data &dataInicio, const Data &dataTermino,
        const Identificador &identificadorUsuario) {


    std::list<Data> listaDataInicio;
    std::list<Data> listaDataTermino;
    std::list<Data>::iterator itDataInicio, itDataTermino;
    bool podeCadastrar = true;

    comandoSQL = "SELECT DataInicio FROM Disponibilidade WHERE Acomodacao = '" + identificadorAcomodacao.getIdentificador() + "';";
    executar();
    for(const ElementoResultado &elemento: listaResultado){
        Data aux;
        aux.setData(elemento.getValorColuna());
        listaDataInicio.push_back(aux);
    }
    listaResultado.clear();

    comandoSQL = "SELECT DataTermino FROM Disponibilidade WHERE Acomodacao = '" + identificadorAcomodacao.getIdentificador() + "';";
    executar();
    for(const ElementoResultado &elemento: listaResultado){
        Data aux;
        aux.setData(elemento.getValorColuna());
        listaDataTermino.push_back(aux);
    }
    listaResultado.clear();

    for(itDataInicio = listaDataInicio.begin(), itDataTermino = listaDataTermino.begin(); itDataInicio != listaDataInicio.end() && itDataTermino != listaDataTermino.end(); itDataInicio++, itDataTermino++){
        if(((*itDataInicio >= dataInicio) && (*itDataTermino <= dataTermino)) || ((dataInicio <= *itDataInicio )  && (*itDataInicio <= dataTermino)) || ((dataInicio <= *itDataTermino )  && (*itDataTermino <= dataTermino)) ){
            podeCadastrar = false;
        } else{
            podeCadastrar = true;
            break;
        }
    }

    if(podeCadastrar){
        comandoSQL = "insert into Disponibilidade (DataInicio, DataTermino, Acomodacao, Usuario) values (";
        comandoSQL += "'" + dataInicio.getData() + "'";
        comandoSQL += ", '" + dataTermino.getData() + "'";
        comandoSQL += ", '" + identificadorAcomodacao.getIdentificador() + "'";
        comandoSQL += ", '" + identificadorUsuario.getIdentificador() + "');";
        try {
            executar();
        } catch (std::exception &e){
            //throw std::
        }
    } else{
        //throw std:: Nessa Data ja existe reserva
    }
}

void ComandoCadastrarDisponibilidadeAcomodacao::cadastrar() {
    executar();
    if(!listaResultado.empty())
        listaResultado.clear();

}
