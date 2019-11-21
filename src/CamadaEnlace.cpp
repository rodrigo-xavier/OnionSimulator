#include "../lib/CamadaEnlace.hpp"

/*##########################################################################################################*/
// TRANSMISSORA

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Tratamento de Dados
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada:  Realiza o enquadramento e o controle de erros do quadro recebido.
*********************************************************************************************/
void CamadaEnlace::DadosTransmissora(vector<int> quadro_bruto)
{
    DadosTransmissoraEnquadramento(quadro_bruto);
    DadosTransmissoraControleDeErro(quadro_bruto);
    //chama proxima camada
    // CamadaFisicaTransmissora(quadro_bruto);
}

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Enquadramento
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada:  Realiza o enquadramento escolhido.
*********************************************************************************************/
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

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Enquadramento por Contagem de Caracteres
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada:  Realiza o enquadramento por contagem de caracteres do quadro recebido
                        como parâmtero e armazena no quadro tratado (vetor de inteiros).
*********************************************************************************************/
void CamadaEnlace::DadosTransmissoraEnquadramentoContagemDeCaracteres(vector<int> quadro_bruto)
{
    cout << "Realizando enquadramento com contagem de caracteres" << endl;

    int qtd_bytes = ceil(quadro.size() / 8);
    vector<int> enquadramento_contagem_caracteres;

    enquadramento_contagem_caracteres.push_back(qtd_bytes);

    for (int i = 0; i < quadro.size(); i++)
        enquadramento_contagem_caracteres.push_back(quadro[i]);

    for (int i = 0; i < enquadramento_contagem_caracteres.size(); i++)
        cout << enquadramento_contagem_caracteres[i];

    cout << endl;

    this->quadro = enquadramento_contagem_caracteres;
}

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Enquadramento por Inserção de Bytes
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada:  Realiza o enquadramento por inserção de bytes do quadro recebido
                        como parâmtero e armazena no quadro tratado (vetor de inteiros).
*********************************************************************************************/
void CamadaEnlace::DadosTransmissoraEnquadramentoInsercaoDeBytes(vector<int> quadro_bruto)
{
    cout << "Realizando enquadramento com inserção de bytes" << endl;

    string byte_str = "", quadro_str = this->flag;
    vector<int> novo_quadro;
    int counter = 1;

    for (int i = 0; i < quadro_bruto.size(); i++)
    {
        byte_str += to_string(quadro_bruto[i]);

        if (counter == (BYTE))
        {
            if ((byte_str == this->flag) || (byte_str == this->esc))
                quadro_str += this->esc;

            quadro_str += byte_str;

            counter = 0;
            byte_str = "";
        }
        counter++;
    }

    quadro_str += this->flag;

    for (auto &i : quadro_str)
        novo_quadro.push_back(i - '0');

    this->quadro = novo_quadro;

    // this->quadro = TransmissoraCodificacaoBinaria(novo_quadro);
}

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Enquadramento por Inserção de Bits
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada:  Realiza o enquadramento por inserção de bits do quadro recebido
                        como parâmtero e armazena no quadro tratado (vetor de inteiros).
*********************************************************************************************/
void CamadaEnlace::DadosTransmissoraEnquadramentoInsercaoDeBits(vector<int> quadro_bruto)
{
    cout << "Realizando enquadramento com inserção de bits" << endl;

    int seq_cinco_bits_um = 0;
    vector<int> enquadramento_insercao_bits;

    cout << "Bits original: ";
    for (int i = 0; i < quadro.size(); i++)
        cout << quadro[i];
    cout << endl;

    for (int i = 0; i < this->flag_bit.length(); i++)
        enquadramento_insercao_bits.push_back(this->flag_bit[i] - '0');

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

    for (int i = 0; i < this->flag_bit.length(); i++)
        enquadramento_insercao_bits.push_back(this->flag_bit[i] - '0');

    cout << "Enquadramento insercao de bits: ";
    for (int i = 0; i < enquadramento_insercao_bits.size(); i++)
        cout << enquadramento_insercao_bits[i];

    cout << endl;

    this->quadro = enquadramento_insercao_bits;

    DadosReceptoraEnquadramentoInsercaoDeBits(enquadramento_insercao_bits);
}

