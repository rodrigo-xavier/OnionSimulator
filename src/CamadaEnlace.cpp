#include "../lib/CamadaEnlace.hpp"

/*##########################################################################################################*/
// TRANSMISSORA

void CamadaEnlace::DadosTransmissora(vector<int> quadro)
{
    DadosTransmissoraEnquadramento(quadro);
    DadosTransmissoraControleDeErro(quadro);
    //chama proxima camada
    // CamadaFisicaTransmissora(quadro);
}

/*##########################################################################################################*/
// TRANSMISSORA: ENQUADRAMENTO

void CamadaEnlace::DadosTransmissoraEnquadramento(vector<int> quadro)
{
    int tipoDeEnquadramento = 0; //alterar de acordo com o teste
    vector<int> quadroEnquadrado;
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
}

void CamadaEnlace::DadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro)
{
    cout << "Realizando enquadramento com contagem de caracteres" << endl;
    //implementacao do algoritmo
    int qtd_bytes = ceil(quadro.size() / 8);
    vector<int> enquadramento_contagem_caracteres;

    enquadramento_contagem_caracteres.push_back(qtd_bytes);

    for (int i = 0; i < quadro.size(); i++)
        enquadramento_contagem_caracteres.push_back(quadro[i]);

    for (int i = 0; i < enquadramento_contagem_caracteres.size(); i++)
        cout << enquadramento_contagem_caracteres[i];

    cout << endl;

    this->quadro = enquadramento_contagem_caracteres;

} //fim do metodo DadosTransmissoraContagemDeCaracteres

void CamadaEnlace::DadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro)
{
    // cout << "Realizando enquadramento com inserção de bytes" << endl;

    // string compare;

    // for (int i = 0; i < quadro.size(); i++)
    // {
    //     for (int j = 0; j < BYTE; j++)
    //     {
    //         compare = quadro
    //     }
    // }
}

void CamadaEnlace::DadosTransmissoraEnquadramentoInsercaoDeBits(vector<int> quadro)
{
    cout << "Realizando enquadramento com inserção de bits" << endl;
    //implementacao do algoritmo
    int seq_cinco_bits_um = 0;
    vector<int> enquadramento_insercao_bits;

    cout << "Bits original: ";
    for (int i = 0; i < quadro.size(); i++)
        cout << quadro[i];
    cout << endl;

    enquadramento_insercao_bits.push_back(0);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(0);

    for (int i = 0; i < quadro.size(); i++)
    {
        if (seq_cinco_bits_um < 5)
        {
            if (quadro[i] == 0)
            {
                seq_cinco_bits_um = 0;
            }
            else
            {
                seq_cinco_bits_um = seq_cinco_bits_um + 1;
            }
            enquadramento_insercao_bits.push_back(quadro[i]);
        }
        else
        {
            enquadramento_insercao_bits.push_back(0);
            enquadramento_insercao_bits.push_back(quadro[i]);
            seq_cinco_bits_um = 0;
        }
    }

    enquadramento_insercao_bits.push_back(0);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(1);
    enquadramento_insercao_bits.push_back(0);

    cout << "Enquadramento insercao de bits: ";
    for (int i = 0; i < enquadramento_insercao_bits.size(); i++)
        cout << enquadramento_insercao_bits[i];

    cout << endl;

    this->quadro = enquadramento_insercao_bits;

    DadosReceptoraEnquadramentoInsercaoDeBits(enquadramento_insercao_bits);
}

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
}

void CamadaEnlace::DadosTransmissoraControleDeErroBitParidadePar(vector<int> quadro)
{
}

void CamadaEnlace::DadosTransmissoraControleDeErroBitParidadeImpar(vector<int> quadro)
{
}

void CamadaEnlace::DadosTransmissoraControleDeErroCRC(vector<int> quadro)
{

    //usar polinomio CRC-32(IEEE 802)
}

void CamadaEnlace::DadosTransmissoraControleDeErroCodigoDeHamming(vector<int> quadro)
{
}

/*##########################################################################################################*/
// RECEPTORA

void CamadaEnlace::DadosReceptora(vector<int> quadro)
{
    DadosTransmissoraEnquadramento(quadro);
    DadosTransmissoraControleDeErro(quadro);
    //chama proxima camada
    // CamadaDeAplicacaoReceptora(quadro);
}

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
}

void CamadaEnlace::DadosReceptoraEnquadramentoContagemDeCaracteres(vector<int> quadro)
{
    //implementacao do algoritmo para DESENQUADRAR
    int qtd_bytes = quadro.front();
    vector<int> desenquadramento_contagem_caracteres;

    for (int i = 1; i < quadro.size(); i++)
        desenquadramento_contagem_caracteres.push_back(quadro[i]);

    for (int i = 0; i < desenquadramento_contagem_caracteres.size(); i++)
        cout << desenquadramento_contagem_caracteres[i];

    cout << endl;

    this->quadro = desenquadramento_contagem_caracteres;

} //fim do metodo DadosReceptoraContagemDeCaracteres

void CamadaEnlace::DadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro)
{
}

void CamadaEnlace::DadosReceptoraEnquadramentoInsercaoDeBits(vector<int> quadro)
{
    cout << "Realizando desenquadramento com inserção de bits" << endl;
    //implementacao do algoritmo
    int seq_cinco_bits_um = 0;
    vector<int> desenquadramento_insercao_bits;

    for (int i = 8; i < quadro.size() - 1; i++)
    {
        if (seq_cinco_bits_um < 5)
        {
            if (quadro[i] == 0)
            {
                seq_cinco_bits_um = 0;
            }
            else
            {
                seq_cinco_bits_um = seq_cinco_bits_um + 1;
            }
            desenquadramento_insercao_bits.push_back(quadro[i]);
        }
        else
        {
            if (quadro[i] == 0)
            {
                seq_cinco_bits_um = 0;
            }
            else
            {
                for (int i = 0; i < 6; i++)
                {
                    desenquadramento_insercao_bits.pop_back();
                }
            }
        }
    }

    cout << "Desenquadramento insercao de bits: ";
    for (int i = 0; i < desenquadramento_insercao_bits.size(); i++)
        cout << desenquadramento_insercao_bits[i];

    cout << endl;

    this->quadro = desenquadramento_insercao_bits;
}

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
}

void CamadaEnlace::DadosReceptoraControleDeErroBitDeParidadePar(vector<int> quadro)
{
}

void CamadaEnlace::DadosReceptoraControleDeErroBitDeParidadeImpar(vector<int> quadro)
{
}

void CamadaEnlace::DadosReceptoraControleDeErroCRC(vector<int> quadro)
{

    //usar polinomio CRC-32(IEEE 802)
}

void CamadaEnlace::DadosReceptoraControleDeErroCodigoDeHamming(vector<int> quadro)
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