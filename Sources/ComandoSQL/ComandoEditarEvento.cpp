//
// Created by paulo on 16/06/19.
//

#include "../../Headers/ComandoSQL/ComandoEditarEvento.h"

Evento ComandoEditarEvento::getEvento(const Codigo_De_Evento &codigoDeEvento, const Usuario &usuario) {
    listaResultado.clear();
    comandoSQL = "SELECT Nome,\n"
                 "       Cidade,\n"
                 "       Estado,\n"
                 "       Classe,\n"
                 "       Faixa\n"
                 "  FROM Eventos\n"
                 " WHERE codigo = \"" + codigoDeEvento.getCodigoEvento() + "\" and Usuario = \"" + usuario.getCpf().getCpf() + "\";";
    if(listaResultado.empty()){
        throw std::runtime_error("Lista vazia");
    } else{
        Evento eventoAtual;
        Nome_De_Evento nomeDeEventoAtual;
        Cidade cidadeAtual;
        Estado estadoAtual;
        Classe_De_Evento classeDeEventoAtual;
        Faixa_Etaria faixaEtariaAtual;


        while(!listaResultado.empty()){
            ElementoResultado colunaAtual;
            colunaAtual = listaResultado.front();
            if (!colunaAtual.getNomeColuna().compare("Nome")) // se for identificador
                nomeDeEventoAtual.setNome_De_Evento(colunaAtual.getValorColuna());
            if (!colunaAtual.getNomeColuna().compare("Cidade")) // se for tipo
                cidadeAtual.setCidade(colunaAtual.getValorColuna());
            if (!colunaAtual.getNomeColuna().compare("Estado")) // se for identificador
                estadoAtual.setEstado(colunaAtual.getValorColuna());
            if (!colunaAtual.getNomeColuna().compare("Classe")) // se for identificador
                classeDeEventoAtual.setClasseEvento(colunaAtual.getValorColuna());
            if (!colunaAtual.getNomeColuna().compare("Faixa")) // se for identificador
                faixaEtariaAtual.setFaixaEtaria(colunaAtual.getValorColuna());
            listaResultado.pop_front();
        }

        eventoAtual.setNomeDeEvento(nomeDeEventoAtual);
        eventoAtual.setCidade(cidadeAtual);
        eventoAtual.setEstado(estadoAtual);
        eventoAtual.setClasseDeEvento(classeDeEventoAtual);
        eventoAtual.setFaixaEtaria(faixaEtariaAtual);

        return eventoAtual;

    }
}

void ComandoEditarEvento::editarEvento(const Evento &evento, const Usuario &usuario) {
    listaResultado.clear();

    comandoSQL="UPDATE Eventos\n"
               "   SET Nome = '" + evento.getNomeDeEvento().getNome_De_Evento() + "',\n"
               "       Cidade = '" + evento.getCidade().getCidade() + "',\n"
               "       Estado = '" + evento.getEstado().getEstado() + "',\n"
               "       Classe = '" + evento.getClasseDeEvento().getClasseEvento() + "',\n"
               "       Faixa = '" + evento.getFaixaEtaria().getFaixaEtaria() + "'\n"
               " WHERE Codigo = \"" + evento.getCodigoDeEvento().getCodigoEvento() + "\" AND \n"
               "       Usuario = \"" + usuario.getCpf().getCpf() + "\";";
    this->executar();
}
