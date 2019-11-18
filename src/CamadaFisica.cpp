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
    MeioDeComunicacao(fluxoBrutoDeBits);
} //fim do metodo CamadaFisicaTransmissora

// CamadaFisicaTransmissoraCodificacaoBinaria
vector<int> CamadaFisica::TransmissoraCodificacaoBinaria(vector<int> quadro)
{
    //implementacao do algoritmo
    cout << "Realizando a codificação binária" << endl;

    vector<int> codificacao_binaria;

    for (int i = 0; i < quadro.size(); i++){
        codificacao_binaria.push_back(quadro[i]);
    }
    
    return codificacao_binaria;

} //fim do metodo CamadaFisicaTransmissoraCodificacaoBinaria

// CamadaFisicaTransmissoraCodificacaoManchester
//demetrio passou por aqui
vector<int> CamadaFisica::TransmissoraCodificacaoManchester(vector<int> quadro)
{
    cout << "Realizando a codificação manchester" << endl;

    vector<int> codificacao_manchester;

    for (int i = 0; i < quadro.size(); i++)
    {
        codificacao_manchester.push_back(quadro[i] ^ 0);
        codificacao_manchester.push_back(quadro[i] ^ 1);
    }

    return codificacao_manchester;
}
vector<int> CamadaFisica::TransmissoraCodificacaoManchesterDiferencial(vector<int> quadro)
{
    //implementacao do algoritmo
} //fim do CamadaFisicaTransmissoraCodificacaoManchesterDiferencial

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
    cout << "Realizando a decodificação binária" << endl;

    vector<int> decodificacao_binaria;

    for (int i = 0; i < quadro.size(); i++){
        decodificacao_binaria.push_back(quadro[i]);
    }
    
    return decodificacao_binaria;    

} //fim do metodo CamadaFisicaReceptoraDecodificacaoBinaria
// CamadaFisicaReceptoraDecodificacaoManchester
vector<int> CamadaFisica::ReceptoraCodificacaoManchester(vector<int> quadro)
{
    //implementacao do algoritmo para DECODIFICAR
    cout << "Realizando a decodificação manchester" << endl;

    vector<int> decodificacao_manchester;

    for (int i = 0; i < quadro.size(); i=i+2)
    {
        if (int(quadro[i]) == 0 && int(quadro[i+1] == 1)){
            decodificacao_manchester.push_back(0);
        } else if (int(quadro[i]) == 1 && int(quadro[i+1] == 0)){
            decodificacao_manchester.push_back(1);
        } else { 
            cout << "Erro na Decodificação" << endl;
        }

    }

    return decodificacao_manchester;

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
    for (int i = 0; i < fluxoBrutoDeBitsPontoA.size(); i++) {
         //BITS! Sendo transferidos
        fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA.at(i));
    } //fim do while

    //chama proxima camada
    //Receptora(fluxoBrutoDeBitsPontoB);
} //fim do metodo MeioDeTransmissao