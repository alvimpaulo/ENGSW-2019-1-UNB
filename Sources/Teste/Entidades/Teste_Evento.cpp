//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Entidades/Teste_Evento.h"

int Teste_Evento::rodar(){
    configurar();

    casoSucesso();

    desconfigurar();

    return estado;
}

void Teste_Evento::casoSucesso(){
    Codigo_De_Evento codigoDeEvento;
    Nome_De_Evento nomeDeEvento;
    Cidade cidade;
    Estado estado1;
    Classe_De_Evento classeDeEvento;
    Faixa_Etaria faixaEtaria;

    try{
        evento->setFaixaEtaria(faixaEtaria);
        evento->setEstado(estado1);
        evento->setCidade(cidade);
        evento->setClasseDeEvento(classeDeEvento);
        evento->setCodigoDeEvento(codigoDeEvento);
        evento->setNomeDeEvento(nomeDeEvento);
    } catch(std::exception &exception){
        std::cout<<exception.what() << std::endl;
        estado = FALHA;
    }


}
