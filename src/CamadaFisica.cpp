#include "../lib/CamadaFisica.hpp"

/*##########################################################################################################*/
// TRANSMISSORA

void CamadaFisica::Transmissora(vector<int> quadro)
{
    int tipoDeCodificacao = 0;    //alterar de acordo o teste
    vector<int> fluxoBrutoDeBits; //ATENÇÃO: trabalhar com BITS!!!
    switch (tipoDeCodificacao)
    {
    case 0: //codificao binaria
        fluxoBrutoDeBits = TransmissoraCodificacaoBinaria(quadro);
        break;
    case 1: //codificacao manchester
        fluxoBrutoDeBits = TransmissoraCodificacaoManchester(quadro);
        break;
    case 2: //codificacao manchester diferencial
        fluxoBrutoDeBits = TransmissoraCodificacaoManchesterDiferencial(quadro);
        break;
    } //fim do switch/case
    // MeioDeComunicacao(fluxoBrutoDeBits);
} //fim do metodo CamadaFisicaTransmissora

// CamadaFisicaTransmissoraCodificacaoBinaria
vector<int> CamadaFisica::TransmissoraCodificacaoBinaria(vector<int> quadro)
{
    //implementacao do algoritmo
} //fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria

// CamadaFisicaTransmissoraCodificacaoManchester
vector<int> CamadaFisica::TransmissoraCodificacaoManchester(vector<int> quadro)
{
    cout << "Realizando a Codificação Manchester" << endl;

    vector<int> codificacao_manchester;

    for (int i = 0; i < quadro.size(); i++)
    {
        codificacao_manchester.push_back(quadro[i] ^ 0);
        codificacao_manchester.push_back(quadro[i] ^ 1);
    }

    return codificacao_manchester;
}

// CamadaFisicaTransmissoraCodificacaoManchesterDiferencial
vector<int> CamadaFisica::TransmissoraCodificacaoManchesterDiferencial(vector<int> quadro)
{
    cout << "Realizando a Codificação Manchester Diferencial" << endl;

    vector<int> codificacao_manchester;
    int alternador_bit_0 = 0;
    int alternador_bit_1 = 1;

    codificacao_manchester.push_back(quadro[0] ^ alternador_bit_0);
    codificacao_manchester.push_back(quadro[0] ^ alternador_bit_1);

    for (int i = 1; i < quadro.size(); i++)
    {
        if (quadro[i] == 1)
        {
            alternador_bit_0 = alternador_bit_0 ^ 0;
            alternador_bit_1 = alternador_bit_1 ^ 0;
        }

        codificacao_manchester.push_back(quadro[i] ^ alternador_bit_0);
        codificacao_manchester.push_back(quadro[i] ^ alternador_bit_1);
    }

    return codificacao_manchester;
}

/*##########################################################################################################*/
// RECEPTORA

void CamadaFisica::Receptora(vector<int> quadro)
{
    int tipoDeDecodificacao = 0;  //alterar de acordo o teste
    vector<int> fluxoBrutoDeBits; //ATENÇÃO: trabalhar com BITS!!!
    switch (tipoDeDecodificacao)
    {
    case 0: //codificao binaria
        fluxoBrutoDeBits = ReceptoraCodificacaoBinaria(quadro);
        break;
    case 1: //codificacao manchester
        fluxoBrutoDeBits = ReceptoraCodificacaoManchester(quadro);
        break;
    case 2: //codificacao manchester diferencial
        fluxoBrutoDeBits = ReceptoraCodificacaoManchesterDiferencial(quadro);
        break;
    } //fim do switch/case
    //chama proxima camada
    // CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
} //fim do metodo CamadaFisicaTransmissora
// CamadaFisicaReceptoraDecodificacaoBinaria
vector<int> CamadaFisica::ReceptoraCodificacaoBinaria(vector<int> quadro)
{
    //implementacao do algoritmo para DECODIFICAR
} //fim do metodo CamadaFisicaReceptoraDecodificacaoBinaria
// CamadaFisicaReceptoraDecodificacaoManchester
vector<int> CamadaFisica::ReceptoraCodificacaoManchester(vector<int> quadro)
{
    //implementacao do algoritmo para DECODIFICAR
} //fim do metodo CamadaFisicaReceptoraDecodificacaoManchester
// CamadaFisicaReceptoraDecodificacaoManchesterDiferencial
vector<int> CamadaFisica::ReceptoraCodificacaoManchesterDiferencial(vector<int> quadro)
{
    //implementacao do algoritmo para DECODIFICAR
} //fim do CamadaFisicaReceptoraDecodificacaoManchesterDiferencial

/*##########################################################################################################*/
// MEIO DE COMUNICAÇÃO

/* Este metodo simula a transmissao da informacao no meio de
* comunicacao, passando de um pontoA (transmissor) para um
* ponto B (receptor)
*/
void CamadaFisica::MeioDeComunicacao(vector<int> fluxoBrutoDeBits)
{
    //OBS IMPORTANTE: trabalhar com BITS e nao com BYTES!!!
    vector<int> fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    // while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA)
    // {
    //     fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; //BITS! Sendo transferidos
    // }                                                 //fim do while
    //chama proxima camada
    Receptora(fluxoBrutoDeBitsPontoB);
} //fim do metodo MeioDeTransmissao