/*##########################################################################################################*/
// TRANSMISSORA: CONTROLE

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Controle de Erro
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada:  Realiza o controle de erro pelo método escolhido.
*********************************************************************************************/
void CamadaEnlace::DadosTransmissoraControleDeErro(vector<int> quadro_bruto)
{
    int tipoDeControleDeErro = 0; //alterar de acordo com o teste
    switch (tipoDeControleDeErro)
    {
    case 0: //bit de paridade par
        DadosTransmissoraControleDeErroBitParidadePar(quadro_bruto);
        break;
    case 1: //bit de paridade impar
        DadosTransmissoraControleDeErroBitParidadePar(quadro_bruto);
        break;
    case 2: //CRC
        DadosTransmissoraControleDeErroCRC(quadro_bruto);
        break;
    case 3: //codigo de Hamming
        DadosTransmissoraControleDeErroCodigoDeHamming(quadro_bruto);
        break;
    } //fim do switch/case
}

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Controle de Erro por Bit de Paridade Par
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada:  Insere os elementos do quadro bruto no vetor de controle, muda o status
                        da paridade (tendo ela começado como verdadeira) se o elemento analisado for 1,
                        insere a paridade final no final do vetor de controle, e imprime cada elemento
                        do vetor de controle. Ao término, define o quadro como o vetor de controle.
*********************************************************************************************/
void CamadaEnlace::DadosTransmissoraControleDeErroBitParidadePar(vector<int> quadro_bruto)
{
    cout << "Controle de Paridade Par" << endl;

    vector<int> controle_paridade_par;
    bool paridade = true;

    for (int i = 0; i < quadro_bruto.size(); i++)
        controle_paridade_par.push_back(quadro_bruto.at(i));

    for (int i = 0; i < quadro_bruto.size(); i++)
        if (quadro_bruto.at(i) == 1)
            paridade = !paridade;

    controle_paridade_par.push_back(paridade);

    for (int i = 0; i < controle_paridade_par.size(); i++)
        cout << controle_paridade_par.at(i);
    cout << endl;

    this->quadro = controle_paridade_par;
}

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Controle de Erro por Bit de Paridade Ímpar
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada:  Insere os elementos do quadro bruto no vetor de controle, muda o status
                        da paridade (tendo ela começado como falsa) se o elemento analisado for 1,
                        insere a paridade final no final do vetor de controle, e imprime cada elemento
                        do vetor de controle. Ao término, define o quadro como o vetor de controle.
*********************************************************************************************/
void CamadaEnlace::DadosTransmissoraControleDeErroBitParidadeImpar(vector<int> quadro_bruto)
{
    cout << "Controle de Paridade Ímpar" << endl;

    vector<int> controle_paridade_impar;
    bool paridade = false;

    for (int i = 0; i < quadro_bruto.size(); i++)
        controle_paridade_impar.push_back(quadro_bruto.at(i));

    for (int i = 0; i < quadro_bruto.size(); i++)
        if (quadro_bruto.at(i) == 1)
            paridade = !paridade;

    controle_paridade_impar.push_back(paridade);

    for (int i = 0; i < controle_paridade_impar.size(); i++)
        cout << controle_paridade_impar.at(i);
    cout << endl;

    this->quadro = controle_paridade_impar;
}

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Controle de Erro por CRC
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada:  Verifica se o quadro possui o tamanho correto para o controle de erro
                        por CRC 32 bits, insere a mesma quantidade de caracteres do CRC em
                        zeros no novo quadro, realiza a operação de ou-exclusivo descrita
                        abaixo se o item atual do vetor for 1, e, por fim, armazena o novo
                        quadro no lugar do quadro antigo no vetor de inteiros.
*********************************************************************************************/
void CamadaEnlace::DadosTransmissoraControleDeErroCRC(vector<int> quadro_bruto)
{
    cout << "Realizando a transmissão com controle de erro CRC" << endl;

    vector<int> novo_quadro = quadro_bruto;

    if (quadro_bruto.size() <= this->polinomio_crc_32.length())
    {
        cout << "Erro, o quadro possui menos bits que o polinômio";
        return;
    }

    for (int i = 0; i < this->polinomio_crc_32.length(); i++)
        novo_quadro.push_back(0);

    for (int i = 0; i < quadro_bruto.size(); i++)
    {
        if (novo_quadro[i] == 1)
        {
            for (int j = 0; j < this->polinomio_crc_32.length(); j++)
                novo_quadro[i + j] ^= (this->polinomio_crc_32[j] - '0');
                // XOR entre o elemento i+j do novo quadro e o polinômio CRC 32bits; Armazena no próprio elemento i+j do novo quadro
        }
    }

    for (int i = 0; i < quadro_bruto.size(); i++)
        novo_quadro[i] = quadro_bruto[i];

    this->quadro = novo_quadro;
}

