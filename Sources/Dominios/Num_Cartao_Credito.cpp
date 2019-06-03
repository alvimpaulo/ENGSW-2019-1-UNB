//
// Created by paulo on 04-Sep-18.
//
//caracteres para serem dobrados: numCartao[14,12,10,8,6,4,2,0]
//entra     714334572634226
//sai       518364174664423 = 64
#include "../../Headers/Dominios/Num_Cartao_Credito.h"

bool Num_Cartao_Credito::validar(std::string numCartao){
    std::string numSemCheckDigit;

    std::regex numCartaoRegex(R"(\d{16})");

    if(std::regex_match(numCartao, numCartaoRegex)){
        numSemCheckDigit = numCartao.substr(0,15);
        int numAtual = 0;
        for(int i = 0; i <= 14; i+=2){
            numAtual = std::stoi(numSemCheckDigit.substr(i,1));
            numAtual *= 2;
            if(numAtual >= 10)
                numAtual -= 9;
            numSemCheckDigit.replace(i, 1, std::to_string(numAtual));
        }
        int soma = 0;
        for(int j = 0; j < numSemCheckDigit.length(); ++j){
            soma += std::stoi(numSemCheckDigit.substr(j,1));
        }
        soma *= 9;
        if(soma % 10 == std::stoi(numCartao.substr(15,1))){
            return true;
        } else{
            return false;
        }
    } else{
        return false;
    }


}

void Num_Cartao_Credito::setNum_Cartao(std::string numCartao){
    if(validar(numCartao)){
        this->numCartao = numCartao;
    } else{
        throw std::invalid_argument(numCartao + " nao eh um numero de cartao valido");
    }
}

Num_Cartao_Credito::Num_Cartao_Credito(){
    numCartao = "0000000000000000";
}

std::istream& operator>>(std::istream& in, Num_Cartao_Credito& numCartaoCredito){
    std::string str;

    in >> str;
        numCartaoCredito.setNum_Cartao(str);

    return in;
}
