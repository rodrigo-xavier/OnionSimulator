#include "../lib/CamadaEnlace.hpp"

/*##########################################################################################################*/
// TRANSMISSORA

void CamadaEnlace::DadosTransmissora(vector<int> quadro)
{
    DadosTransmissoraEnquadramento(quadro);
    DadosTransmissoraControleDeErro(quadro);
    //chama proxima camada
    // CamadaFisicaTransmissora(quadro);
} //fim do metodo CamadaEnlaceDadosTransmissora

/*##########################################################################################################*/
// TRANSMISSORA: ENQUADRAMENTO

void CamadaEnlace::DadosTransmissoraEnquadramento(vector<int> quadro)
{
    int tipoDeEnquadramento = 0; //alterar de acordo com o teste
    vector<int> quadroEnquadrado;
    switch (tipoDeEnquadramento)
    {
    case 0: //contagem de caracteres
        quadroEnquadrado = DadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
        break;
    case 1: //insercao de bytes
        quadroEnquadrado = DadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
        break;
    case 2: //insercao de bits
        quadroEnquadrado = DadosTransmissoraEnquadramentoInsercaoDeBits(quadro);
    case 3: //violacao da camada fisica
        // DadosTransmissoraEnquadramentoViolacaoCamadaFisica(quadro);
        break;
    } //fim do switch/case
    DadosTransmissoraControleDeErro(quadroEnquadrado);
} //fim do metodo CamadaEnlaceTransmissoraEnquadramento

vector<int> CamadaEnlace::DadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro)
{
    //implementacao do algoritmo
    int qtd_bytes = ceil(quadro.size() / 8);
    vector<int> enquadramento_contagem_caracteres;

    enquadramento_contagem_caracteres.push_back(qtd_bytes);

    for (int i = 0; i < quadro.size(); i++)
        enquadramento_contagem_caracteres.push_back(quadro[i]);

    for (int i = 0; i < enquadramento_contagem_caracteres.size(); i++)
        cout << enquadramento_contagem_caracteres[i];

    cout << endl;

    return enquadramento_contagem_caracteres;

} //fim do metodo DadosTransmissoraContagemDeCaracteres

vector<int> CamadaEnlace::DadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro)
{
    //implementacao do algoritmo
} //fim do metodo DadosTransmissoraInsercaoDeBytes

vector<int> CamadaEnlace::DadosTransmissoraEnquadramentoInsercaoDeBits(vector<int> quadro)
{
    //implementacao do algoritmo
} //fim do metodo DadosTransmissoraInsercaoDeBits

vector<int> CamadaEnlace::DadosTransmissoraEnquadramentoViolacaoDaCamadaFisica(vector<int> quadro)
{
    //implementacao do algoritmo
} //fim do metodo DadosTransmissoraViolacaoDaCamadaFisica

/*##########################################################################################################*/
// TRANSMISSORA: CONTROLE

void CamadaEnlace::DadosTransmissoraControleDeErro(vector<int> quadro)
{
    int tipoDeControleDeErro = 0; //alterar de acordo com o teste
    switch (tipoDeControleDeErro)
    {
    case 0: //bit de paridade par
        //codigo
        break;
    case 1: //bit de paridade impar
        //codigo
        break;
    case 2: //CRC
    //codigo
    case 3: //codigo de Hamming
        //codigo
        break;
    } //fim do switch/case
} //fim do metodo DadosTransmissoraControleDeErro

void CamadaEnlace::DadosTransmissoraControleDeFluxo(vector<int> quadro)
{
    //algum codigo aqui
} //fim do metodo DadosTransmissoraControleDeFluxo

void CamadaEnlace::DadosTransmissoraControleDeErroBitParidadePar(vector<int> quadro)
{
    //implementacao do algoritmo
} //fim do metodo DadosTransmissoraControledeErroBitParidadePar

void CamadaEnlace::DadosTransmissoraControleDeErroBitParidadeImpar(vector<int> quadro)
{
    //implementacao do algoritmo
} //fim do metodo DadosTransmissoraControledeErroBitParidadeImpar

void CamadaEnlace::DadosTransmissoraControleDeErroCRC(vector<int> quadro)
{
    //implementacao do algoritmo
    //usar polinomio CRC-32(IEEE 802)
} //fim do metodo DadosTransmissoraControledeErroCRC

void CamadaEnlace::DadosTransmissoraControleDeErroCodigoDeHamming(vector<int> quadro)
{
    //implementacao do algoritmo
} //fim do metodo DadosTransmissoraControleDeErroCodigoDehamming

/*##########################################################################################################*/
// RECEPTORA

void CamadaEnlace::DadosReceptora(vector<int> quadro)
{
    DadosTransmissoraEnquadramento(quadro);
    DadosTransmissoraControleDeErro(quadro);
    DadosTransmissoraControleDeFluxo(quadro);
    //chama proxima camada
    // CamadaDeAplicacaoReceptora(quadro);
} //fim do metodo DadosReceptora

