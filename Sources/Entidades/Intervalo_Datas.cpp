//
// Created by paulo on 17-Nov-18.
//

#include "../../Headers/Entidades/Intervalo_Datas.h"

bool operator==(const Intervalo_Datas &intervalo1, const Intervalo_Datas &intervalo2) {
    return intervalo1.dataInicio == intervalo2.dataTermino && intervalo1.dataTermino == intervalo2.dataTermino;
}
