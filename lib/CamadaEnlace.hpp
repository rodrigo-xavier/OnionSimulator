#ifndef CAMADA_ENLACE
#define CAMADA_ENLACE
#include "CamadaFisica.hpp"
#include <iostream>
#include <math.h>
#include <algorithm>

#define BYTE 8

// using namespace std;

class CamadaEnlace
{
public:
    vector<int> quadro;
    string flag = "00001111";
    string esc = "11110000";
    string flag_bit = "01111110";
    string polinomio_crc_32 = "100110000010001110110110111";

    vector<int> DadosTransmissora(vector<int> quadro);

    void DadosTransmissoraEnquadramento(vector<int> quadro);
    void DadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro);
    void DadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro);
    void DadosTransmissoraEnquadramentoInsercaoDeBits(vector<int> quadro);

    void DadosTransmissoraControleDeErro(vector<int> quadro);
    void DadosTransmissoraControleDeErroBitParidadePar(vector<int> quadro);
    void DadosTransmissoraControleDeErroBitParidadeImpar(vector<int> quadro);
    void DadosTransmissoraControleDeErroCRC(vector<int> quadro);
    void DadosTransmissoraControleDeErroCodigoDeHamming(vector<int> quadro);

    vector<int> DadosReceptora(vector<int> quadro);

    void DadosReceptoraEnquadramento(vector<int> quadro);
    void DadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro);
    void DadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro);
    void DadosReceptoraEnquadramentoInsercaoDeBits(vector<int> quadro);

    void DadosReceptoraControleDeErro(vector<int> quadro);
    void DadosReceptoraControleDeErroBitDeParidadePar(vector<int> quadro);
    void DadosReceptoraControleDeErroBitDeParidadeImpar(vector<int> quadro);
    void DadosReceptoraControleDeErroCRC(vector<int> quadro);
    void DadosReceptoraControleDeErroCodigoDeHamming(vector<int> quadro);

    void MeioDeComunicacao(vector<int> fluxoBrutoDeBits);
};

#endif