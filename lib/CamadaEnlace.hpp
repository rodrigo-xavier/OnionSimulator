#ifndef CAMADA_ENLACE
#define CAMADA_ENLACE
#include "CamadaFisica.hpp"
#include <iostream>

using namespace std;

class CamadaEnlace
{
public:
    void DadosTransmissora(int quadro[]);

    void DadosTransmissoraEnquadramento(int quadro[]);
    void DadosTransmissoraEnquadramentoContagemDeCaracteres(int quadro[]);
    void DadosTransmissoraEnquadramentoInsercaoDeBytes(int quadro[]);
    void DadosTransmissoraEnquadramentoInsercaoDeBits(int quadro[]);
    void DadosTransmissoraEnquadramentoViolacaoDaCamadaFisica(int quadro[]);

    void DadosTransmissoraControleDeErro(int quadro[]);
    void DadosTransmissoraControleDeFluxo(int quadro[]);
    void DadosTransmissoraControleDeErroBitParidadePar(int quadro[]);
    void DadosTransmissoraControleDeErroBitParidadeImpar(int quadro[]);
    void DadosTransmissoraControleDeErroCRC(int quadro[]);
    void DadosTransmissoraControleDeErroCodigoDeHamming(int quadro[]);

    void DadosReceptora(int quadro[]);

    void DadosReceptoraEnquadramento(int quadro[]);
    void DadosReceptoraEnquadramentoContagemDeCaracteres(int quadro[]);
    void DadosReceptoraEnquadramentoInsercaoDeBytes(int quadro[]);
    void DadosReceptoraEnquadramentoInsercaoDeBits(int quadro[]);
    void DadosReceptoraEnquadramentoViolacaoDaCamadaFisica(int quadro[]);

    void DadosReceptoraControleDeErro(int quadro[]);
    void DadosReceptoraControleDeFluxo(int quadro[]);
    void DadosReceptoraControleDeErroBitDeParidadePar(int quadro[]);
    void DadosReceptoraControleDeErroBitDeParidadeImpar(int quadro[]);
    void DadosReceptoraControleDeErroCRC(int quadro[]);
    void DadosReceptoraControleDeErroCodigoDeHamming(int quadro[]);

    void MeioDeComunicacao(int fluxoBrutoDeBits[]);

public:
};

#endif