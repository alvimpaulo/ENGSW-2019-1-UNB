//
// Created by paulo on 18-Nov-18.
//

#include <ios>
#include "iostream"
#include "../../Headers/ComandoSQL/ComandoSQL.h"

std::list<ElementoResultado> ComandoSQL::listaResultado;
//---------------------------------------------------------------------------
//Classe ElementoResultado.

void ElementoResultado::setNomeColuna(const std::string& nomeColuna) {
    this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const std::string& valorColuna){
    this->valorColuna = valorColuna;
}

void ComandoSQL::conectar(){
    rc = sqlite3_open(nomeBancoDados, &bd);
    if( rc != SQLITE_OK )
        throw std::runtime_error("Erro na conexao ao banco de dados");
}

void ComandoSQL::desconectar(){
    rc =  sqlite3_close(bd);
    if( rc != SQLITE_OK )
        throw std::runtime_error("Erro na desconexao ao banco de dados");
}

void ComandoSQL::executar(){
    conectar();
    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if(rc != SQLITE_OK){
        if (mensagem)
            std::cout << mensagem << std::endl;
            free(mensagem);
        throw std::runtime_error("Erro na execucao do comando SQL");
    }
    desconectar();
}

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
    NotUsed= nullptr;
    ElementoResultado elemento;
    int i;
    for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
    }
    return 0;
}