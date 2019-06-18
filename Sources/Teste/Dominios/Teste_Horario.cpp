//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Horario.h"

const std::string Teste_Horario::VALOR_VALIDO = "07:15";
const std::string Teste_Horario::VALOR_INVALIDO = "10:23";

void Teste_Horario::configurar(){
    horario = new Horario;
    estado = SUCESSO;

}

void Teste_Horario::casoSucesso(){
    try{
        horario->setHorario(VALOR_VALIDO);
        if(horario->getHorario() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Horario::casoFalha(){
    try{
        horario->setHorario(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}