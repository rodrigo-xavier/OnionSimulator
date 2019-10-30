#include "../lib/CamadaFisica.hpp"

/*##########################################################################################################*/
// TRANSMISSORA

void CamadaFisica::Transmissora(int quadro[])
{
    int tipoDeCodificacao = 0; //alterar de acordo o teste
    int *fluxoBrutoDeBits;     //ATENÇÃO: trabalhar com BITS!!!
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
    MeioDeComunicacao(fluxoBrutoDeBits);
} //fim do metodo CamadaFisicaTransmissora

int *CamadaFisica::TransmissoraCodificacaoBinaria(int quadro[])
{
    //implementacao do algoritmo
} //fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria
int *CamadaFisica::TransmissoraCodificacaoManchester(int quadro[])
{
    //implementacao do algoritmo
} //fim do metodo CamadaFisicaTransmissoraCodificacaoManchester
int *CamadaFisica::TransmissoraCodificacaoManchesterDiferencial(int quadro[])
{
    //implementacao do algoritmo
} //fim do CamadaFisicaTransmissoraCodificacaoManchesterDiferencial

/*##########################################################################################################*/
// RECEPTORA

void CamadaFisica::Receptora(int quadro[])
{
    int tipoDeDecodificacao = 0; //alterar de acordo o teste
    int *fluxoBrutoDeBits;       //ATENÇÃO: trabalhar com BITS!!!
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

int *CamadaFisica::ReceptoraCodificacaoBinaria(int quadro[])
{
    //implementacao do algoritmo para DECODIFICAR
} //fim do metodo CamadaFisicaReceptoraDecodificacaoBinaria
int *CamadaFisica::ReceptoraCodificacaoManchester(int quadro[])
{
    //implementacao do algoritmo para DECODIFICAR
} //fim do metodo CamadaFisicaReceptoraDecodificacaoManchester
int *CamadaFisica::ReceptoraCodificacaoManchesterDiferencial(int quadro[])
{
    //implementacao do algoritmo para DECODIFICAR
} //fim do CamadaFisicaReceptoraDecodificacaoManchesterDiferencial

/*##########################################################################################################*/
// MEIO DE COMUNICAÇÃO

/* Este metodo simula a transmissao da informacao no meio de
* comunicacao, passando de um pontoA (transmissor) para um
* ponto B (receptor)
*/
void CamadaFisica::MeioDeComunicacao(int fluxoBrutoDeBits[])
{
    //OBS IMPORTANTE: trabalhar com BITS e nao com BYTES!!!
    int *fluxoBrutoDeBitsPontoA, *fluxoBrutoDeBitsPontoB;
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    // while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA)
    // {
    //     fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; //BITS! Sendo transferidos
    // }                                                 //fim do while
    //chama proxima camada
    Receptora(fluxoBrutoDeBitsPontoB);
} //fim do metodo MeioDeTransmissao