void CamadaEnlaceDadosTransmissora(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosTransmissora
void CamadaEnlaceDadosTransmissoraEnquadramento(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosTransmissoraEnquadramentos
void CamadaEnlaceDadosTransmissoraControleDeErro(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosTransmissoraControleDeErro
void CamadaEnlaceDadosTransmissoraControleDeFluxo(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosTransmissoraControleDeFluxo

void CamadaEnlaceDadosTransmissora(int quadro[])
{
    CamadaDeEnlaceTransmissoraEnquadramento(quadro);
    CamadaDeEnlaceTransmissoraControleDeErro(quadro);
    CamadaDeEnlaceTransmissoraControleDeFluxo(quadro);
    //chama proxima camada
    CamadaFisicaTransmissora(quadro);
} //fim do metodo CamadaEnlaceDadosTransmissora

void CamadaEnlaceDadosTransmissoraEnquadramento(int quadro[])
{
    int tipoDeEnquadramento = 0; //alterar de acordo com o teste
    int quadroEnquadrado[];
    switch (tipoDeEnquadramento)
    {
    case 0: //contagem de caracteres
        quadroEnquadrado = CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro);
        break;
    case 1: //insercao de bytes
        quadroEnquadrado = CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro);
        break;
    case 2: //insercao de bits
        quadroEnquadrado = CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro);
    case 3: //violacao da camada fisica
        quadroEnquadrado = CamadaDeEnlaceTransmissoraEnquadramentoViolacaoCamadaFisica(quadro);
        break;
    } //fim do switch/case
} //fim do metodo CamadaEnlaceTransmissoraEnquadramento

void CamadaEnlaceDadosTransmissoraEnquadramentoContagemDeCaracteres(int quadro[])
{
    //implementacao do algoritmo
} //fim do metodo CamadaEnlaceDadosTransmissoraContagemDeCaracteres
void CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBytes(int quadro[])
{
    //implementacao do algoritmo
} //fim do metodo CamadaEnlaceDadosTransmissoraInsercaoDeBytes
void CamadaEnlaceDadosTransmissoraEnquadramentoInsercaoDeBits(int quadro[])
{
    //implementacao do algoritmo
} //fim do metodo CamadaEnlaceDadosTransmissoraInsercaoDeBits
void CamadaEnlaceDadosTransmissoraEnquadramentoViolacaoDaCamadaFisica(int quadro[])
{
    //implementacao do algoritmo
} //fim do metodo CamadaEnlaceDadosTransmissoraViolacaoDaCamadaFisica

void CamadaEnlaceDadosReceptora(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosReceptora
void CamadaEnlaceDadosReceptoraEnquadramento(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosReceptoraEnquadramento
void CamadaEnlaceDadosReceptoraControleDeErro(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosReceptoraControleDeErro
void CCamadaEnlaceDadosReceptoraControleDeFluxo(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosReceptoraControleDeFluxo

void CamadaEnlaceDadosReceptora(int quadro[])
{
    CamadaDeEnlaceTransmissoraEnquadramento(quadro);
    CamadaDeEnlaceTransmissoraControleDeErro(quadro);
    CamadaDeEnlaceTransmissoraControleDeFluxo(quadro);
    //chama proxima camada
    CamadaDeAplicacaoReceptora(quadro);
} //fim do metodo CamadaEnlaceDadosReceptora

void CamadaEnlaceDadosReceptoraEnquadramento(int quadro[])
{
    int tipoDeEnquadramento = 0; //alterar de acordo com o teste
    int quadroDesenquadrado[];
    switch (tipoDeEnquadramento)
    {
    case 0: //contagem de caracteres
        quadroDesenquadrado = CamadaDeEnlaceTransmissoraEnquadramentoContagemDeCaracteres(quadro);
        break;
    case 1: //insercao de bytes
        quadroDesenquadrado = CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBytes(quadro);
        break;
    case 2: //insercao de bits
        quadroDesenquadrado = CamadaDeEnlaceTransmissoraEnquadramentoInsercaoDeBits(quadro);
    case 3: //violacao da camada fisica
        quadroDesenquadrado = CamadaDeEnlaceTransmissoraEnquadramentoViolacaoCamadaFisica(quadro);
        break;
    } //fim do switch/case
} //fim do metodo CamadaEnlaceDadosReceptoraEnquadramento

void CamadaEnlaceDadosReceptoraEnquadramentoContagemDeCaracteres(int quadro[])
{
    //implementacao do algoritmo para DESENQUADRAR
} //fim do metodo CamadaEnlaceDadosReceptoraContagemDeCaracteres
void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBytes(int quadro[])
{
    //implementacao do algoritmo para DESENQUADRAR
} //fim do metodo CamadaEnlaceDadosReceptoraInsercaoDeBytes
void CamadaEnlaceDadosReceptoraEnquadramentoInsercaoDeBits(int quadro[])
{
    //implementacao do algoritmo para DESENQUADRAR
} //fim do metodo CamadaEnlaceDadosReceptoraInsercaoDeBits
void CamadaEnlaceDadosReceptoraEnquadramentoViolacaoDaCamadaFisica(int quadro[])
{
    //implementacao do algoritmo para DESENQUADRAR
} //fim do metodo CamadaEnlaceDadosReceptoraViolacaoDaCamadaFisica

void CamadaEnlaceDadosTransmissora(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosTransmissora
void CamadaEnlaceDadosTransmissoraEnquadramento(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosTransmissoraEnquadramentos
void CamadaEnlaceDadosTransmissoraControleDeErro(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosTransmissoraControleDeErro
void CamadaEnlaceDadosTransmissoraControleDeFluxo(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosTransmissoraControleDeFluxo

void CamadaEnlaceDadosTransmissora(int quadro[])
{
    CamadaEnlaceDadosTransmissoraEnquadramento(quadro);
    CamadaEnlaceDadosTransmissoraControleDeErro(quadro);
    CamadaEnlaceDadosTransmissoraControleDeFluxo(quadro);
    //chama proxima camada
    CamadaFisicaTransmissora(quadro);
} //fim do metodo CamadaEnlaceDadosTransmissora

void CamadaEnlaceDadosTransmissoraControleDeErro(int quadro[])
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
} //fim do metodo CamadaEnlaceDadosTransmissoraControleDeErro

void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(int quadro[])
{
    //implementacao do algoritmo
} //fim do metodo CamadaEnlaceDadosTransmissoraControledeErroBitParidadePar
void CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(int quadro[])
{
    //implementacao do algoritmo
} //fim do metodo CamadaEnlaceDadosTransmissoraControledeErroBitParidadeImpar
void CamadaEnlaceDadosTransmissoraControleDeErroCRC(int quadro[])
{
    //implementacao do algoritmo
    //usar polinomio CRC-32(IEEE 802)
} //fim do metodo CamadaEnlaceDadosTransmissoraControledeErroCRC
void CamadaEnlaceDadosTransmissoraControleDeErroCodigoDeHamming(int quadro[])
{
    //implementacao do algoritmo
} //fim do metodo CamadaEnlaceDadosTransmissoraControleDeErroCodigoDehamming

void MeioDeComunicacao(int fluxoBrutoDeBits[])
{
    //OBS: trabalhar com BITS e nao com BYTES!!!
    int erro, porcentagemDeErros;
    int fluxoBrutoDeBitsPontoA[], fluxoBrutoDeBitsPontoB[];
    porcentagemDeErros = 0; //10%, 20%, 30%, 40%, ..., 100%
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    while (fluxoBrutoDeBitsPontoB.lenght != fluxoBrutoDeBitsPontoA)
    {
        if ((rand() % 100) == ...)                        //fazer a probabilidade do erro
            fluxoBrutoBitsPontoB += fluxoBrutoBitsPontoA; //BITS!!!
        else                                              //ERRO! INVERTER (usa condicao ternaria)
            (fluxoBrutoBitsPontoB == 0) ? fluxoBrutoBitsPontoA = fluxoBrutoBitsPontoB++ : fluxoBrutoBitsPontoA = fluxoBrutoBitsPontoB--;
    } //fim do while
} //fim do metodo MeioDeTransmissao

void CamadaEnlaceDadosReceptora(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceReceptora
void CamadaEnlaceDadosReceptoraEnquadramento(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosReceptoraEnquadramento
void CamadaEnlaceDadosReceptoraControleDeErro(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosReceptoraControleDeErro
void CamadaEnlaceDadosReceptoraControleDeFluxo(int quadro[])
{
    //algum codigo aqui
} //fim do metodo CamadaEnlaceDadosReceptoraControleDeFluxo

void CamadaEnlaceDadosReceptora(int quadro[])
{
    CamadaDeEnlaceTransmissoraEnquadramento(quadro);
    CamadaDeEnlaceTransmissoraControleDeErro(quadro);
    CamadaDeEnlaceTransmissoraControleDeFluxo(quadro);
    //chama proxima camada
    CamadaDeAplicacaoReceptora(quadro);
} //fim do metodo CamadaEnlaceDadosReceptora

void CamadaEnlaceDadosReceptoraControleDeErro(int quadro[])
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
} //fim do metodo CamadaEnlaceDadosReceptoraControleDeErro

void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar(int quadro[])
{
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
} //fim do metodo CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadePar
void CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar(int quadro[])
{
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
} //fim do metodo CamadaEnlaceDadosReceptoraControleDeErroBitDeParidadeImpar
void CamadaEnlaceDadosReceptoraControleDeErroCRC(int quadro[])
{
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
    //usar polinomio CRC-32(IEEE 802)
} //fim do metodo CamadaEnlaceDadosReceptoraControleDeErroCRC
void CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming(int quadro[])
{
    //implementacao do algoritmo para VERIFICAR SE HOUVE ERRO
} //fim do metodo CamadaEnlaceDadosReceptoraControleDeErroCodigoDeHamming