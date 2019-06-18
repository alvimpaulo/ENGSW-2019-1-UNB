//
// Created by paulo on 18-Nov-18.
//

#ifndef TRABALHO_1_CLION_COMANDOSQL_H
#define TRABALHO_1_CLION_COMANDOSQL_H


#include "../../sqlite/sqlite3.h"
#include <stdexcept>
#include <list>

class ElementoResultado {
private:
    std::string nomeColuna;
    std::string valorColuna;
public:
    void setNomeColuna(const std::string&);
    std::string getNomeColuna() const{
        return nomeColuna;
    }
    void setValorColuna(const std::string&);
    std::string getValorColuna() const{
        return valorColuna;
    }
};

class ComandoSQL {
private:
    const char *nomeBancoDados;
    sqlite3 *bd{};
    char *mensagem{};
    int rc{};
    void conectar();
    void desconectar() ;
    static int callback(void *, int, char **, char **);

protected:
    static std::list<ElementoResultado> listaResultado;
    std::string comandoSQL;
public:
    ComandoSQL(){
        //Informa o nome do banco de dados.
        nomeBancoDados = "./Database/Database.db";
    }
    void executar();
};


#endif //TRABALHO_1_CLION_COMANDOSQL_H
