//
// Created by paulo on 16-Nov-18.
//

#include "../../../Headers/Controladoras/Apresentacao/CntrAprReserva.h"

CntrAprReserva::CntrAprReserva() {

}

void CntrAprReserva::executar(Identificador &identificador) {
    int escolha;
    bool flag;
    std::string input;
    std::cout << "Sistema de Acomodacao - Servicos de reserva" << std::endl << std::endl;

    std::cout << "1 - Realizar reserva." << std::endl;
    std::cout << "2 - Cancelar reserva." << std::endl;
    std::cout << "3 - Sair." << std::endl;

    std::cout << "Escolha a opcao: ";

    std::getline(std::cin, input);
    escolha = std::stoi(input);

    flag = true;

    while (flag){
        switch (escolha) {
            case OPCAO_REALIZAR_RESERVA:
                realizarReserva(identificador);
                flag = false;
                break;
            case OPCAO_CANCELAR_RESERVA:
                cancelarReserva(identificador);
                flag = false;
                break;
            case OPCAO_SAIR:
            default:
                return;
        }
    }

}

void CntrAprReserva::setCntrsServReserva(InterServReserva *cntrsServReserva) {
    this->cntrServReserva = cntrsServReserva;
}

void CntrAprReserva::cancelarReserva(Identificador &identificadorUsuario) {
    Identificador idReserva;
    Intervalo_Datas intervaloDatas;
    Data dataInicio;
    Data dataTermino;
    std::string input;
    bool flagCampoInseridoCorretamente = false;

    std::cout << "Insira o identificador da reserva: ";
    std::getline(std::cin, input);
    while (!flagCampoInseridoCorretamente) {
        try {
            idReserva.setIdentificador(input);
            flagCampoInseridoCorretamente = true;
        } catch (std::invalid_argument &invalid_argument) {
            flagCampoInseridoCorretamente = false;
        }
    }
    std::cout << "Insira a data de inicio da reserva: ";
    std::getline(std::cin, input);
    flagCampoInseridoCorretamente = false;
    while (!flagCampoInseridoCorretamente) {
        try {
            dataInicio.setData(input);
            flagCampoInseridoCorretamente = true;
        } catch (std::invalid_argument &invalid_argument) {
            flagCampoInseridoCorretamente = false;
        }
    }
    std::cout << "Insira a data de termino da reserva: ";
    std::getline(std::cin, input);
    flagCampoInseridoCorretamente = false;
    while (!flagCampoInseridoCorretamente) {
        try {
            dataTermino.setData(input);
            flagCampoInseridoCorretamente = true;
        } catch (std::invalid_argument &invalid_argument) {
            flagCampoInseridoCorretamente = false;
        }
    }

    intervaloDatas.setDataInicio(dataInicio);
    intervaloDatas.setDataTermino(dataTermino);

    try {
        cntrServReserva->cancelarReserva(idReserva, intervaloDatas, identificadorUsuario);
    } catch (std::exception &exception){
        std::cout << "Não foi possível cancelar a reserva." << std::endl;
        return;
    }

    std::cout << "Reserva cancelada com sucesso" << std::endl;
}



void CntrAprReserva::realizarReserva(Identificador &identificadorUsuario) {

    Identificador idReserva;
    Intervalo_Datas intervaloDatas;
    Data dataInicio;
    Data dataTermino;
    std::string input;
    bool flagCampoInseridoCorretamente = false;


    while (!flagCampoInseridoCorretamente) {
        try {
            std::cout << "Insira o identificador da acomodacao a qual esta reserva pertence: ";
            std::getline(std::cin, input);
            idReserva.setIdentificador(input);
            flagCampoInseridoCorretamente = true;
        } catch (std::invalid_argument &invalid_argument) {
            std::cout << invalid_argument.what() << std::endl;
            flagCampoInseridoCorretamente = false;
        }
    }

    flagCampoInseridoCorretamente = false;
    while (!flagCampoInseridoCorretamente) {
        try {
            std::cout << "Insira a data de inicio da reserva: ";
            std::getline(std::cin, input);
            dataInicio.setData(input);
            flagCampoInseridoCorretamente = true;
        } catch (std::invalid_argument &invalid_argument) {
            std::cout << invalid_argument.what() << std::endl;
            flagCampoInseridoCorretamente = false;
        }
    }

    flagCampoInseridoCorretamente = false;
    while (!flagCampoInseridoCorretamente) {
        try {
            std::cout << "Insira a data de termino da reserva: ";
            std::getline(std::cin, input);
            dataTermino.setData(input);
            flagCampoInseridoCorretamente = true;
        } catch (std::invalid_argument &invalid_argument) {
            std::cout << invalid_argument.what() << std::endl;
            flagCampoInseridoCorretamente = false;
        }
    }

    intervaloDatas.setDataInicio(dataInicio);
    intervaloDatas.setDataTermino(dataTermino);

    try {
        cntrServReserva->realizarReserva(idReserva, intervaloDatas, identificadorUsuario);
    } catch (std::exception &exception){
        std::cout << "Não foi possível realizar a reserva." << std::endl;
        return;
    }

    std::cout << "Reserva realizada com sucesso" << std::endl;
}
CntrAprReserva::~CntrAprReserva() {

}
