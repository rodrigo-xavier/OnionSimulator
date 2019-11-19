#include "../lib/CamadaEnlace.hpp"

/*##########################################################################################################*/
// TRANSMISSORA

void CamadaEnlace::DadosTransmissora(vector<int> quadro_bruto)
{
    DadosTransmissoraEnquadramento(quadro_bruto);
    DadosTransmissoraControleDeErro(quadro_bruto);
    //chama proxima camada
    // CamadaFisicaTransmissora(quadro_bruto);
}

/*##########################################################################################################*/
// TRANSMISSORA: ENQUADRAMENTO

void CamadaEnlace::DadosTransmissoraEnquadramento(vector<int> quadro_bruto)
{
    int tipoDeEnquadramento = 0; //alterar de acordo com o teste
    vector<int> quadroEnquadrado;
    switch (tipoDeEnquadramento)
    {
    case 0: //contagem de caracteres
        DadosTransmissoraEnquadramentoContagemDeCaracteres(quadro_bruto);
        break;
    case 1: //insercao de bytes
        DadosTransmissoraEnquadramentoInsercaoDeBytes(quadro_bruto);
        break;
    case 2: //insercao de bits
        DadosTransmissoraEnquadramentoInsercaoDeBits(quadro_bruto);
    case 3: //violacao da camada fisica
        // DadosTransmissoraEnquadramentoViolacaoCamadaFisica(quadro_bruto);
        break;
    } //fim do switch/case
}

void CamadaEnlace::DadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro_bruto)
{
}

void CamadaEnlace::DadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro_bruto)
{
    cout << "Realizando enquadramento com inserção de bytes" << endl;

    string byte_str = "", quadro_str = this->flag;
    bitset<BYTE-1> bin_to_str;
    vector<int> novo_quadro;
    int counter = BYTE - 2;

    string showme="";
    for (int i = 0; i < quadro_bruto.size(); i++)
        showme+=quadro_bruto[i];
    cout << showme << endl;
    

    for (int i = 0; i < quadro_bruto.size(); i++)
    {
        bin_to_str[counter] = quadro_bruto[i];

        if (counter == 0)
        {
            byte_str = bin_to_str.to_string();
            cout << byte_str << endl;

            if (byte_str == this->flag)
                quadro_str += this->esc;
            if (byte_str == this->esc)
                quadro_str += this->esc;

            quadro_str += byte_str;

            counter = BYTE - 2;
            // bin_to_str.reset();
        }
        counter--;
    }

    quadro_str += this->flag;

    cout << quadro_str << endl;

    for(auto& i : quadro_str) novo_quadro.push_back(i - '0');

    this->quadro = novo_quadro;

    // this->quadro = TransmissoraCodificacaoBinaria(novo_quadro);
}

void CamadaEnlace::DadosTransmissoraEnquadramentoInsercaoDeBits(vector<int> quadro_bruto)
{
}

/*##########################################################################################################*/
// TRANSMISSORA: CONTROLE

void CamadaEnlace::DadosTransmissoraControleDeErro(vector<int> quadro_bruto)
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
}

void CamadaEnlace::DadosTransmissoraControleDeErroBitParidadePar(vector<int> quadro_bruto)
{
}

void CamadaEnlace::DadosTransmissoraControleDeErroBitParidadeImpar(vector<int> quadro_bruto)
{
}

void CamadaEnlace::DadosTransmissoraControleDeErroCRC(vector<int> quadro_bruto)
{

    //usar polinomio CRC-32(IEEE 802)
}

void CamadaEnlace::DadosTransmissoraControleDeErroCodigoDeHamming(vector<int> quadro_bruto)
{
}

/*##########################################################################################################*/
// RECEPTORA

void CamadaEnlace::DadosReceptora(vector<int> quadro_bruto)
{
    DadosTransmissoraEnquadramento(quadro_bruto);
    DadosTransmissoraControleDeErro(quadro_bruto);
    //chama proxima camada
    // CamadaDeAplicacaoReceptora(quadro_bruto);
}

/*##########################################################################################################*/
// RECEPTORA: ENQUADRAMENTO

void CamadaEnlace::DadosReceptoraEnquadramento(vector<int> quadro_bruto)
{
    int tipoDeEnquadramento = 0; //alterar de acordo com o teste
    vector<int> quadroDesenquadrado;
    switch (tipoDeEnquadramento)
    {
    case 0: //contagem de caracteres
        DadosTransmissoraEnquadramentoContagemDeCaracteres(quadro_bruto);
        break;
    case 1: //insercao de bytes
        DadosTransmissoraEnquadramentoInsercaoDeBytes(quadro_bruto);
        break;
    case 2: //insercao de bits
        DadosTransmissoraEnquadramentoInsercaoDeBits(quadro_bruto);
    case 3: //violacao da camada fisica
        // DadosTransmissoraEnquadramentoViolacaoCamadaFisica(quadro_bruto);
        break;
    } //fim do switch/case
}

void CamadaEnlace::DadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro_bruto)
{
}

void CamadaEnlace::DadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro_bruto)
{
}

void CamadaEnlace::DadosReceptoraEnquadramentoInsercaoDeBits(vector<int> quadro_bruto)
{
}

/*##########################################################################################################*/
// RECEPTORA: CONTROLE

void CamadaEnlace::DadosReceptoraControleDeErro(vector<int> quadro_bruto)
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
}

void CamadaEnlace::DadosReceptoraControleDeErroBitDeParidadePar(vector<int> quadro_bruto)
{
}

void CamadaEnlace::DadosReceptoraControleDeErroBitDeParidadeImpar(vector<int> quadro_bruto)
{
}

void CamadaEnlace::DadosReceptoraControleDeErroCRC(vector<int> quadro_bruto)
{

    //usar polinomio CRC-32(IEEE 802)
}

void CamadaEnlace::DadosReceptoraControleDeErroCodigoDeHamming(vector<int> quadro_bruto)
{
}

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
}