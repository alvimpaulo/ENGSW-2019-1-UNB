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
    Num_De_Sala capacidade;
    Data dataInicio;
    Data dataTermino;
    Cidade cidade;
    Estado estado;
    Preco diaria;

    identificador.setIdentificador("abcde");
    tipo.setTipoAcomodacao("Casa");
    capacidade.setNumSala("1");
    cidade.setCidade("Paulo Alvim.Alv");
    estado.setEstado("BA");
    diaria.setPreco("1224.50");
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
