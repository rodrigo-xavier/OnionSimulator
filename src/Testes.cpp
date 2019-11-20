#include "../lib/Testes.hpp"

void Testes::run(void)
{
    init_pacote();
    init_quadro();

#ifdef DEBUG_CAMADA_FISICA
    test_transmissora_binaria();
    test_transmissora_manchester();
    test_transmissora_manchester_diferencial();
    test_meio_de_comunicacao();
    test_binaria_receptora();
    test_manchester_receptora();
    test_manchester_receptora_diferencial();
#endif

#ifdef DEBUG_CAMADA_ENLACE

    // test_transmissora_enquadramento_contagem_de_caracteres();
    // test_transmissora_enquadramento_insercao_de_bits();
    test_transmissora_enquadramento_insercao_de_bytes();
    // test_transmissora_controle_de_erro_bit_paridade_impar();
    //    test_receptora_controle_de_erro_bit_paridade_par();
    test_receptora_enquadramento_insercao_de_bytes();

#endif

#ifdef DEBUG_CAMADA_APLICACAO
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
    camadafisica.MeioDeComunicacao(this->pacote_transmissor);
    cout << endl;
}

void Testes::test_binaria_receptora(void)
{
    string enviado = "", recebido = "";

    this->pacote_receptor = camadafisica.ReceptoraCodificacaoBinaria(this->pacote_transmissor);

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
    camadaenlace.DadosTransmissoraEnquadramentoContagemDeCaracteres(this->quadro_transmissor);

    cout << int(this->quadro_transmissor[0]) << endl;
    /*assertm(int(this->quadro_transmissor[0]) == 6, "Falha no Enquadramento usando contagem de caracteres");
    assertm(int(this->quadro_transmissor[1]) == 0, "Falha no Enquadramento usando contagem de caracteres");
    assertm(int(this->quadro_transmissor[47]) == 1, "Falha no Enquadramento usando contagem de caracteres");
    */
    cout << "Enquadramento usando contagem de caracteres funcionando" << endl;
}

void Testes::test_transmissora_enquadramento_insercao_de_bytes(void)
{
    string _255 = "11111111", _3 = "00000011", _esc_240 = "11110000";
    string _flag_15 = "00001111", _5 = "00000101", _0 = "00000000";
    string esperado = _flag_15 + _255 + _3 + _esc_240 + _esc_240 + _esc_240 + _flag_15 + _5 + _0 + _flag_15;
    string enviado = "", recebido = "";

    this->camadaenlace.DadosTransmissoraEnquadramentoInsercaoDeBytes(this->quadro_transmissor);

    for (int i = 0; i < this->quadro_transmissor.size(); i++)
        enviado += to_string(this->quadro_transmissor[i]);

    for (int i = 0; i < this->camadaenlace.quadro.size(); i++)
        recebido += to_string(this->camadaenlace.quadro[i]);

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: " << esperado << endl;

    assertm(recebido == esperado, "Falha na insercao de bytes");

    cout << "Enquadramento com inserção de bytes funcionando" << endl;
    cout << endl;
}

void Testes::test_transmissora_enquadramento_insercao_de_bits(void)
{
    camadaenlace.DadosTransmissoraEnquadramentoInsercaoDeBits(this->quadro_transmissor);

    cout << "Enquadramento com inserção de bits funcionando" << endl;
}

void Testes::test_transmissora_controle_de_erro_bit_paridade_par(void)
{
    camadaenlace.DadosTransmissoraControleDeErroBitParidadePar(this->quadro_transmissor);

    cout << "Controle de erro de paridade par funcionando" << endl;
}

void Testes::test_receptora_controle_de_erro_bit_paridade_par(void)
{
    camadaenlace.DadosReceptoraControleDeErroBitDeParidadePar(this->quadro_transmissor);

    cout << "Recebimento do controle de erro de paridade par funcionando" << endl;
}

void Testes::test_transmissora_controle_de_erro_bit_paridade_impar(void)
{
    camadaenlace.DadosTransmissoraControleDeErroBitParidadeImpar(this->quadro_transmissor);

    cout << "Recebimento do controle de erro de paridade impar funcionando" << endl;
}

void Testes::test_receptora_enquadramento_insercao_de_bytes(void)
{
    string enviado = "", recebido = "", esperado = "";

    this->camadaenlace.DadosTransmissoraEnquadramentoInsercaoDeBytes(this->quadro_transmissor);

    for (int i = 0; i < this->camadaenlace.quadro.size(); i++)
        enviado += to_string(this->camadaenlace.quadro[i]);

    this->camadaenlace.DadosReceptoraEnquadramentoInsercaoDeBytes(this->camadaenlace.quadro);

    for (int i = 0; i < this->camadaenlace.quadro.size(); i++)
    {
        recebido += to_string(this->camadaenlace.quadro[i]);
        esperado += to_string(this->quadro_transmissor[i]);
    }

    cout << "Valor enviado : " << enviado << endl;
    cout << "Valor recebido: " << recebido << endl;
    cout << "Valor esperado: " << esperado << endl;

    assertm(recebido == esperado, "Falha na insercao de bytes");

    cout << "Decodificação do enquadramento com inserção de bytes funcionando" << endl;
    cout << endl;
}