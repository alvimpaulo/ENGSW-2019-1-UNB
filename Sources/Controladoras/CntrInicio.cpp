//
// Created by paulo on 16-Nov-18.
//

#include "../../Headers/Controladoras/CntrInicio.h"

void CntrInicio::iniciar() {
    int res;
    std::string input;
    std::string errorMsg;
    bool sair = false;
    while (!sair) {
        std::cout << "1 - Fazer login." << std::endl;
        std::cout << "2 - Cadastrar novo usuario." << std::endl;
        std::cout << "3 - Sair." << std::endl << std::endl;
        std::cout << "Escolha a opcao: ";

        std::getline(std::cin, input);
        res = std::stoi(input);
        if (res == 1) {
            try {
                this->usuario = cntrAprAutenticacao->autenticar();
            }
            catch (std::exception &e) {
                std::cout << e.what() << std::endl;
                continue;
            }
        } else if (res == 2) {
            try {
                cntrAprUsuarios->cadastrar();
                continue;
            } catch (std::exception &exception){
                std::cout << "nao foi possivel cadastrar motivo: " << exception.what()  << std::endl;
                continue;
            }
        } else if(res == 3){
            sair = true;
            return;
        }

        sair = false;
        while (!sair) {

            std::cout << "1 - Gerenciar Usuario." << std::endl;
            std::cout << "2 - Gerenciar Eventos." << std::endl;
            std::cout << "3 - Gerenciar Vendas." << std::endl;
            std::cout << "4 - Sair." << std::endl << std::endl;
            std::cout << "Escolha a opcao: ";

            std::getline(std::cin, input);
            res = std::stoi(input);

            if (res == 1) {
                try {
                    cntrAprUsuarios->executar(usuario);
                } catch (std::runtime_error &error){
                    if(std::strcmp(error.what(), "Usuario descadastrado") == 0){
                        std::cout << "O usuario foi descadastrado com sucesso" << std::endl;
                        break;
                    } else{
                        std::cout << "nao foi possivel gerenciar usuarios motivo: " << error.what() << std::endl;
                    }
                } catch (std::exception &exception) {
                    std::cout << "nao foi possivel gerenciar usuarios motivo: " << exception.what() << std::endl;
                }
            } else if (res == 2) {
                try {
                    cntrAprEvento->executar(usuario);
                } catch (std::exception &exception) {
                    std::cout << "nao foi possivel gerenciar eventos motivo: " << exception.what() << std::endl;
                }
            } else if (res == 3) {
                try {
                    cntrAprVendas->executar(usuario);
                } catch (std::exception &exception) {
                    std::cout << "nao foi possivel gerenciar vendas motivo: " << exception.what() << std::endl;
                    continue;
                }
            } else if (res == 4) {
                sair = true;
            }
        }
        sair = false;
    }
}

CntrInicio::CntrInicio(InterAprEvento *cntrAprEvento, InterAprAutenticacao *cntrAprAutenticacao,
                       InterAprVendas *cntrAprVendas, InterAprUsuarios *cntrAprUsuarios)
        : cntrAprEvento(cntrAprEvento), cntrAprAutenticacao(cntrAprAutenticacao),
          cntrAprVendas(cntrAprVendas), cntrAprUsuarios(cntrAprUsuarios) {

}

CntrInicio::~CntrInicio()= default;