/********************************************************************************************  
  Descrição Breve: Método da Camada de Enlace de Controle de Erro por Código de Hamming
  
  Descrição da Entrada:
  (quadro_bruto) - Unidade de dados da camada de enlace

  Descrição da saída:
  (void)

  Descrição Detalhada: 
*********************************************************************************************/
void CamadaEnlace::DadosTransmissoraControleDeErroCodigoDeHamming(vector<int> quadro_bruto)
{
    cout << "Realizando o controle de erro utilizando código de Hamming" << endl;

    int bit_redundancia = 0;
    vector<int> codigo_hamming;
    vector<int> bits_paridade;
    while (quadro_bruto.size() + bit_redundancia + 1 > pow(2, bit_redundancia))
    {
        bit_redundancia++;
    }
    cout << "Bit de redundância: " << bit_redundancia << endl;
    int tamanho_hamming = bit_redundancia + quadro_bruto.size();
    cout << "Qtd final de bits: " << tamanho_hamming << endl;
    int posicao_paridade = 0;
    int posicao_dado = 0;

    for (int i = 1; i <= tamanho_hamming; i++)
    {
        if (i == pow(2, posicao_paridade))
        {
            codigo_hamming.push_back(0);
            posicao_paridade++;
        }
        else
        {
            codigo_hamming.push_back(quadro_bruto.at(posicao_dado));
            posicao_dado++;
        }
    }

    int posicao_analise;
    int xor_analise;
    bool primeiro_elemento;

    for (int i = 0; i < bit_redundancia; i++)
    {
        primeiro_elemento = true;
        xor_analise = 0;
        posicao_analise = pow(2, i) - 1;
        while (posicao_analise < codigo_hamming.size())
        {
            if (primeiro_elemento == true)
            {
                xor_analise = codigo_hamming[posicao_analise + 1];
                primeiro_elemento = false;
            }
            else
            {
                xor_analise ^= codigo_hamming[posicao_analise];
                xor_analise ^= codigo_hamming[posicao_analise + 1];
            }
            posicao_analise += 1;
            posicao_analise += pow(2, i) - 1 + 1;
        }
        bits_paridade.push_back(xor_analise);
    }

    cout << "bits de paridade: ";
    for (int i = 0; i < bits_paridade.size(); i++)
        cout << bits_paridade.at(i);
    cout << endl;

    int pos = 0;
    posicao_paridade = 0;

    for (int i = 1; i <= codigo_hamming.size(); i++)
    {
        if (i == pow(2, posicao_paridade))
        {
            codigo_hamming[i - 1] = bits_paridade.at(bit_redundancia - 1 - pos);
            pos++;
            posicao_paridade++;
        }
    }

    cout << "codigo_hamming: ";
    for (int i = 0; i < codigo_hamming.size(); i++)
        cout << codigo_hamming.at(i);
    cout << endl;

    this->quadro = codigo_hamming;
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
    cout << "Realizando o enquadramento com contagem de caracteres" << endl;

    int qtd_bytes = quadro.front();
    vector<int> desenquadramento_contagem_caracteres;

    for (int i = 1; i < quadro.size(); i++)
        desenquadramento_contagem_caracteres.push_back(quadro[i]);

    for (int i = 0; i < desenquadramento_contagem_caracteres.size(); i++)
        cout << desenquadramento_contagem_caracteres[i];

    cout << endl;

    this->quadro = desenquadramento_contagem_caracteres;
}

void CamadaEnlace::DadosReceptoraEnquadramentoInsercaoDeBytes(vector<int> quadro_bruto)
{
    cout << "Realizando a decodificação do enquadramento com inserção de bytes" << endl;

    string byte_str = "", quadro_str = "";
    vector<int> novo_quadro;
    int counter = 1;
    bool ignore = false;

    for (int i = 0; i < quadro_bruto.size(); i++)
    {
        byte_str += to_string(quadro_bruto[i]);

        if (counter == BYTE)
        {
            if (((byte_str == this->flag) || (byte_str == this->esc)) && !ignore)
                ignore = true;
            else
            {
                quadro_str += byte_str;
                ignore = false;
            }

            counter = 0;
            byte_str = "";
        }
        counter++;
    }

    for (auto &i : quadro_str)
        novo_quadro.push_back(i - '0');

    this->quadro = novo_quadro;
}

