//
// Created by Oscar Madureira on 18/11/2018.
//

#include "../../Headers/ComandoSQL/ComandoCadastrarUsuario.h"
#include "ios"
#include "iomanip"
#include "sstream"
#include "ctime"
void ComandoCadastrarUsuario::cadastrarUsuario(const Usuario& usuario, const Cartao_De_Credito& cartaoDeCredito) {
    listaResultado.clear();
    comandoSQL = "INSERT INTO Usuarios (Cpf, Senha)\nVALUES ('"
       + usuario.getCpf().getCpf()
       +"', '"
       +usuario.getSenha().getSenha()
       +"');";
    try{
        this->executar();
    } catch(std::exception &e){
        throw std::runtime_error("Não foi possível cadastrar o usuario");
    }
    listaResultado.clear();

    //converter data de dd/mm/aaaa para aaaa-mm-dd
    struct tm tmData;
    strptime(cartaoDeCredito.getDataDeValidade().getData_De_Validade().c_str(), "%d/%m/%Y", &tmData);
    char dataConverted[11];
    strftime(dataConverted, sizeof(dataConverted), "%Y-%m-%d", &tmData);

    comandoSQL= "INSERT INTO CartoesDeCredito VALUES (\n"
                "                                 '" + cartaoDeCredito.getNumero().getNum_Cartao() + "',\n"
                "                                 '" + cartaoDeCredito.getCodigoDeSeguranca().getCodigoSeguranca() + "',\n"
                "                                 '" + dataConverted + "',\n"
                "                                 '" + usuario.getCpf().getCpf() + "'\n"
                "                             );";
}
