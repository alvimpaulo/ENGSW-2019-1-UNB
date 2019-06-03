//
// Created by oetch on 16/09/2018.
//

#include "../../Headers/Entidades/Acomodacao.h"

void Acomodacao::removeDisponibilidade(Intervalo_Datas disponibilidade) {
    std::list<Intervalo_Datas>::iterator iter = std::find(disponibilidades.begin(), disponibilidades.end(), disponibilidade);
    if(iter == disponibilidades.end()){
        return;
    } else{
        disponibilidades.erase(iter);
    }
}

void Acomodacao::removeReserva(Intervalo_Datas reserva) {
    std::list<Intervalo_Datas>::iterator iter = std::find(reservas.begin(), reservas.end(), reserva);
    if(iter == reservas.end()){
        return;
    } else{
        reservas.erase(iter);
    }
}
