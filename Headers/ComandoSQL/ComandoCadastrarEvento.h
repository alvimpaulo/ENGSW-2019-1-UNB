//
// Created by paulo on 15/06/19.
//

#ifndef TRABALHO_1_CLION_COMANDOCADASTRAREVENTO_H
#define TRABALHO_1_CLION_COMANDOCADASTRAREVENTO_H

#include "ComandoSQL.h"
#include "../Entidades/Evento.h"
#include "../Entidades/Apresentacao.h"
#include "../Entidades/Usuario.h"

class ComandoCadastrarEvento : public ComandoSQL {
public:
    void cadastrarEvento(const Nome_De_Evento &nomeDeEvento,
                         const std::list<Apresentacao> &apresentacoes,
                         const Cidade &cidade,
                         const Estado &estado,
                         const Classe_De_Evento &classeDeEvento,
                         const Faixa_Etaria &faixaEtaria,
                         const Usuario &usuario);
};


#endif //TRABALHO_1_CLION_COMANDOCADASTRAREVENTO_H
