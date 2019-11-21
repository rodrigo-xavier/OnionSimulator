#ifndef CAMADA_APLICACAO
#define CAMADA_APLICACAO

#include "CamadaFisica.hpp"
#include "CamadaEnlace.hpp"
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

/*##########################################################################################################*/
// CamadaAplicacao

class CamadaAplicacao
{
public:
    CamadaEnlace camadaenlace;
    CamadaFisica camadafisica;
    string mensagem;

    void AplicacaoTransmissora(void)
    {
        string mensagem;
        cout << "Digite uma mensagem:" << endl;
        cin >> mensagem;

        Transmissora(mensagem);
        //chama a proxima camada
        // CamadaDeAplicacaoTransmissora(mensagem); //em um exemplo mais realistico, aqui seria dado um SEND do SOCKET
    }

    void Transmissora(string mensagem)
    {
        vector<int> binario;
        int bit_mensagem;
        cout << "Transformando em binário: ";
        for (int i = 0; i < mensagem.size(); i++)
        {
            bitset<8> bits(mensagem.c_str()[i]);
            for (int j = 0; j < 8; j++)
                binario.push_back(int(bits[j]));
        }

        for (int i = 0; i < binario.size(); i++)
            cout << binario.at(i);

        cout << endl;

        //chama a proxima camada
        // CamadaFisicaTransmissora(quadro);
        camadafisica.Transmissora(binario);
    }

    void Receptora(vector<int> quadro)
    {
        string mensagem = "";
        int counter = 0;
        bitset<8> byte;
        char msg;

        cout << "Receptora da Camada de Aplicação: ";

        for (int i = 0; i < quadro.size(); i++)
        {
            byte[counter] = quadro[i];
            if (counter == 8)
            {
                msg = (char)byte.to_ulong();
                mensagem += msg;
                counter = 0;
            }

            counter++;
        }

        cout << endl;

        AplicacaoReceptora(mensagem);
    }

    void AplicacaoReceptora(string mensagem)
    {
        cout << "A mensagem recebida foi:" << mensagem << endl;
    }
};

#endif