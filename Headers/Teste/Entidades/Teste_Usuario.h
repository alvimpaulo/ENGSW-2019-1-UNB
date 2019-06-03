//
// Created by oetch on 16/09/2018.
//
//
#ifndef TRABALHO_1_CLION_TESTE_USUARIO_H
#define TRABALHO_1_CLION_TESTE_USUARIO_H

#include "../Teste.h"
#include "../../Entidades/Usuario.h"
#include "Teste_Entidades.h"

/**
 * @brief Classe que testa a classe Usuario.
 * @details
 */
class Teste_Usuario: public Teste_Entidades{
public:
    void mensagemSucesso() override{
        std::cout << "Sucesso Usuario" << std::endl;
    }
    void mensagemFalha() override{
        std::cout << "Falha Usuario" << std::endl;
    }
    int rodar() override;
private:

    Usuario *usuario;
    void configurar() override{
        usuario = new Usuario();
        estado = SUCESSO;
    }
    void desconfigurar() override{
        delete usuario;
    }
    void casoSucesso() override;
};


#endif //TRABALHO_1_CLION_TESTE_USUARIO_H
