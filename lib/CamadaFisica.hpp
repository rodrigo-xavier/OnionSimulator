#ifndef CAMADA_FISICA
#define CAMADA_FISICA
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class CamadaFisica
{
private:
    /* Codificação dos bits na codificação manchester
        u = unsigned
        1u = 00000000000000000000000000000001
        2u = 00000000000000000000000000000010
    */
    static const unsigned manchester_bit_1 = 1u;
    static const unsigned manchester_bit_0 = 2u;

    vector<int> quadro;

    void Transmissora(int quadro);
    int *TransmissoraCodificacaoBinaria(int quadro);
    int *TransmissoraCodificacaoManchester(int quadro);
    int *TransmissoraCodificacaoManchesterDiferencial(int quadro);

    void Receptora(int quadro);
    int *ReceptoraCodificacaoBinaria(int quadro);
    int *ReceptoraCodificacaoManchester(int quadro);
    int *ReceptoraCodificacaoManchesterDiferencial(int quadro);

    void MeioDeComunicacao(int fluxoBrutoDeBits[]);

public:
};

#endif