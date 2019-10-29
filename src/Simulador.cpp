#include "../lib/CamadaEnlace.hpp"
#include "../lib/CamadaFisica.hpp"
#include <iostream>
#include <string>

using namespace std;

class CamadaDeAplicacao
{
private:
    void Transmissora(string mensagem)
    {
        //int quadro [] = mensagem //trabalhar com bits!!!
        //chama a proxima camada
        CamadaFisicaTransmissora(quadro);
    } //fim do metodo CamadaDeAplicacaoTransmissora

    void Receptora(int quadro[])
    {
        //string mensagem = quadro []; //estava trabalhando com bits
        //chama proxima camada
        AplicacaoReceptora(mensagem);
    } //fim do metodo CamadaDeAplicacaoReceptora

    void AplicacaoTransmissora(void)
    {
        string mensagem;
        cout << "Digite uma mensagem:" << endl;
        cin >> mensagem;
        //chama a proxima camada
        CamadaDeAplicacaoTransmissora(mensagem); //em um exemplo mais realistico, aqui seria dado um SEND do SOCKET
    }                                            //fim do metodo AplicacaoTransmissora

    void AplicacaoReceptora(string mensagem)
    {
        cout << "A mensagem recebida foi:" << mensagem << endl;
    } //fim do metodo AplicacaoReceptora

public:
};

void MeioDeComunicacaoEnlace(int fluxoBrutoDeBits[])
{
    //OBS: trabalhar com BITS e nao com BYTES!!!
    int erro, porcentagemDeErros;
    int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB[];
    porcentagemDeErros = 0; //10%, 20%, 30%, 40%, ..., 100%
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA)
    {
        if ((rand() % 100) == ...)                        //fazer a probabilidade do erro
            fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; //BITS!!!
        else                                              //ERRO! INVERTER (usa condicao ternaria)
            (fluxoBrutoBitsPontoB == 0) ? fluxoBrutoBitsPontoA = fluxoBrutoBitsPontoB++ : fluxoBrutoBitsPontoA = fluxoBrutoBitsPontoB--;
    } //fim do while
} //fim do metodo MeioDeTransmissao

/* Este metodo simula a transmissao da informacao no meio de
* comunicacao, passando de um pontoA (transmissor) para um
* ponto B (receptor)
*/
void MeioDeComunicacaoFisica(int fluxoBrutoDeBits[])
{
    //OBS IMPORTANTE: trabalhar com BITS e nao com BYTES!!!
    int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB[];
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA)
    {
        fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; //BITS! Sendo transferidos
    }                                                 //fim do while
    //chama proxima camada
    CamadaFisicaReceptora(fluxoBrutoDeBitsPontoB);
} //fim do metodo MeioDeTransmissao

void main(int argc, char *args[])
{
    AplicacaoTransmissora();

    return 0;
}