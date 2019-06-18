//
// Created by paulo on 14/06/19.
//

#include "../../../Headers/Controladoras/Apresentacao/CntrAprEvento.h"


void printEventos(const std::list<std::pair<Evento, Apresentacao> >& eventos){
    std::string classeEvento;

    for(auto pair : eventos){
        std::cout << "Nome do Evento: " << pair.first.getNomeDeEvento().getNome_De_Evento() << std::endl;
        std::cout << "Codigo da apresentacao:  " << pair.second.getCodigoDeApresentacao().getCodigoApresentacao() << std::endl;
        std::cout << "Data da apresentacao: " << pair.second.getData().getData() << std::endl;
        std::cout << "Horario da apresentacao: " << pair.second.getHorario().getHorario() << std::endl;
        std::cout << "Preco de ingresso da apresentacao: " << pair.second.getPreco().getPreco() << std::endl;
        std::cout << "Numero da sala da apresentacao: " << pair.second.getNumDeSala().getNumSala() << std::endl;
        std::cout << "Ingressos disponiveis da apresentacao: " << pair.second.getDisponibilidade().getDisponibilidade() << std::endl;

        switch (std::stoi(pair.first.getClasseDeEvento().getClasseEvento())){
            case 1:
                classeEvento = "teatro";
                break;
            case 2:
                classeEvento = "esporte";
                break;
            case 3:
                classeEvento = "show nacional";
                break;
            case 4:
                classeEvento = "show internacional";
                break;
        }

        std::cout << "Classe do Evento: " << classeEvento << std::endl;
        std::cout << "Faixa Etaria do Evento: " << pair.first.getFaixaEtaria().getFaixaEtaria() << std::endl;
        std::cout << std::endl << std::endl;
    }
}

void CntrAprEvento::setCntrServEvento(InterServEvento *cntrServEvento) {
    this->cntrServEvento = cntrServEvento;

}

CntrAprEvento::CntrAprEvento() {
    cntrServEvento = nullptr;

}

CntrAprEvento::~CntrAprEvento() {
    delete cntrServEvento;

}

void CntrAprEvento::executar(Usuario &usuario) {
    int escolha;
    bool flag;
    std::string input;
    std::cout << "Sistema de Ingressos - Servicos de Eventos" << std::endl << std::endl;

    std::cout << "1 - Cadastrar evento." << std::endl;
    std::cout << "2 - Descadastrar evento." << std::endl;
    std::cout << "3 - Editar evento." << std::endl;
    std::cout << "4 - Pesquisar evento." << std::endl;
    std::cout << "5 - Sair." << std::endl;

    std::cout << "Escolha a opcao: ";

    std::getline(std::cin, input);
    escolha = std::stoi(input);

    flag = true;

    while (flag){
        switch (escolha) {
            case OPCAO_CADASTRAR_EVENTO:
                cadastrar(usuario);
                flag = false;
                break;
            case OPCAO_DESCADASTRAR_EVENTO:
                descadastrar(usuario);
                flag = false;
                break;
            case OPCAO_EDITAR_EVENTO:
                editar(usuario);
                flag = false;
                break;
            case OPCAO_PESQUISAR_EVENTO:
                pesquisar();
                flag = false;
                break;
            case OPCAO_SAIR_EVENTO:
                flag = false;
            default:
                break;
        }
    }
}

void CntrAprEvento::pesquisar() {
    Data dataInicio;
    Data dataTermino;
    Cidade cidade;
    Estado estado;

    std::list<std::pair<Evento, Apresentacao> > eventos;

    std::string input;

    try {
        std::cout << "Digite a data de inicio               : ";
        std::getline(std::cin, input);
        dataInicio.setData(input);
        std::cout << "Digite a data de termino             : ";
        std::getline(std::cin, input);
        dataTermino.setData(input);
        std::cout << "Digite o estado onde é localizado     : ";
        std::getline(std::cin, input);
        estado.setEstado(input);
        std::cout << "Digite a cidade onde é localizado     : ";
        std::getline(std::cin, input);
        cidade.setCidade(input);
    } catch (std::invalid_argument &e) {
        std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
        return;
    }

    try {
        eventos = cntrServEvento->pesquisar(dataInicio, dataTermino, cidade, estado);
        printEventos(eventos);
    } catch (std::invalid_argument &e) {
        std::cout << std::endl << "Nao foi possivel pesquisar os eventos!" << std::endl;
        return;
    }

}

