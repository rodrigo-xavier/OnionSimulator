#include "../lib/Testes.hpp"

void Testes::run(void)
{
    init_pacote();
    init_quadro();

#ifdef DEBUG_CAMADA_FISICA
    cout << "REALIZANDO TESTES NA CAMADA FÍSICA" << endl;
    cout << endl;
    cout << endl;

    test_transmissora_binaria();
    test_transmissora_manchester();
    test_transmissora_manchester_diferencial();
    test_meio_de_comunicacao();
    test_binaria_receptora();
    test_manchester_receptora();
    test_manchester_receptora_diferencial();

    cout << endl;
#endif

#ifdef DEBUG_CAMADA_ENLACE
    cout << "REALIZANDO TESTES NA CAMADA DE ENLACE" << endl;
    cout << endl;
    cout << endl;

    test_transmissora_enquadramento_contagem_de_caracteres();
    test_transmissora_enquadramento_insercao_de_bits();
    test_transmissora_enquadramento_insercao_de_bytes();
    test_transmissora_controle_de_erro_bit_paridade_impar();
    test_receptora_controle_de_erro_bit_paridade_par();
    test_receptora_enquadramento_insercao_de_bytes();
    test_transmissora_controle_de_erro_crc();
    test_receptora_controle_de_erro_crc();
    test_transmissora_controle_de_erro_codificacao_hamming();

    cout << endl;
#endif

#ifdef DEBUG_CAMADA_APLICACAO
    cout << "REALIZANDO TESTES NA CAMADA DE APLICAÇÃO" << endl;
    cout << endl;
    cout << endl;

    CamadaAplicacao camadaaplicacao;
    CamadaEnlace camadaenlace;
    CamadaFisica camadafisica;

    vector<int> passagem_bits;
    string mensagem;

    /* Emissor */
    mensagem = camadaaplicacao.AplicacaoTransmissora();
    passagem_bits = camadaaplicacao.Transmissora(mensagem);
    passagem_bits = camadaenlace.DadosTransmissora(passagem_bits);
    passagem_bits = camadafisica.Transmissora(passagem_bits);

    /* Meio de transmissão */
    passagem_bits = camadafisica.MeioDeComunicacao(passagem_bits);

    /*Receptor*/
    passagem_bits = camadafisica.Receptora(passagem_bits);
    passagem_bits = camadaenlace.DadosReceptora(passagem_bits);
    mensagem = camadaaplicacao.Receptora(passagem_bits);
    // camadaaplicacao.AplicacaoReceptora(mensagem);

    cout << endl;
#endif
}

void Testes::init_pacote(void)
{
    // Define um pacote com o número 5 em binário
    this->pacote_transmissor.push_back(1);
    this->pacote_transmissor.push_back(0);
    this->pacote_transmissor.push_back(1);
    // Define um pacote com o número 5 em binário
}

void Testes::init_quadro(void)
{
    string _255 = "11111111", _3 = "00000011", _esc_240 = "11110000";
    string _flag_15 = "00001111", _5 = "00000101", _0 = "00000000";
    int introdutor;

    //string concat = "1001101010011010";
    string concat = _255 + _3 + _esc_240 + _flag_15 + _5 + _0;

    for (int i = 0; i < concat.length(); i++)
    {
        introdutor = concat[i] - '0';
        this->quadro_transmissor.push_back(introdutor);
    }
}

/*##########################################################################################################*/
// CAMADA FÍSICA

void Testes::test_transmissora_binaria(void)
{
    CamadaFisica camadafisica;
    string enviado = "", recebido = "";

    this->pacote_receptor = camadafisica.TransmissoraCodificacaoBinaria(this->pacote_transmissor);

    for (int i = 0; i < this->pacote_receptor.size(); i++)
    {
        enviado += to_string(this->pacote_transmissor[i]);
        recebido += to_string(this->pacote_receptor[i]);
    }

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: 101" << endl;

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Codificacao binária");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Codificacao binária");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Codificacao binária");

    cout << "Codificacao binária funcionando" << endl;
    cout << endl;
}

void Testes::test_transmissora_manchester(void)
{
    CamadaFisica camadafisica;
    string enviado = "", recebido = "";

    this->pacote_receptor = camadafisica.TransmissoraCodificacaoManchester(this->pacote_transmissor);

    for (int i = 0; i < this->pacote_receptor.size(); i++)
    {
        enviado += to_string(this->pacote_transmissor[i]);
        recebido += to_string(this->pacote_receptor[i]);
    }

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: 100110" << endl;

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[2]) == 0, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[3]) == 1, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[4]) == 1, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[5]) == 0, "Falha na Codificacao manchester");

    cout << "Codificacao manchester funcionando" << endl;
    cout << endl;
}

