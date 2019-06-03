//
// Created by paulo on 15-Sep-18.
//

#include "../../../Headers/Teste/Dominios/Teste_Nome.h"

const std::string Teste_Nome::VALOR_VALIDO = "Paulo Alvim.Alv";
const std::string Teste_Nome::VALOR_INVALIDO = "Oscar Madureira .";

void Teste_Nome::configurar(){
    nome = new Nome;
    estado = SUCESSO;

}

void Teste_Nome::casoSucesso(){
    try{
        nome->setNome(VALOR_VALIDO);
        if(nome->getNome() != VALOR_VALIDO){
            estado = FALHA;
        }
    } catch(std::invalid_argument &e){
        std::cout << e.what() << std::endl;
        return;
    }

}

void Teste_Nome::casoFalha(){
    try{
        nome->setNome(VALOR_INVALIDO);
        estado = FALHA;
    } catch(std::invalid_argument &e){
        return;
    }
}