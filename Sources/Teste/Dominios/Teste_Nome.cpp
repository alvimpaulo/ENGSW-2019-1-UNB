//
// Created by paulo on 15-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Nome.h"

const std::string Teste_Nome::VALOR_VALIDO = "Paulo Alvim.Alv";
const std::string Teste_Nome::VALOR_INVALIDO = "Oscar Madureira .";

void Teste_Nome::configurar(){
    nome = new Cidade;
    estado = SUCESSO;

}

void Teste_Nome::casoSucesso(){
    try{
        nome->setCidade(VALOR_VALIDO);
        if(nome->getCidade() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Nome::casoFalha(){
    try{
        nome->setCidade(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}