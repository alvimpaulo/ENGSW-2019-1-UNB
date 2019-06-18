cmake_minimum_required(VERSION 3.12)
project(Trabalho_1_ENGSW)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

find_package (Threads)

add_executable(Trabalho_1_ENGSW
		main.cpp

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
		Sources/Dominios/Cidade.cpp
		Headers/Dominios/Cidade.h
		Sources/Dominios/Num_Cartao_Credito.cpp
		Headers/Dominios/Num_Cartao_Credito.h
		Sources/Dominios/Senha.cpp
		Headers/Dominios/Senha.h
		Sources/Dominios/Codigo_De_Apresentacao.cpp
		Headers/Dominios/Codigo_De_Apresentacao.h
		Sources/Dominios/Codigo_De_Ingresso.cpp
		Headers/Dominios/Codigo_De_Ingresso.h
		Sources/Dominios/Nome_De_Evento.cpp
		Headers/Dominios/Nome_De_Evento.h
		Sources/Dominios/Codigo_De_Seguranca.cpp
		Headers/Dominios/Codigo_De_Seguranca.h
		Sources/Dominios/Faixa_Etaria.cpp
		Headers/Dominios/Faixa_Etaria.h
		Sources/Dominios/Horario.cpp
		Headers/Dominios/Horario.h
		Sources/Dominios/Disponibilidade.cpp
		Headers/Dominios/Disponibilidade.h
		Sources/Dominios/Classe_De_Evento.cpp
		Headers/Dominios/Classe_De_Evento.h
		Sources/Dominios/Cpf.cpp
		Headers/Dominios/Cpf.h

		Sources/Teste/Dominios/Teste_Codigo_De_Apresentacao.cpp
		Headers/Teste/Dominios/Teste_Codigo_De_Apresentacao.h
		Sources/Teste/Dominios/Teste_Codigo_De_Evento.cpp
		Headers/Teste/Dominios/Teste_Codigo_De_Evento.h
		Sources/Teste/Dominios/Teste_Nome_De_Evento.cpp
		Headers/Teste/Dominios/Teste_Nome_De_Evento.h
		Sources/Teste/Dominios/Teste_Horario.cpp
		Headers/Teste/Dominios/Teste_Horario.h
		Sources/Teste/Dominios/Teste_Preco.cpp
		Headers/Teste/Dominios/Teste_Preco.h
		Sources/Teste/Dominios/Teste_Num_De_Sala.cpp
		Headers/Teste/Dominios/Teste_Num_De_Sala.h
		Sources/Teste/Dominios/Teste_Classe_De_Evento.cpp
		Headers/Teste/Dominios/Teste_Classe_De_Evento.h
		Sources/Teste/Dominios/Teste_Faixa_Etaria.cpp
		Headers/Teste/Dominios/Teste_Faixa_Etaria.h
		Sources/Teste/Dominios/Teste_Cpf.cpp
		Headers/Teste/Dominios/Teste_Cpf.h
		Sources/Teste/Dominios/Teste_Codigo_De_Seguranca.cpp
		Headers/Teste/Dominios/Teste_Codigo_De_Seguranca.h
		Sources/Teste/Dominios/Teste_Codigo_De_Ingresso.cpp
		Headers/Teste/Dominios/Teste_Codigo_De_Ingresso.h
		Sources/Teste/Dominios/Teste_Estado.cpp
		Headers/Teste/Dominios/Teste_Estado.h
		Sources/Teste/Dominios/Teste_Data.cpp
		Headers/Teste/Dominios/Teste_Data.h
		Sources/Teste/Dominios/Teste_Data_De_Validade.cpp
		Headers/Teste/Dominios/Teste_Data_De_Validade.h
		Sources/Teste/Dominios/Teste_Disponibilidade.cpp
		Headers/Teste/Dominios/Teste_Disponibilidade.h
		Sources/Teste/Dominios/Teste_Cidade.cpp
		Headers/Teste/Dominios/Teste_Cidade.h
		Sources/Teste/Dominios/Teste_Num_Cartao.cpp
		Headers/Teste/Dominios/Teste_Num_Cartao.h
		Sources/Teste/Dominios/Teste_Senha.cpp
		Headers/Teste/Dominios/Teste_Senha.h

		Sources/Entidades/Cartao_De_Credito.cpp
		Headers/Entidades/Cartao_De_Credito.h
		Sources/Entidades/Usuario.cpp
		Headers/Entidades/Usuario.h
		Sources/Entidades/Ingresso.cpp
		Headers/Entidades/Ingresso.h
		Sources/Entidades/Evento.cpp
		Headers/Entidades/Evento.h
		Sources/Entidades/Apresentacao.cpp
		Headers/Entidades/Apresentacao.h

		Sources/Teste/Entidades/Teste_Usuario.cpp
		Headers/Teste/Entidades/Teste_Usuario.h
		Sources/Teste/Entidades/Teste_Cartao_De_Credito.cpp
		Headers/Teste/Entidades/Teste_Cartao_De_Credito.h
		Sources/Teste/Entidades/Teste_Evento.cpp
		Headers/Teste/Entidades/Teste_Evento.h
		Sources/Teste/Entidades/Teste_Apresentacao.cpp
		Headers/Teste/Entidades/Teste_Apresentacao.h
		Sources/Teste/Entidades/Teste_Ingresso.cpp
		Headers/Teste/Entidades/Teste_Ingresso.h

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
		Sources/Controladoras/Servico/CntrServUsuarios.cpp
		Headers/Controladoras/Servico/CntrServUsuarios.h
		Sources/Controladoras/Servico/CntrServAutenticacao.cpp
		Headers/Controladoras/Servico/CntrServAutenticacao.h
		Sources/Controladoras/Apresentacao/CntrAprEvento.cpp
		Headers/Controladoras/Apresentacao/CntrAprEvento.h
		Sources/Controladoras/Apresentacao/CntrAprVendas.cpp
		Headers/Controladoras/Apresentacao/CntrAprVendas.h
		Sources/Controladoras/Servico/CntrServVendas.cpp
		Headers/Controladoras/Servico/CntrServVendas.h
		Sources/Controladoras/Servico/CntrServEvento.cpp
		Headers/Controladoras/Servico/CntrServEvento.h

		Headers/Interfaces/Apresentacao/InterAprAutenticacao.h
		Headers/Interfaces/Servico/InterServAutenticacao.h
		Headers/Interfaces/Servico/InterServUsuarios.h
		Headers/Interfaces/Apresentacao/InterAprUsuarios.h
		Headers/Interfaces/Apresentacao/InterAprEvento.h
		Headers/Interfaces/Servico/InterServEvento.h
		Headers/Interfaces/Servico/InterServVendas.h
		Headers/Interfaces/Apresentacao/InterAprVendas.h

		sqlite/sqlite3.c
		sqlite/sqlite3.h

        Sources/ComandoSQL/ComandoSQL.cpp
        Headers/ComandoSQL/ComandoSQL.h
        Sources/ComandoSQL/ComandoAutenticar.cpp
        Headers/ComandoSQL/ComandoAutenticar.h
        Sources/ComandoSQL/ComandoCadastrarUsuario.cpp
        Headers/ComandoSQL/ComandoCadastrarUsuario.h
		Sources/ComandoSQL/ComandoDescadastrarUsuario.cpp
		Headers/ComandoSQL/ComandoDescadastrarUsuario.h
		Sources/ComandoSQL/ComandoGetApresentacoesFromEvento.cpp
		Headers/ComandoSQL/ComandoGetApresentacoesFromEvento.h
		Sources/ComandoSQL/ComandoGetIngressosFromApresentacao.cpp
		Headers/ComandoSQL/ComandoGetIngressosFromApresentacao.h
		Sources/ComandoSQL/ComandoSolicitarInformacaoDeVendas.cpp
		Headers/ComandoSQL/ComandoSolicitarInformacaoDeVendas.h
		Sources/ComandoSQL/ComandoComprarIngresso.cpp
		Headers/ComandoSQL/ComandoComprarIngresso.h
		Sources/ComandoSQL/ComandoCadastrarEvento.cpp
		Headers/ComandoSQL/ComandoCadastrarEvento.h
		Sources/ComandoSQL/ComandoPesquisarEvento.cpp
		Headers/ComandoSQL/ComandoPesquisarEvento.h
		Sources/ComandoSQL/ComandoDescadastrarEvento.cpp
		Headers/ComandoSQL/ComandoDescadastrarEvento.h
		Sources/ComandoSQL/ComandoEditarEvento.cpp
		Headers/ComandoSQL/ComandoEditarEvento.h
		)

target_link_libraries(Trabalho_1_ENGSW  ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS})