void CntrAprEvento::cadastrar(const Usuario &usuario) {
    Cidade cidade;
    Nome_De_Evento nomeDeEvento;
    Estado estado;
    Classe_De_Evento classeDeEvento;
    Faixa_Etaria faixaEtaria;

    std::list<Apresentacao> apresentacoes;
    Apresentacao apresentacao;
    Data data;
    Horario horario;
    Preco preco;
    Num_De_Sala numDeSala;
    Disponibilidade disponibilidade;

    int numDeApresentacoes;

    std::string input;
    bool sair = false;

    while (!sair) {
        try {
            std::cout << "Digite o nome do seu evento: ";
            std::getline(std::cin, input);
            nomeDeEvento.setNome_De_Evento(input);
            std::cout << "Digite a cidade do seu evento: ";
            std::getline(std::cin, input);
            cidade.setCidade(input);
            std::cout << "Digite o estado do seu evento: ";
            std::getline(std::cin, input);
            estado.setEstado(input);
            std::cout << "Digite a classe do seu evento: ";
            std::getline(std::cin, input);
            classeDeEvento.setClasseEvento(input);
            std::cout << "Digite a faixa etaria do seu evento: ";
            std::getline(std::cin, input);
            faixaEtaria.setFaixaEtaria(input);

            std::cout << "Digite o numero de apresentacoes do seu evento: ";
            std::getline(std::cin, input);
            numDeApresentacoes = std::stoi(input);
            for (int i = 0; i < numDeApresentacoes; ++i) {
                std::cout << "Digite a data da apresentacao: ";
                std::getline(std::cin, input);
                data.setData(input);
                std::cout << "Digite o horario da apresentacao: ";
                std::getline(std::cin, input);
                horario.setHorario(input);
                std::cout << "Digite o preço da apresentacao: ";
                std::getline(std::cin, input);
                preco.setPreco(input);
                std::cout << "Digite o numero da sala da apresentacao: ";
                std::getline(std::cin, input);
                numDeSala.setNumSala(input);
                std::cout << "Digite o numero de ingressos da apresentacao: ";
                std::getline(std::cin, input);
                disponibilidade.setDisponibilidade(input);

                apresentacao.setPreco(preco);
                apresentacao.setHorario(horario);
                apresentacao.setData(data);
                apresentacao.setDisponibilidade(disponibilidade);
                apresentacao.setNumDeSala(numDeSala);

                apresentacoes.push_back(apresentacao);

            }

            sair = true;
        } catch (std::invalid_argument &e) {
            std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
            return;
        }
    }

    try {
        cntrServEvento->cadastrarEvento(nomeDeEvento, apresentacoes, cidade, estado, classeDeEvento, faixaEtaria, usuario);
    } catch (std::invalid_argument &e) {
        std::cout << std::endl << "Nao foi possivel cadastrar o evento!" << std::endl;
        return;
    }
    std::cout << "Evento cadastrado com sucesso" << std::endl;

}

void CntrAprEvento::descadastrar(const Usuario &usuario) {
    Codigo_De_Evento codigoDeEvento;
    std::string input;
    bool sair = false;

    while (!sair) {
        try {
            std::cout << "Digite o codigo do seu evento: ";
            std::getline(std::cin, input);
            codigoDeEvento.setCodigoEvento(input);
            sair = true;
        } catch (std::invalid_argument &e) {
            std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
            return;
        }
    }

    try {
        cntrServEvento->descadastrarEvento(codigoDeEvento, usuario);
    } catch (std::runtime_error &e) {
        std::cout << std::endl << "Nao foi possivel descadastrar o evento, motivo: " << e.what() << std::endl;
        return;
    }
    std::cout << "Evento descadastrado com sucesso" << std::endl;

}

void CntrAprEvento::editar(const Usuario &usuario) {

    Codigo_De_Evento codigoDeEvento;
    Cidade cidade;
    Nome_De_Evento nomeDeEvento;
    Estado estado;
    Classe_De_Evento classeDeEvento;
    Faixa_Etaria faixaEtaria;

    Evento evento;

    std::string input;
    bool sair = false;

    while (!sair) {
        try {
            std::cout << "Digite o codigo do seu evento: ";
            std::getline(std::cin, input);
            codigoDeEvento.setCodigoEvento(input);
            std::cout << "Digite o nome do seu evento: ";
            std::getline(std::cin, input);
            nomeDeEvento.setNome_De_Evento(input);
            std::cout << "Digite a cidade do seu evento: ";
            std::getline(std::cin, input);
            cidade.setCidade(input);
            std::cout << "Digite o estado do seu evento: ";
            std::getline(std::cin, input);
            estado.setEstado(input);
            std::cout << "Digite a classe do seu evento: ";
            std::getline(std::cin, input);
            classeDeEvento.setClasseEvento(input);
            std::cout << "Digite a faixa etaria do seu evento: ";
            std::getline(std::cin, input);
            faixaEtaria.setFaixaEtaria(input);

            evento.setCodigoDeEvento(codigoDeEvento);
            evento.setNomeDeEvento(nomeDeEvento);
            evento.setClasseDeEvento(classeDeEvento);
            evento.setCidade(cidade);
            evento.setEstado(estado);
            evento.setFaixaEtaria(faixaEtaria);

            sair = true;
        } catch (std::invalid_argument &e) {
            std::cout << std::endl << "Dado em formato incorreto.!" << std::endl;
            return;
        }
    }
    try {
        cntrServEvento->editarEvento(evento, usuario);
    } catch (std::invalid_argument &e) {
        std::cout << std::endl << "Nao foi possivel editar o evento!" << std::endl;
        return;
    }
    std::cout << "Evento editado com sucesso" << std::endl;
}
