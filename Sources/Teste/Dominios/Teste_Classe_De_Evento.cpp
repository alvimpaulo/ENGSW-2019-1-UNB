//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Dominios/Teste_Classe_De_Evento.h"

const std::string Teste_Classe_De_Evento::VALOR_VALIDO = "1";
const std::string Teste_Classe_De_Evento::VALOR_INVALIDO = "5";

void Teste_Classe_De_Evento::configurar(){
   classeDeEvento = new Classe_De_Evento;
    estado = SUCESSO;
}

void Teste_Classe_De_Evento::casoSucesso(){
    try{
        classeDeEvento->setClasseEvento(VALOR_VALIDO);
        if(classeDeEvento->getClasseEvento() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Classe_De_Evento::casoFalha(){
    try{
        classeDeEvento->setClasseEvento(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }

}