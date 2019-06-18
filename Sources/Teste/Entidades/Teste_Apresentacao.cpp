//
// Created by paulo on 17/06/19.
//

#include "../../../Headers/Teste/Entidades/Teste_Apresentacao.h"

int Teste_Apresentacao::rodar(){
    configurar();

    casoSucesso();

    desconfigurar();

    return estado;
}

void Teste_Apresentacao::casoSucesso(){
    Codigo_De_Apresentacao codigoDeApresentacao;
    Data data;
    Horario horario;
    Preco preco;
    Num_De_Sala numDeSala;
    Disponibilidade disponibilidade;


    try{
        apresentacao->setDisponibilidade(disponibilidade);
        apresentacao->setCodigoDeApresentacao(codigoDeApresentacao);
        apresentacao->setNumDeSala(numDeSala);
        apresentacao->setHorario(horario);
        apresentacao->setDisponibilidade(disponibilidade);
        apresentacao->setPreco(preco);
    } catch(std::exception &exception){
        std::cout<<exception.what() << std::endl;
        estado = FALHA;
    }


}