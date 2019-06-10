//
// Created by paulo on 16-Nov-18.
//

#ifndef TRABALHO_1_CLION_CNTRSSERVACOMODACAO_H
#define TRABALHO_1_CLION_CNTRSSERVACOMODACAO_H

#include "../../Interfaces/Servico/InterServAcomodacao.h"
#include "../../ComandoSQL/ComandoPesquisarAcomodacao.h"
#include "../../ComandoSQL/ComandoCadastrarAcomodacao.h"
#include "../../ComandoSQL/ComandoCadastrarDisponibilidadeAcomodacao.h"
#include "../../ComandoSQL/ComandoDescadastrarAcomodacao.h"
#include "../../ComandoSQL/ComandoEditarAcomodacao.h"
#include "../../ComandoSQL/ComandoDescadastrarDisponibilidade.h"
#include "../../ComandoSQL/ComandoChecarContaCorrente.h"

class CntrsServAcomodacao: public  InterServAcomodacao{
public:
    CntrsServAcomodacao() = default;


    //Retorna as acomodacoes que batem com a pesquisae_De
     std::list<Acomodacao> pesquisar(const Data& dataInicio, const Data& dataTermino, const Num_De_Sala& capacidadeDeAcomodacao, const Cidade& cidade, const Estado& estado);

    //Cadastra uma nova acomodacao para o usuario atual. Todos parametros sao obrigatorios
     void cadastrar(const Identificador& identificadorAcomodacao, const Tipo_Acomodacao& tipoAcomodacao, const Num_De_Sala& capacidadeDeAcomodacao, const Preco& diaria, const Cidade& cidade, const Estado& estado, const Identificador& identificadorUsuario);

    //Cadastra uma nova disponibilidade em uma acomodacao pelo seu identificador
    void cadastrarDisponibilidade(const Identificador &identificadorAcomodacao, const Data &dataInicio,
                                  const Data &dataTermino, const Identificador &identificadorUsuario);

    //recebe o identificador da acomodacao e descadastra ela, caso seja possivel.
     void descadastrar(const Identificador& identificadorAcomodacao, const Identificador& identificadorUsuario);

    //descadastra uma disponibilidade
    void descadastrarDisponibilidade(const Identificador &identificadorAcomodacao,
                                     const Identificador &identificadorUsuario, const Data &dataInicio,
                                     const Data &dataTermino);

};


#endif //TRABALHO_1_CLION_CNTRSSERVACOMODACAO_H
