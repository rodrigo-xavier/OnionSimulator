#ifndef CAMADA_FISICA
#include <iostream>

using namespace std;

class CamadaFisica
{
private:
    void Transmissora(int quadro[]);
    int *TransmissoraCodificacaoBinaria(int quadro[]);
    int *TransmissoraCodificacaoManchester(int quadro[]);
    int *TransmissoraCodificacaoManchesterDiferencial(int quadro[]);

    void Receptora(int quadro[]);
    int *ReceptoraCodificacaoBinaria(int quadro[]);
    int *ReceptoraCodificacaoManchester(int quadro[]);
    int *ReceptoraCodificacaoManchesterDiferencial(int quadro[]);

public:
};

#endif