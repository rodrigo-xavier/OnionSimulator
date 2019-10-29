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
        fluxoBrutoDeBits = ReceptoraDecodificacaoBinaria(quadro);
        break;
    case 1: //codificacao manchester
        fluxoBrutoDeBits = ReceptoraDecodificacaoManchester(quadro);
        break;
    case 2: //codificacao manchester diferencial
        fluxoBrutoDeBits = ReceptoraDecodificacaoManchesterDiferencial(quadro);
        break;
    } //fim do switch/case
    //chama proxima camada
    CamadaDeAplicacaoReceptora(fluxoBrutoDeBits);
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