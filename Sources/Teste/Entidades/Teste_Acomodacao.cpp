//
// Created by oetch on 16/09/2018.
//

#include "../../../Headers/Teste/Entidades/Teste_Acomodacao.h"

void Teste_Acomodacao::configurar(){
    acomodacao = new Acomodacao;
    estado = SUCESSO;
}

void Teste_Acomodacao::casoSucesso(){
    Data data1;
    Data data2;
    Intervalo_Datas intervaloDatas;
    Identificador identificador;
    Tipo_Acomodacao tipo;
    Capacidade_De_Acomodacao capacidade;
    Data dataInicio;
    Data dataTermino;
    Nome cidade;
    Estado estado;
    Diaria diaria;

    identificador.setIdentificador("abcde");
    tipo.setTipoAcomodacao("Casa");
    capacidade.setCapacidade_De_Acomodacao("1");
    cidade.setNome("Paulo Alvim.Alv");
    estado.setEstado("BA");
    diaria.setDiaria("1224.50");
    data1.setData("10/jan/2010");
    data2.setData("11/jan/2011");
    intervaloDatas.setDataInicio(data1);
    intervaloDatas.setDataTermino(data2);

    try{
        acomodacao->setDiaria(diaria);
        acomodacao->setTipo(tipo);
        acomodacao->setCapacidade(capacidade);
        acomodacao->setCidade(cidade);
        acomodacao->setEstado(estado);
        acomodacao->setDiaria(diaria);
        acomodacao->addReserva(intervaloDatas);
    } catch(std::invalid_argument &e){
        this->estado = FALHA;
    }
}
