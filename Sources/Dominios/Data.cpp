//
// Created by paulo on 04-Sep-18.
//

#include "../../Headers/Dominios/Data.h"

const std::vector<int> Data::LIMITE_SUPERIOR_DIA = {
        31, 28, 31,
        30, 31, 30,
        31, 31, 30,
        31, 30, 31
};

Data::Data(){
    dia = "01";
    mes = "01";
    ano = "2000";
    data = "01/01/2000";
}

void Data::setData(std::string data){
    if(validar(data)){
        setData(data.substr(0, 2), data.substr(3, 2), data.substr(6, 4));
    } else{
        throw (std::invalid_argument(data + "nao eh uma data valida"));
    }
}


void Data::setData(std::string dia, std::string mes, std::string ano){
    setAno(ano);
    setMes(mes);
    setDia(dia);
}

void Data::setDia(std::string dia){
    if(validarDia(dia)){
        this->dia = dia;
        data.replace(0, 2, dia);
    } else{
        throw (std::invalid_argument(dia + "nao eh um dia valido"));
    }
}

std::string Data::getDia() const{
    return dia;
}

void Data::setMes(std::string mes){
    if(validarMes(mes)){
        this->mes = mes;
        data.replace(3, 2, mes);
    } else{
        throw (std::invalid_argument(mes + "nao eh um mes valido"));
    }
}

std::string Data::getMes() const{
    return mes;
}

void Data::setAno(std::string ano){
    if(validarAno(ano)){
        this->ano = ano;
        data.replace(6, 4, ano);
    } else{
        throw (std::invalid_argument(ano + "nao eh um ano valido"));
    }
}

std::string Data::getAno() const{
    return ano;
}

bool Data::validar(std::string data){
    std::regex nomeRegex(R"((\d{2})(\/)(0\d|(1[012]))(\/)(\d{4}))");

    return std::regex_match(data, nomeRegex);
}

bool Data::validarDia(std::string dia){
    std::regex nomeRegex(R"((\d{2}))");
    int tmpDia = std::stoi(dia);

    return std::regex_match(dia, nomeRegex);
}

bool Data::validarMes(std::string mes){
    std::regex nomeRegex(R"((0\d|(1[012])))");

    return std::regex_match(mes, nomeRegex);
}

bool Data::validarAno(std::string ano){
    std::regex nomeRegex(R"((\d{4}))");

    if(std::regex_match(ano, nomeRegex)){
        int tmpAno = std::stoi(ano);
        return true;
    } else{
        return false;
    }
}

inline bool operator<(const Data& data1, const Data& data2){

    if(data1.ano == data2.ano){
        if(data1.mes == data2.mes){
            if(data1.dia >= data2.dia){
                return false;
            }
        } else if(data1.mes > data2.mes){
            return false;
        }
    } else if(data1.ano > data2.ano){
        return false;
    }
}

bool operator>(const Data& data1, const Data& data2){
    return data2 < data1;
}
bool operator==(const Data &data1, const Data &data2) {
    return data1.dia == data2.dia && data1.mes == data2.mes && data1.ano == data2.ano;
}
bool operator<=(const Data& data1, const Data& data2){
    return data1 < data2 || data1 == data2;
}
bool operator>=(const Data& data1, const Data& data2){
    return data2 < data1 || data1 == data2;
}

std::istream& operator>>(std::istream& in, Data& data){
    std::string str;

    in >> str;
    data.setData(str);

    return in;
}