void CamadaEnlace::DadosReceptoraEnquadramentoInsercaoDeBits(vector<int> quadro_bruto)
{
    cout << "Realizando desenquadramento com inserção de bits" << endl;

    int seq_cinco_bits_um = 0;
    vector<int> desenquadramento_insercao_bits;

    for (int i = 8; i < quadro.size() - 1; i++)
    {
        if (seq_cinco_bits_um < 5)
        {
            if (quadro[i] == 0)
                seq_cinco_bits_um = 0;
            else
                seq_cinco_bits_um = seq_cinco_bits_um + 1;

            desenquadramento_insercao_bits.push_back(quadro[i]);
        }
        else
        {
            if (quadro[i] == 0)
                seq_cinco_bits_um = 0;
            else
                for (int i = 0; i < 6; i++)
                    desenquadramento_insercao_bits.pop_back();
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

void CamadaEnlace::DadosReceptoraControleDeErro(vector<int> quadro_bruto)
{
    int tipoDeControleDeErro = 0; //alterar de acordo com o teste
    switch (tipoDeControleDeErro)
    {
    case 0: //bit de paridade par
        DadosReceptoraControleDeErroBitDeParidadePar(quadro_bruto);
        break;
    case 1: //bit de paridade impar
        DadosReceptoraControleDeErroBitDeParidadeImpar(quadro_bruto);
        break;
    case 2: //CRC
        DadosReceptoraControleDeErroCRC(quadro_bruto);
    case 3: //codigo de hamming
        DadosReceptoraControleDeErroCodigoDeHamming(quadro_bruto);
        break;
    } //fim do switch/case
}

void CamadaEnlace::DadosReceptoraControleDeErroBitDeParidadePar(vector<int> quadro_bruto)
{
    cout << "Recebimento do controle de Paridade Par" << endl;

    vector<int> recebimento_paridade_par;
    bool paridade = true;

    for (int i = 0; i < quadro_bruto.size() - 1; i++)
        recebimento_paridade_par.push_back(quadro_bruto.at(i));

    for (int i = 0; i < recebimento_paridade_par.size(); i++)
        if (recebimento_paridade_par.at(i) == 1)
            paridade = !paridade;

    if (quadro_bruto.back() == paridade)
        cout << "Recebeu com sucesso" << endl;

    for (int i = 0; i < recebimento_paridade_par.size(); i++)
        cout << recebimento_paridade_par.at(i);
    cout << endl;

    this->quadro = recebimento_paridade_par;
}

void CamadaEnlace::DadosReceptoraControleDeErroBitDeParidadeImpar(vector<int> quadro_bruto)
{
    cout << "Recebimento do controle de Paridade Ímpar" << endl;

    vector<int> recebimento_paridade_impar;
    bool paridade = false;

    for (int i = 0; i < quadro_bruto.size() - 1; i++)
    {
        recebimento_paridade_impar.push_back(quadro_bruto.at(i));
    }

    for (int i = 0; i < recebimento_paridade_impar.size(); i++)
    {
        if (recebimento_paridade_impar.at(i) == 1)
        {
            paridade = !paridade;
        }
    }

    if (quadro_bruto.back() == paridade)
    {
        cout << "Recebeu com sucesso" << endl;
    }

    for (int i = 0; i < recebimento_paridade_impar.size(); i++)
    {
        cout << recebimento_paridade_impar.at(i);
    }
    cout << endl;

    this->quadro = recebimento_paridade_impar;
}

void CamadaEnlace::DadosReceptoraControleDeErroCRC(vector<int> quadro_bruto)
{
    cout << "Realizando o controle de erro CRC receptor" << endl;

    vector<int> mensagem, novo_quadro;
    bool valido = true;

    if (quadro_bruto.size() <= this->polinomio_crc_32.length())
    {
        cout << "Erro, o quadro possui menos bits que o polinômio";
        return;
    }

    novo_quadro = quadro_bruto;
    mensagem = quadro_bruto;
    mensagem.erase(mensagem.end() - 31, mensagem.end());

    for (int i = 0; i < mensagem.size(); i++)
    {
        if (quadro_bruto[i] == 1)
        {
            for (int j = 0; j < this->polinomio_crc_32.length(); j++)
                novo_quadro[j + i] = novo_quadro[j + i] == polinomio_crc_32[j] ? 0 : 1;
        }
    }

    for (int i = 0; i < mensagem.size(); i++)
    {
        if (novo_quadro[i] != 0)
            valido = false;
    }

    if (valido)
        this->quadro = mensagem;
}

void CamadaEnlace::DadosReceptoraControleDeErroCodigoDeHamming(vector<int> quadro_bruto)
{
    cout << "Realizando a Decodificação do código de hamming" << endl;

    vector<int> decodificacao_hamming;
    int posicao_paridade = 0;

    cout << "Decodicação de Hamming: ";
    for (int i = 0; i < quadro_bruto.size(); i++)
        cout << quadro_bruto.at(i);
    cout << endl;

    for (int i = 1; i <= quadro_bruto.size(); i++)
    {
        if (i == pow(2, posicao_paridade))
        {
            posicao_paridade++;
        }
        else
        {
            decodificacao_hamming.push_back(quadro_bruto.at(i - 1));
        }
    }

    cout << "Decodicação de Hamming: ";
    for (int i = 0; i < decodificacao_hamming.size(); i++)
        cout << decodificacao_hamming.at(i);
    cout << endl;
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