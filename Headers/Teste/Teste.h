//
// Created by oetch on 16/09/2018.
//
#ifndef TRABALHO_1_CLION_TESTE_DOMINIO_H
#define TRABALHO_1_CLION_TESTE_DOMINIO_H


#include <string>

/**
 * @brief Classe base virtual para os testes
 * @details
 */
class Teste{
public:
    /**
     * @brief Valor que indica sucesso
     */
    static const int SUCESSO = 0;
    /**
     * @brief Valor que indica falha
     */
    static const int FALHA = 1;
    /**
     * @brief Roda uma sequência de testes para verificar veracidade de uma classe.
     * @return Retorna Teste::FALHA caso haja falha nos testes ou Teste::SUCESSO caso haja sucesso nos testes.
     */
    virtual int rodar() = 0;
    /**
     * @brief Exibe uma mensagem de sucesso.
     * @details Exibe uma mensagem de sucesso para o teste de uma classe.
     */
    virtual void mensagemSucesso() = 0;
    /**
     * @brief Exibe uma mensagem de falha.
     * @details Exibe uma mensagem de falha para o teste de uma classe.
     */
    virtual void mensagemFalha() = 0;

protected:
    /**
     * @brief Variável que indica o estado do teste.
     * @details Variável que indica o estado do teste, Teste::FALHA ou Teste::SUCESSO.
     */
    int estado;
private:
    virtual void configurar() = 0;
    virtual void desconfigurar() = 0;
};


#endif //TRABALHO_1_CLION_TESTE_DOMINIO_H
