#include "../lib/CamadaFisica.hpp"
#include "../lib/CamadaEnlace.hpp"
#include <iostream>
#include <string>
#include <assert.h>

#define DEBUG_CAMADA_FISICA
#define DEBUG_CAMADA_ENLACE
#define DEBUG_CAMADA_APLICACAO
// #define DEBUG_MANCHESTER_TRANSMISSORA
#define DEBUG_MANCHESTER_TRANSMISSORA_DIFERENCIAL
#define DEBUG_MANCHESTER_RECEPTORA
#define DEBUG_BINARIA_TRANSMISSORA
#define DEBUG_BINARIA_RECEPTORA

#define assertm(exp, msg) assert(((void)msg, exp))

// using namespace std;

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

int main(int argc, char *args[])
{
    CamadaAplicacao Simulador;
    CamadaFisica camadafisica;
    CamadaEnlace camadaenlace;
    vector<int> quadro_transmissor;
    vector<int> quadro_receptor;

    #ifdef DEBUG_CAMADA_FISICA

        // Define o número 5
        quadro_transmissor.push_back(0);
        quadro_transmissor.push_back(1);
        quadro_transmissor.push_back(1);
        // Define o número 5

        #ifdef DEBUG_MANCHESTER_TRANSMISSORA
            quadro_receptor = camadafisica.TransmissoraCodificacaoManchester(quadro_transmissor);

            assertm(int(quadro_receptor[0]) == 1, "Falha na Codificacao Manchester");
            assertm(int(quadro_receptor[1]) == 0, "Falha na Codificacao Manchester");
            assertm(int(quadro_receptor[2]) == 0, "Falha na Codificacao Manchester");
            assertm(int(quadro_receptor[3]) == 1, "Falha na Codificacao Manchester");
            assertm(int(quadro_receptor[4]) == 1, "Falha na Codificacao Manchester");
            assertm(int(quadro_receptor[5]) == 0, "Falha na Codificacao Manchester");

            cout << "Codificacao Manchester funcionando" << endl;
        #endif
        #ifdef DEBUG_MANCHESTER_TRANSMISSORA_DIFERENCIAL
            quadro_receptor = camadafisica.TransmissoraCodificacaoManchesterDiferencial(quadro_transmissor);

            cout << quadro_receptor[0] << endl;
            cout << quadro_receptor[1] << endl;
            cout << quadro_receptor[2] << endl;
            cout << quadro_receptor[3] << endl;
            cout << quadro_receptor[4] << endl;
            cout << quadro_receptor[5] << endl;

            assertm(int(quadro_receptor[0]) == 1, "Falha na Codificacao Manchester Diferencial");
            assertm(int(quadro_receptor[1]) == 0, "Falha na Codificacao Manchester Diferencial");
            assertm(int(quadro_receptor[2]) == 1, "Falha na Codificacao Manchester Diferencial");
            assertm(int(quadro_receptor[3]) == 0, "Falha na Codificacao Manchester Diferencial");
            assertm(int(quadro_receptor[4]) == 0, "Falha na Codificacao Manchester Diferencial");
            assertm(int(quadro_receptor[5]) == 1, "Falha na Codificacao Manchester Diferencial");

            cout << "Codificacao manchester Diferencial funcionando" << endl;
        #endif
    #endif

    return 0;
}
