//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Nome_De_Evento.h"

const std::string Teste_Nome_De_Evento::VALOR_VALIDO = "vinteletrasehletradm";
const std::string Teste_Nome_De_Evento::VALOR_INVALIDO = "vinteumaletrasehletradm";

void Teste_Nome_De_Evento::configurar(){
    nomeDeEvento = new Nome_De_Evento;
    estado = SUCESSO;

}

void Teste_Nome_De_Evento::casoSucesso(){
    try{
        nomeDeEvento->setNome_De_Evento(VALOR_VALIDO);
        if(nomeDeEvento->getNome_De_Evento() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Nome_De_Evento::casoFalha(){
    try{
        nomeDeEvento->setNome_De_Evento(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}