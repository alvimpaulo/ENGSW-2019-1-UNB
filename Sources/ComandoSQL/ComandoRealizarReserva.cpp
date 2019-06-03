#include "../../Headers/ComandoSQL/ComandoRealizarReserva.h"

ComandoRealizarReserva::ComandoRealizarReserva(const Identificador &identificadorAcomodacao,
                                               const Intervalo_Datas &intervaloDatas,
                                               const Identificador& identificadorUsuario) {
    listaResultado.clear();
    comandoSQL = "insert into Reservas ('DataInicio', 'DataTermino', 'Acomodacao', 'Usuario') values (";
    comandoSQL += "'" + intervaloDatas.getDataInicio().getData() + "'";
    comandoSQL += ",'" + intervaloDatas.getDataTermino().getData() + "'";
    comandoSQL += ",'" + identificadorAcomodacao.getIdentificador() + "'";
    comandoSQL += ",'" + identificadorUsuario.getIdentificador() + "'";
    comandoSQL += ")";

}

void ComandoRealizarReserva::realizarReserva(const Identificador &identificadorAcomodacao,
                                             const Intervalo_Datas &intervaloDatas,
                                             const Identificador &identificadorUsuario) {

    std::list<Data> listaDataInicio;
    std::list<Data> listaDataTermino;
    std::list<Data>::iterator itDataInicio, itDataTermino;
    bool podeCadastrar = true;

    comandoSQL = "SELECT DataInicio FROM Reservas WHERE Acomodacao = '" + identificadorAcomodacao.getIdentificador() +"';";
    executar();
    for(const ElementoResultado &elemento: listaResultado){
        Data aux;
        aux.setData(elemento.getValorColuna());
        listaDataInicio.push_back(aux);
    }
    listaResultado.clear();

    comandoSQL = "SELECT DataTermino FROM Reservas WHERE Acomodacao = '" + identificadorAcomodacao.getIdentificador() +"';";
    executar();
    for(const ElementoResultado &elemento: listaResultado){
        Data aux;
        aux.setData(elemento.getValorColuna());
        listaDataTermino.push_back(aux);
    }
    listaResultado.clear();

    for(itDataInicio = listaDataInicio.begin(), itDataTermino = listaDataTermino.begin(); itDataInicio != listaDataInicio.end() && itDataTermino != listaDataTermino.end(); itDataInicio++, itDataTermino++){
        if(((*itDataInicio >= intervaloDatas.getDataInicio()) && (*itDataTermino <= intervaloDatas.getDataTermino())) || ((intervaloDatas.getDataInicio() <= *itDataInicio )  && (*itDataInicio <= intervaloDatas.getDataTermino())) || ((intervaloDatas.getDataInicio() <= *itDataTermino )  && (*itDataTermino <= intervaloDatas.getDataTermino())) ){
            podeCadastrar = false;
        } else{
            podeCadastrar = true;
            break;
        }
    }
    listaDataInicio.clear();
    listaDataTermino.clear();

    if(podeCadastrar){
        comandoSQL = "SELECT DataInicio FROM Disponibilidade WHERE Acomodacao= '" + identificadorAcomodacao.getIdentificador() + "';";
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
            if(((*itDataInicio >= intervaloDatas.getDataInicio()) && (intervaloDatas.getDataTermino() <= *itDataTermino))){
                podeCadastrar = true;
                break;
            } else{
                podeCadastrar = false;
            }
        }
        listaDataInicio.clear();
        listaDataTermino.clear();

        if(podeCadastrar){
            comandoSQL = "insert into Reservas ('DataInicio', 'DataTermino', 'Acomodacao', 'Usuario') values (";
            comandoSQL += "'" + intervaloDatas.getDataInicio().getData() + "'";
            comandoSQL += ",'" + intervaloDatas.getDataTermino().getData() + "'";
            comandoSQL += ",'" + identificadorAcomodacao.getIdentificador() + "'";
            comandoSQL += ",'" + identificadorUsuario.getIdentificador() + "'";
            comandoSQL += ")";
            try {
                executar();
            } catch (std::exception &e){
                //throw std::
            }
        } else{
            //throw std::Nessa data já existe reserva
        }
    }

}
