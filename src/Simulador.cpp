/*##########################################################################################################*/
// INCLUDE

#include "../lib/CamadaFisica.hpp"
#include "../lib/CamadaEnlace.hpp"
#include <iostream>
#include <string>
#include <assert.h>

/*##########################################################################################################*/
// DEFINE
/*
#define DEBUG_CAMADA_FISICA
#define DEBUG_CAMADA_ENLACE
#define DEBUG_CAMADA_APLICACAO
#define DEBUG_MANCHESTER_TRANSMISSORA
#define DEBUG_MANCHESTER_TRANSMISSORA_DIFERENCIAL
#define DEBUG_MANCHESTER_RECEPTORA
#define DEBUG_MANCHESTER_RECEPTORA_DIFERENCIAL
#define DEBUG_BINARIA_TRANSMISSORA
#define DEBUG_BINARIA_RECEPTORA
#define DEBUG_MEIO_DE_COMUNICACAO
*/
#define assertm(exp, msg) assert(((void)msg, exp))

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
    CamadaAplicacao Simulador;
    CamadaFisica camadafisica;
    CamadaEnlace camadaenlace;
    vector<int> quadro_transmissor;
    vector<int> quadro_receptor;
    vector<int> quadro_meio_comunicacao;

    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(0);
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(0);
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(0);
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(0);
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(0);
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(0);

    camadaenlace.DadosReceptoraEnquadramentoContagemDeCaracteres(quadro_transmissor);

#ifdef DEBUG_CAMADA_FISICA

    // Define o número 5
    quadro_transmissor.push_back(1);
    quadro_transmissor.push_back(0);
    quadro_transmissor.push_back(1);
    // Define o número 5

#ifdef DEBUG_BINARIA_TRANSMISSORA
    quadro_receptor = camadafisica.TransmissoraCodificacaoBinaria(quadro_transmissor);

    assertm(int(quadro_receptor[0]) == 1, "Falha na Codificacao binária");
    assertm(int(quadro_receptor[1]) == 0, "Falha na Codificacao binária");
    assertm(int(quadro_receptor[2]) == 1, "Falha na Codificacao binária");

    cout << "Codificacao binária funcionando" << endl;

#endif

#ifdef DEBUG_MANCHESTER_TRANSMISSORA
    quadro_receptor = camadafisica.TransmissoraCodificacaoManchester(quadro_transmissor);

    assertm(int(quadro_receptor[0]) == 1, "Falha na Codificacao manchester");
    assertm(int(quadro_receptor[1]) == 0, "Falha na Codificacao manchester");
    assertm(int(quadro_receptor[2]) == 0, "Falha na Codificacao manchester");
    assertm(int(quadro_receptor[3]) == 1, "Falha na Codificacao manchester");
    assertm(int(quadro_receptor[4]) == 1, "Falha na Codificacao manchester");
    assertm(int(quadro_receptor[5]) == 0, "Falha na Codificacao manchester");

    cout << "Codificacao manchester funcionando" << endl;

#endif

#ifdef DEBUG_MANCHESTER_TRANSMISSORA_DIFERENCIAL
    quadro_receptor = camadafisica.TransmissoraCodificacaoManchesterDiferencial(quadro_transmissor);

    assertm(int(quadro_receptor[0]) == 1, "Falha na Codificacao Manchester Diferencial");
    assertm(int(quadro_receptor[1]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(quadro_receptor[2]) == 1, "Falha na Codificacao Manchester Diferencial");
    assertm(int(quadro_receptor[3]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(quadro_receptor[4]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(quadro_receptor[5]) == 1, "Falha na Codificacao Manchester Diferencial");

    cout << "Codificacao manchester Diferencial funcionando" << endl;
#endif

#ifdef DEBUG_MEIO_DE_COMUNICACAO
    camadafisica.MeioDeComunicacao(quadro_transmissor);
#endif

#ifdef DEBUG_BINARIA_RECEPTORA
    quadro_receptor = camadafisica.ReceptoraCodificacaoBinaria(quadro_transmissor);

    assertm(int(quadro_receptor[0]) == 1, "Falha na Decodificacao binária");
    assertm(int(quadro_receptor[1]) == 0, "Falha na Decodificacao binária");
    assertm(int(quadro_receptor[2]) == 1, "Falha na Decodificacao binária");

    cout << "Decodificacao Binária Funcionando" << endl;

#endif

#ifdef DEBUG_MANCHESTER_RECEPTORA

    quadro_meio_comunicacao = camadafisica.TransmissoraCodificacaoManchester(quadro_transmissor);
    quadro_receptor = camadafisica.ReceptoraCodificacaoManchester(quadro_meio_comunicacao);

    assertm(int(quadro_receptor[0]) == 1, "Falha na Decodificacao manchester");
    assertm(int(quadro_receptor[1]) == 0, "Falha na Decodificacao manchester");
    assertm(int(quadro_receptor[2]) == 1, "Falha na Decodificacao manchester");

    cout << "Decodificacao Manchester Funcionando" << endl;

#endif

#ifdef DEBUG_MANCHESTER_RECEPTORA_DIFERENCIAL

    quadro_meio_comunicacao = camadafisica.TransmissoraCodificacaoManchesterDiferencial(quadro_transmissor);
    quadro_receptor = camadafisica.ReceptoraCodificacaoManchesterDiferencial(quadro_meio_comunicacao);

    assertm(int(quadro_receptor[0]) == 1, "Falha na Decodificacao manchester");
    assertm(int(quadro_receptor[1]) == 0, "Falha na Decodificacao manchester");
    assertm(int(quadro_receptor[2]) == 1, "Falha na Decodificacao manchester");

    cout << "Decodificacao Manchester Diferencial Funcionando" << endl;

#endif

#endif

    return 0;
}
