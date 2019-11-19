/*##########################################################################################################*/
// INCLUDE

#include "../lib/CamadaFisica.hpp"
#include "../lib/CamadaEnlace.hpp"
#include "../lib/Testes.hpp"
#include <iostream>
#include <string>

/*##########################################################################################################*/
// CamadaAplicacao

class CamadaAplicacao
{
private:
    CamadaEnlace camadaenlace;

    void Transmissora(string mensagem)
    {
        //int quadro [] = mensagem //trabalhar com bits!!!
        //chama a proxima camada
        // CamadaFisicaTransmissora(quadro);
    } //fim do metodo CamadaDeAplicacaoTransmissora

    void Receptora(int quadro[])
    {
        //string mensagem = quadro []; //estava trabalhando com bits
        //chama proxima camada
        // AplicacaoReceptora(mensagem);
    } //fim do metodo CamadaDeAplicacaoReceptora

    void AplicacaoTransmissora(void)
    {
        string mensagem;
        cout << "Digite uma mensagem:" << endl;
        cin >> mensagem;
        //chama a proxima camada
        // CamadaDeAplicacaoTransmissora(mensagem); //em um exemplo mais realistico, aqui seria dado um SEND do SOCKET
    } //fim do metodo AplicacaoTransmissora

    void AplicacaoReceptora(string mensagem)
    {
        cout << "A mensagem recebida foi:" << mensagem << endl;
    } //fim do metodo AplicacaoReceptora

public:
};

/*##########################################################################################################*/
// MAIN

int main(int argc, char *args[])
{
    Testes teste;

    teste.init();

    return 0;
}
