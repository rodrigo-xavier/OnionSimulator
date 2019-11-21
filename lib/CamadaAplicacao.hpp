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
    string mensagem_recebida;
    vector<int> vetor_bits;

    vector<int> Transmissora(string mensagem)
    {
        vector<int> binario;
        int bit_mensagem;

        cout << endl
             << "Transformando em binário" << endl;

        for (int i = 0; i < mensagem.length(); i++)
        {
            bitset<7> bits(mensagem[i]);
            for (int j = 0; j < 8; j++)
                binario.push_back(int(bits[j]));
        }

        return binario;
    }

    string Receptora(vector<int> quadro)
    {
        string mensagem = "";
        int counter = 0;
        bitset<7> byte;
        char msg;

        cout << "Receptora da Camada de Aplicação" << endl;

        for (int i = 0; i < quadro.size(); i++)
        {
            byte[counter] = quadro[i];

            if (counter == 8)
            {
                msg = char(byte.to_ulong());
                mensagem += msg;
                counter = 0;
            }

            counter++;
        }

        AplicacaoReceptora(mensagem);
    }

    string AplicacaoTransmissora(void)
    {
        string mensagem;
        cout << "Digite uma mensagem:" << endl;
        cin >> mensagem;

        return mensagem;
    }

    void AplicacaoReceptora(string mensagem)
    {
        cout << endl
             << "A mensagem recebida foi:" << mensagem
             << endl;
    }
};

#endif