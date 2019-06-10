cmake_minimum_required(VERSION 3.12)
project(Trabalho_1_Clion)

set(CMAKE_CXX_STANDARD 11)

add_executable(Trabalho_1_Clion
		main.cpp
		Sources/Dominios/Agencia.cpp
		Headers/Dominios/Agencia.h
        Sources/Dominios/Codigo_De_Evento.cpp
        Headers/Dominios/Codigo_De_Evento.h
		Sources/Dominios/Num_De_Sala.cpp
		Headers/Dominios/Num_De_Sala.h
        Sources/Dominios/Preco.cpp
        Headers/Dominios/Preco.h
		Sources/Dominios/Data.cpp
		Headers/Dominios/Data.h
		Sources/Dominios/Data_De_Validade.cpp
		Headers/Dominios/Data_De_Validade.h
		Sources/Dominios/Estado.cpp
		Headers/Dominios/Estado.h
		Sources/Dominios/Identificador.cpp
		Headers/Dominios/Identificador.h
		Sources/Dominios/Cidade.cpp
		Headers/Dominios/Cidade.h
		Sources/Dominios/Num_Cartao_Credito.cpp
		Headers/Dominios/Num_Cartao_Credito.h
		Sources/Dominios/Num_Conta_Corrente.cpp
		Headers/Dominios/Num_Conta_Corrente.h
		Sources/Dominios/Senha.cpp
		Headers/Dominios/Senha.h
		Sources/Dominios/Tipo_Acomodacao.cpp
		Headers/Dominios/Tipo_Acomodacao.h

		Sources/Teste/Dominios/Teste_Agencia.cpp
		Headers/Teste/Dominios/Teste_Agencia.h
		Sources/Teste/Dominios/Teste_Tipo_Acomodacao.cpp
		Headers/Teste/Dominios/Teste_Tipo_Acomodacao.h
		Sources/Teste/Dominios/Teste_Estado.cpp
		Headers/Teste/Dominios/Teste_Estado.h
		Sources/Teste/Dominios/Teste_Diaria.cpp
		Headers/Teste/Dominios/Teste_Diaria.h
		Sources/Teste/Dominios/Teste_Data.cpp
		Headers/Teste/Dominios/Teste_Data.h
		Sources/Teste/Dominios/Teste_Data_De_Validade.cpp
		Headers/Teste/Dominios/Teste_Data_De_Validade.h
		Sources/Teste/Dominios/Teste_Banco.cpp
		Headers/Teste/Dominios/Teste_Banco.h
		Sources/Teste/Dominios/Teste_Capacidade_De_Acomodacao.cpp
		Headers/Teste/Dominios/Teste_Capacidade_De_Acomodacao.h
		Sources/Teste/Dominios/Teste_Nome.cpp
		Headers/Teste/Dominios/Teste_Nome.h
		Sources/Teste/Dominios/Teste_Identificador.cpp
		Headers/Teste/Dominios/Teste_Identificador.h
		Sources/Teste/Dominios/Teste_Num_Cartao.cpp
		Headers/Teste/Dominios/Teste_Num_Cartao.h
		Sources/Teste/Dominios/Teste_Num_Conta_Corrente.cpp
		Headers/Teste/Dominios/Teste_Num_Conta_Corrente.h
		Sources/Teste/Dominios/Teste_Senha.cpp
		Headers/Teste/Dominios/Teste_Senha.h

		Sources/Entidades/Acomodacao.cpp
		Headers/Entidades/Acomodacao.h
		Sources/Entidades/Cartao_De_Credito.cpp
		Headers/Entidades/Cartao_De_Credito.h
		Sources/Entidades/Conta_Corrente.cpp
		Headers/Entidades/Conta_Corrente.h
		Sources/Entidades/Usuario.cpp
		Headers/Entidades/Usuario.h
		Sources/Entidades/Intervalo_Datas.cpp
		Headers/Entidades/Intervalo_Datas.h

		Sources/Teste/Entidades/Teste_Acomodacao.cpp
		Headers/Teste/Entidades/Teste_Acomodacao.h
		Sources/Teste/Entidades/Teste_Usuario.cpp
		Headers/Teste/Entidades/Teste_Usuario.h
		Sources/Teste/Entidades/Teste_Cartao_De_Credito.cpp
		Headers/Teste/Entidades/Teste_Cartao_De_Credito.h
		Sources/Teste/Entidades/Teste_Conta_Corrente.cpp
		Headers/Teste/Entidades/Teste_Conta_Corrente.h

		Sources/Teste/Teste.cpp
		Headers/Teste/Teste.h

		Sources/Teste/Entidades/Teste_Entidades.cpp
		Headers/Teste/Entidades/Teste_Entidades.h

		Sources/Teste/Dominios/Teste_Dominios.cpp
		Headers/Teste/Dominios/Teste_Dominios.h

		Sources/Controladoras/Apresentacao/CntrAprUsuarios.cpp
		Headers/Controladoras/Apresentacao/CntrAprUsuarios.h
		Sources/Controladoras/Apresentacao/CntrAprAutenticacao.cpp
		Headers/Controladoras/Apresentacao/CntrAprAutenticacao.h
		Sources/Controladoras/CntrInicio.cpp
		Headers/Controladoras/CntrInicio.h
		Sources/Controladoras/Apresentacao/CntrAprAcomodacao.cpp
		Headers/Controladoras/Apresentacao/CntrAprAcomodacao.h
		Sources/Controladoras/Apresentacao/CntrAprReserva.cpp
		Headers/Controladoras/Apresentacao/CntrAprReserva.h
		Sources/Controladoras/Servico/CntrsServAcomodacao.cpp
		Headers/Controladoras/Servico/CntrsServAcomodacao.h
		Sources/Controladoras/Servico/CntrsServUsuarios.cpp
		Headers/Controladoras/Servico/CntrsServUsuarios.h
		Sources/Controladoras/Servico/CntrsServReserva.cpp
		Headers/Controladoras/Servico/CntrsServReserva.h
		Sources/Controladoras/Servico/CntrsServAutenticacao.cpp
		Headers/Controladoras/Servico/CntrsServAutenticacao.h

		Headers/Interfaces/Apresentacao/InterAprAutenticacao.h
		Headers/Interfaces/Servico/InterServAutenticacao.h
		Headers/Interfaces/Servico/InterServUsuarios.h
		Headers/Interfaces/Servico/InterServAcomodacao.h
		Headers/Interfaces/Servico/InterServReserva.h
		Headers/Interfaces/Apresentacao/InterAprUsuarios.h
		Headers/Interfaces/Apresentacao/InterAprAcomodacao.h
		Headers/Interfaces/Apresentacao/InterAprReserva.h

		sqlite/sqlite3.c
		sqlite/sqlite3.h

        Sources/ComandoSQL/ComandoSQL.cpp
        Headers/ComandoSQL/ComandoSQL.h
        Sources/ComandoSQL/ComandoAutenticar.cpp
        Headers/ComandoSQL/ComandoAutenticar.h
        Sources/ComandoSQL/ComandoCadastrarUsuario.cpp
        Headers/ComandoSQL/ComandoCadastrarUsuario.h
        Sources/ComandoSQL/ComandoPesquisarAcomodacao.cpp
        Headers/ComandoSQL/ComandoPesquisarAcomodacao.h
        Sources/ComandoSQL/ComandoCadastrarAcomodacao.cpp
        Headers/ComandoSQL/ComandoCadastrarAcomodacao.h
        Sources/ComandoSQL/ComandoCadastrarDisponibilidadeAcomodacao.cpp
        Headers/ComandoSQL/ComandoCadastrarDisponibilidadeAcomodacao.h
        Sources/ComandoSQL/ComandoDescadastrarAcomodacao.cpp
        Headers/ComandoSQL/ComandoDescadastrarAcomodacao.h
        Sources/ComandoSQL/ComandoEditarAcomodacao.cpp
        Headers/ComandoSQL/ComandoEditarAcomodacao.h
		Sources/ComandoSQL/ComandoRealizarReserva.cpp
		Headers/ComandoSQL/ComandoRealizarReserva.h
		Sources/ComandoSQL/ComandoCancelarReserva.cpp
		Headers/ComandoSQL/ComandoCancelarReserva.h
       Sources/ComandoSQL/ComandoDescadastrarUsuario.cpp
		Headers/ComandoSQL/ComandoDescadastrarUsuario.h
		Sources/ComandoSQL/ComandoDescadastrarContaCorrente.cpp
		Headers/ComandoSQL/ComandoDescadastrarContaCorrente.h
		Sources/ComandoSQL/ComandoDescadastrarCartaoCredito.cpp
		Headers/ComandoSQL/ComandoDescadastrarCartaoCredito.h
		Sources/ComandoSQL/ComandoCadastrarContaCorrente.cpp
		Headers/ComandoSQL/ComandoCadastrarContaCorrente.h
		Sources/ComandoSQL/ComandoCadastrarCartaoCredito.cpp
		Headers/ComandoSQL/ComandoCadastrarCartaoCredito.h
		Sources/ComandoSQL/ComandoEditarUsuario.cpp
		Headers/ComandoSQL/ComandoEditarUsuario.h
		Sources/ComandoSQL/ComandoDescadastrarDisponibilidade.cpp
		Headers/ComandoSQL/ComandoDescadastrarDisponibilidade.h
		Sources/ComandoSQL/ComandoChecarContaCorrente.cpp
		Headers/ComandoSQL/ComandoChecarContaCorrente.h Sources/Dominios/Codigo_De_Apresentacao.cpp Headers/Dominios/Codigo_De_Apresentacao.h Sources/Dominios/Codigo_De_Ingresso.cpp Headers/Dominios/Codigo_De_Ingresso.h Sources/Dominios/Nome_De_Evento.cpp Headers/Dominios/Nome_De_Evento.h Sources/Dominios/Codigo_De_Seguranca.cpp Headers/Dominios/Codigo_De_Seguranca.h Sources/Dominios/Faixa_Etaria.cpp Headers/Dominios/Faixa_Etaria.h Sources/Dominios/Horario.cpp Headers/Dominios/Horario.h Sources/Dominios/Disponibilidade.cpp Headers/Dominios/Disponibilidade.h Sources/Dominios/Classe_De_Evento.cpp Headers/Dominios/Classe_De_Evento.h Sources/Dominios/Cpf.cpp Headers/Dominios/Cpf.h Sources/Entidades/Ingresso.cpp Headers/Entidades/Ingresso.h Sources/Entidades/Evento.cpp Headers/Entidades/Evento.h Sources/Entidades/Apresentacao.cpp Headers/Entidades/Apresentacao.h Headers/Interfaces/Apresentacao/InterAprEvento.h Headers/Interfaces/Servico/InterServEvento.h)