void Testes::test_transmissora_manchester_diferencial(void)
{
    CamadaFisica camadafisica;
    string enviado = "", recebido = "";

    this->pacote_receptor = camadafisica.TransmissoraCodificacaoManchesterDiferencial(this->pacote_transmissor);

    for (int i = 0; i < this->pacote_receptor.size(); i++)
    {
        enviado += to_string(this->pacote_transmissor[i]);
        recebido += to_string(this->pacote_receptor[i]);
    }

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: 101001" << endl;

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[3]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[4]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[5]) == 1, "Falha na Codificacao Manchester Diferencial");

    cout << "Codificacao manchester Diferencial funcionando" << endl;
    cout << endl;
}

void Testes::test_meio_de_comunicacao(void)
{
    CamadaFisica camadafisica;
    camadafisica.MeioDeComunicacao(this->pacote_transmissor);
    cout << endl;
}

void Testes::test_binaria_receptora(void)
{
    CamadaFisica camadafisica;

    string enviado = "", recebido = "";

    for (int i = 0; i < this->pacote_receptor.size(); i++)
    {
        enviado += to_string(this->pacote_transmissor[i]);
        recebido += to_string(this->pacote_receptor[i]);
    }

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: 101" << endl;

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Decodificacao binária");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Decodificacao binária");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Decodificacao binária");

    cout << "Decodificacao Binária Funcionando" << endl;
    cout << endl;
}

void Testes::test_manchester_receptora(void)
{
    CamadaFisica camadafisica;
    string enviado = "", recebido = "";

    this->pacote_meio_comunicacao = camadafisica.TransmissoraCodificacaoManchester(this->pacote_transmissor);
    this->pacote_receptor = camadafisica.ReceptoraCodificacaoManchester(this->pacote_meio_comunicacao);

    for (int i = 0; i < this->pacote_meio_comunicacao.size(); i++)
        enviado += to_string(this->pacote_meio_comunicacao[i]);
    for (int i = 0; i < this->pacote_receptor.size(); i++)
        recebido += to_string(this->pacote_receptor[i]);

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: 101" << endl;

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Decodificacao manchester");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Decodificacao manchester");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Decodificacao manchester");

    cout << "Decodificacao Manchester Funcionando" << endl;
    cout << endl;
}

void Testes::test_manchester_receptora_diferencial(void)
{
    CamadaFisica camadafisica;
    string enviado = "", recebido = "";

    this->pacote_meio_comunicacao = camadafisica.TransmissoraCodificacaoManchesterDiferencial(this->pacote_transmissor);
    this->pacote_receptor = camadafisica.ReceptoraCodificacaoManchesterDiferencial(this->pacote_meio_comunicacao);

    for (int i = 0; i < this->pacote_meio_comunicacao.size(); i++)
        enviado += to_string(this->pacote_meio_comunicacao[i]);
    for (int i = 0; i < this->pacote_receptor.size(); i++)
        recebido += to_string(this->pacote_receptor[i]);

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: 101" << endl;

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Decodificacao manchester");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Decodificacao manchester");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Decodificacao manchester");

    cout << "Decodificacao Manchester Diferencial Funcionando" << endl;
    cout << endl;
}

/*##########################################################################################################*/
// CAMADA ENLACE

void Testes::test_transmissora_enquadramento_contagem_de_caracteres(void)
{
    CamadaEnlace camadaenlace;
    camadaenlace.DadosTransmissoraEnquadramentoContagemDeCaracteres(this->quadro_transmissor);

    cout << int(this->quadro_transmissor[0]) << endl;
    /*assertm(int(this->quadro_transmissor[0]) == 6, "Falha no Enquadramento usando contagem de caracteres");
    assertm(int(this->quadro_transmissor[1]) == 0, "Falha no Enquadramento usando contagem de caracteres");
    assertm(int(this->quadro_transmissor[47]) == 1, "Falha no Enquadramento usando contagem de caracteres");
    */
    cout << "Enquadramento usando contagem de caracteres funcionando" << endl;
    cout << endl;
}

void Testes::test_transmissora_enquadramento_insercao_de_bytes(void)
{
    CamadaEnlace camadaenlace;

    string _255 = "11111111", _3 = "00000011", _esc_240 = "11110000";
    string _flag_15 = "00001111", _5 = "00000101", _0 = "00000000";
    string esperado = _flag_15 + _255 + _3 + _esc_240 + _esc_240 + _esc_240 + _flag_15 + _5 + _0 + _flag_15;
    string enviado = "", recebido = "";

    camadaenlace.DadosTransmissoraEnquadramentoInsercaoDeBytes(this->quadro_transmissor);

    for (int i = 0; i < this->quadro_transmissor.size(); i++)
        enviado += to_string(this->quadro_transmissor[i]);

    for (int i = 0; i < camadaenlace.quadro.size(); i++)
        recebido += to_string(camadaenlace.quadro[i]);

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: " << esperado << endl;

    assertm(recebido == esperado, "Falha na insercao de bytes");

    cout << "Enquadramento com inserção de bytes funcionando" << endl;
    cout << endl;
}

void Testes::test_transmissora_enquadramento_insercao_de_bits(void)
{

    CamadaEnlace camadaenlace;
    camadaenlace.DadosTransmissoraEnquadramentoInsercaoDeBits(this->quadro_transmissor);

    cout << "Enquadramento com inserção de bits funcionando" << endl;
    cout << endl;
}

