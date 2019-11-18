#ifndef CAMADA_FISICA
#define CAMADA_FISICA
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class CamadaFisica
{
public:
    vector<int> quadro;

    void Transmissora(vector<int> quadro);
    vector<int> TransmissoraCodificacaoBinaria(vector<int> quadro);
    vector<int> TransmissoraCodificacaoManchester(vector<int> quadro);
    vector<int> TransmissoraCodificacaoManchesterDiferencial(vector<int> quadro);

    void Receptora(vector<int> quadro);
    vector<int> ReceptoraCodificacaoBinaria(vector<int> quadro);
    vector<int> ReceptoraCodificacaoManchester(vector<int> quadro);
    vector<int> ReceptoraCodificacaoManchesterDiferencial(vector<int> quadro);

    void MeioDeComunicacao(vector<int> fluxoBrutoDeBits);

public:
};

#endif