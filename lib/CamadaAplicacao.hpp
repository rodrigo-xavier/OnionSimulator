#include "CamadaFisica.hpp"
#include "CamadaEnlace.hpp"
#include <iostream>
#include <string>

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
        //int quadro [] = mensagem //trabalhar com bits!!!
        vector<int> binario;
        int bit_mensagem;
        cout << "Transformando em binário" << endl;
        for (int i = 0; i < mensagem.size(); i++)
        {
            bitset<8> bits(mensagem.c_str()[i]);
            for (int j = 0; j < 8; j++)
            {
                binario.push_back(int(bits[j]));
            }
        }

        for (int i = 0; i < binario.size(); i++)
        {
            cout << binario.at(i);
        }
        cout << endl;

        return binario;
        //chama a proxima camada
        // CamadaFisicaTransmissora(quadro);
        //camadafisica.Transmissora(binario);
    } //fim do metodo CamadaDeAplicacaoTransmissora

    string Receptora(vector<int> quadro)
    {
        cout << "Receptora da Camada de Aplicação";
        for (int i = 0; i < quadro.size(); i++)
        {
            cout << quadro.at(i); //estava trabalhando com bits
        }
        cout << endl;
        //chama proxima camada
        return "mensagem a ser recebida";
        //this->mensagem = "mensagem a ser recebida";
        // AplicacaoReceptora(mensagem);
    } //fim do metodo CamadaDeAplicacaoReceptora

    string AplicacaoTransmissora(void)
    {
        string mensagem;
        cout << "Digite uma mensagem:" << endl;
        cin >> mensagem;

        //Transmissora(mensagem);
        //chama a proxima camada
        return mensagem;
        // CamadaDeAplicacaoTransmissora(mensagem); //em um exemplo mais realistico, aqui seria dado um SEND do SOCKET
    } //fim do metodo AplicacaoTransmissora

    void AplicacaoReceptora(string mensagem)
    {
        cout << "A mensagem recebida foi:" << mensagem << endl;
    } //fim do metodo AplicacaoReceptora
};