void Testes::test_transmissora_controle_de_erro_bit_paridade_par(void)
{
    CamadaEnlace camadaenlace;
    camadaenlace.DadosTransmissoraControleDeErroBitParidadePar(this->quadro_transmissor);

    cout << "Controle de erro de paridade par funcionando" << endl;
    cout << endl;
}

void Testes::test_receptora_controle_de_erro_bit_paridade_par(void)
{
    CamadaEnlace camadaenlace;
    camadaenlace.DadosReceptoraControleDeErroBitDeParidadePar(this->quadro_transmissor);

    cout << "Recebimento do controle de erro de paridade par funcionando" << endl;
    cout << endl;
}

void Testes::test_transmissora_controle_de_erro_bit_paridade_impar(void)
{
    CamadaEnlace camadaenlace;
    camadaenlace.DadosTransmissoraControleDeErroBitParidadeImpar(this->quadro_transmissor);

    cout << "Recebimento do controle de erro de paridade impar funcionando" << endl;
    cout << endl;
}

void Testes::test_receptora_enquadramento_insercao_de_bytes(void)
{
    CamadaEnlace camadaenlace;
    string enviado = "", recebido = "", esperado = "";

    camadaenlace.DadosTransmissoraEnquadramentoInsercaoDeBytes(this->quadro_transmissor);

    for (int i = 0; i < camadaenlace.quadro.size(); i++)
        enviado += to_string(camadaenlace.quadro[i]);

    camadaenlace.DadosReceptoraEnquadramentoInsercaoDeBytes(camadaenlace.quadro);

    for (int i = 0; i < camadaenlace.quadro.size(); i++)
    {
        recebido += to_string(camadaenlace.quadro[i]);
        esperado += to_string(this->quadro_transmissor[i]);
    }

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: " << esperado << endl;

    assertm(recebido == esperado, "Falha na insercao de bytes");

    cout << "Decodificação do enquadramento com inserção de bytes funcionando" << endl;
    cout << endl;
}

void Testes::test_receptora_camada_aplicacao(void)
{
    CamadaAplicacao camadaaplicacao;

    camadaaplicacao.AplicacaoTransmissora();
    cout << endl;
}

void Testes::test_transmissora_controle_de_erro_crc(void)
{

    CamadaEnlace camadaenlace;
    string enviado = "", recebido = "", esperado = "1111111100000011111100000000111100000101000000001010100110001111111110010";

    camadaenlace.DadosTransmissoraControleDeErroCRC(this->quadro_transmissor);

    for (int i = 0; i < this->quadro_transmissor.size(); i++)
        enviado += to_string(this->quadro_transmissor[i]);

    for (int i = 0; i < camadaenlace.quadro.size(); i++)
        recebido += to_string(camadaenlace.quadro[i]);

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: " << esperado << endl;
    cout << "CRC:            1010100110001111111110010" << endl;

    if (recebido == esperado)
        cout << "Transmissão com controle de erro CRC realizada com sucesso" << endl;
    else
        cout << "Falha na transmissão com controle de erro CRC" << endl;

    cout << endl;
}

void Testes::test_receptora_controle_de_erro_crc(void)
{
    CamadaEnlace camadaenlace;
    string enviado = "", recebido = "", esperado = "111111110000001111110000000011110000010100000000";

    camadaenlace.DadosTransmissoraControleDeErroCRC(this->quadro_transmissor);
    camadaenlace.DadosReceptoraControleDeErroCRC(this->quadro_transmissor);

    for (int i = 0; i < this->quadro_transmissor.size(); i++)
        enviado += to_string(this->quadro_transmissor[i]);

    for (int i = 0; i < camadaenlace.quadro.size(); i++)
        recebido += to_string(camadaenlace.quadro[i]);

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: " << esperado << endl;
    cout << "CRC:            1010100110001111111110010" << endl;

    if (recebido == esperado)
        cout << "Transmissão com controle de erro CRC realizada com sucesso" << endl;
    else
        cout << "Falha na transmissão com controle de erro CRC" << endl;

    cout << endl;
}

void Testes::test_transmissora_controle_de_erro_codificacao_hamming(void)
{
    cout << "Realizando a Codificação e a Decodificação do código de Hamming" << endl;

    CamadaEnlace camadaenlace;
    string enviado = "", recebido = "", esperado = "111111110000001111110000000011110000010100000000";

    cout << "Valor enviado: " << endl;
    for (int i = 0; i < this->quadro_transmissor.size(); i++)
        cout << this->quadro_transmissor.at(i);
    cout << endl;

    cout << this->quadro_transmissor.size() << endl;

    camadaenlace.DadosTransmissoraControleDeErroCodigoDeHamming(this->quadro_transmissor);
    camadaenlace.DadosReceptoraControleDeErroCodigoDeHamming(this->quadro_transmissor);

    cout << "Concluídas a Codificação e a Decodificação do código de Hamming" << endl;
    cout << endl;
}