/*##########################################################################################################*/
// RECEPTORA: ENQUADRAMENTO

void CamadaEnlace::DadosReceptoraEnquadramento(vector<int> quadro)
{
    int tipoDeEnquadramento = 0; //alterar de acordo com o teste
    vector<int> quadroDesenquadrado;
    switch (tipoDeEnquadramento)
    {
    case 0: //contagem de caracteres
        DadosTransmissoraEnquadramentoContagemDeCaracteres(quadro);
        break;
    case 1: //insercao de bytes
        DadosTransmissoraEnquadramentoInsercaoDeBytes(quadro);
        break;
    case 2: //insercao de bits
        DadosTransmissoraEnquadramentoInsercaoDeBits(quadro);
    case 3: //violacao da camada fisica
        // DadosTransmissoraEnquadramentoViolacaoCamadaFisica(quadro);
        break;
    } //fim do switch/case
} //fim do metodo DadosReceptoraEnquadramento

vector<int> CamadaEnlace::DadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro)
{
    //implementacao do algoritmo para DESENQUADRAR
    int qtd_bytes = quadro.front();
    vector<int> desenquadramento_contagem_caracteres;

    for (int i = 1; i < quadro.size(); i++)
        desenquadramento_contagem_caracteres.push_back(quadro[i]);

    for (int i = 0; i < desenquadramento_contagem_caracteres.size(); i++)
        cout << desenquadramento_contagem_caracteres[i];

    cout << endl;

    return desenquadramento_contagem_caracteres;
} //fim do metodo DadosReceptoraContagemDeCaracteres

vector<int> CamadaEnlace::DadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro)
{
    //implementacao do algoritmo para DESENQUADRAR

} //fim do metodo DadosReceptoraInsercaoDeBytes

vector<int> CamadaEnlace::DadosReceptoraEnquadramentoInsercaoDeBits(vector<int> quadro)
{
    //implementacao do algoritmo para DESENQUADRAR
} //fim do metodo DadosReceptoraInsercaoDeBits

vector<int> CamadaEnlace::DadosReceptoraEnquadramentoViolacaoDaCamadaFisica(vector<int> quadro)
{
    //implementacao do algoritmo para DESENQUADRAR
} //fim do metodo DadosReceptoraViolacaoDaCamadaFisica

/*##########################################################################################################*/
// RECEPTORA: CONTROLE

void CamadaEnlace::DadosReceptoraControleDeErro(vector<int> quadro)
{
    int tipoDeControleDeErro = 0; //alterar de acordo com o teste
    switch (tipoDeControleDeErro)
    {
    case 0: //bit de paridade par
        //codigo
        break;
    case 1: //bit de paridade impar
        //codigo
        break;
    case 2: //CRC
    //codigo
    case 3: //codigo de hamming
        //codigo
        break;
    } //fim do switch/case
} //fim do metodo DadosReceptoraControleDeErro

void CamadaEnlace::DadosReceptoraControleDeFluxo(vector<int> quadro)
{
    //algum codigo aqui
} //fim do metodo DadosReceptoraControleDeFluxo

void CamadaEnlace::DadosReceptoraControleDeErroBitDeParidadePar(vector<int> quadro)
{
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
} //fim do metodo DadosReceptoraControleDeErroBitDeParidadePar

void CamadaEnlace::DadosReceptoraControleDeErroBitDeParidadeImpar(vector<int> quadro)
{
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
} //fim do metodo DadosReceptoraControleDeErroBitDeParidadeImpar

void CamadaEnlace::DadosReceptoraControleDeErroCRC(vector<int> quadro)
{
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
    //usar polinomio CRC-32(IEEE 802)
} //fim do metodo DadosReceptoraControleDeErroCRC

void CamadaEnlace::DadosReceptoraControleDeErroCodigoDeHamming(vector<int> quadro)
{
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
} //fim do metodo DadosReceptoraControleDeErroCodigoDeHamming

/*##########################################################################################################*/
// MEIO DE COMUNICAÇÃO

void CamadaEnlace::MeioDeComunicacao(vector<int> fluxoBrutoDeBits)
{
    //OBS: trabalhar com BITS e nao com BYTES!!!
    int erro, porcentagemDeErros;
    vector<int> fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;
    porcentagemDeErros = 0; //10%, 20%, 30%, 40%, ..., 100%
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    // while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA)
    // {
    //     if ((rand() % 100) == ...)                        //fazer a probabilidade do erro
    //         fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; //BITS!!!
    //     else                                              //ERRO! INVERTER (usa condicao ternaria)
    //         (fluxoBrutoBitsPontoB == 0) ? fluxoBrutoBitsPontoA = fluxoBrutoBitsPontoB++ : fluxoBrutoBitsPontoA = fluxoBrutoBitsPontoB--;
    // } //fim do while
} //fim do metodo MeioDeTransmissao