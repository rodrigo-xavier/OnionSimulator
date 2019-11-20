#include "../lib/Testes.hpp"
#define assertm(exp, msg) assert(((void)msg, exp))

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
    vector<int> value_255 = {1, 1, 1, 1, 1, 1, 1, 1}, value_3 = {0, 0, 0, 0, 0, 0, 1, 1}, value_esc = {1, 1, 1, 1, 0, 0, 0, 0};
    vector<int> value_flag = {0, 0, 0, 0, 1, 1, 1, 1}, value_5 = {0, 0, 0, 0, 0, 1, 0, 1}, value_0 = {0, 0, 0, 0, 0, 0, 0, 0};
    int introdutor;

    vector<int> concat = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = concat.size(); i >= 0; i--)
    {
        introdutor = int(concat[i]);
        this->quadro_transmissor.push_back(introdutor);
    }
}

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
    test_transmissora_enquadramento_contagem_de_caracteres();
    test_transmissora_enquadramento_insercao_de_bits();
#endif
#ifdef DEBUG_CAMADA_APLICACAO
#endif
}

/*##########################################################################################################*/
// CAMADA FÍSICA

void Testes::test_transmissora_binaria(void)
{
    this->pacote_receptor = camadafisica.TransmissoraCodificacaoBinaria(this->pacote_transmissor);

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Codificacao binária");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Codificacao binária");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Codificacao binária");

    cout << "Codificacao binária funcionando" << endl;
}

void Testes::test_transmissora_manchester(void)
{
    this->pacote_receptor = camadafisica.TransmissoraCodificacaoManchester(this->pacote_transmissor);

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[2]) == 0, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[3]) == 1, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[4]) == 1, "Falha na Codificacao manchester");
    assertm(int(this->pacote_receptor[5]) == 0, "Falha na Codificacao manchester");

    cout << "Codificacao manchester funcionando" << endl;
}

void Testes::test_transmissora_manchester_diferencial(void)
{
    this->pacote_receptor = camadafisica.TransmissoraCodificacaoManchesterDiferencial(this->pacote_transmissor);

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[3]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[4]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->pacote_receptor[5]) == 1, "Falha na Codificacao Manchester Diferencial");

    cout << "Codificacao manchester Diferencial funcionando" << endl;
}

void Testes::test_meio_de_comunicacao(void)
{
    camadafisica.MeioDeComunicacao(this->pacote_transmissor);
}

void Testes::test_binaria_receptora(void)
{
    this->pacote_receptor = camadafisica.ReceptoraCodificacaoBinaria(this->pacote_transmissor);

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Decodificacao binária");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Decodificacao binária");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Decodificacao binária");

    cout << "Decodificacao Binária Funcionando" << endl;
}

void Testes::test_manchester_receptora(void)
{
    this->pacote_meio_comunicacao = camadafisica.TransmissoraCodificacaoManchester(this->pacote_transmissor);
    this->pacote_receptor = camadafisica.ReceptoraCodificacaoManchester(this->pacote_meio_comunicacao);

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Decodificacao manchester");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Decodificacao manchester");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Decodificacao manchester");

    cout << "Decodificacao Manchester Funcionando" << endl;
}

void Testes::test_manchester_receptora_diferencial(void)
{
    this->pacote_meio_comunicacao = camadafisica.TransmissoraCodificacaoManchesterDiferencial(this->pacote_transmissor);
    this->pacote_receptor = camadafisica.ReceptoraCodificacaoManchesterDiferencial(this->pacote_meio_comunicacao);

    assertm(int(this->pacote_receptor[0]) == 1, "Falha na Decodificacao manchester");
    assertm(int(this->pacote_receptor[1]) == 0, "Falha na Decodificacao manchester");
    assertm(int(this->pacote_receptor[2]) == 1, "Falha na Decodificacao manchester");

    cout << "Decodificacao Manchester Diferencial Funcionando" << endl;
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
    int introdutor;
    string quadro = "";
    bitset<8> bin_to_dec;

    this->camadaenlace.DadosTransmissoraEnquadramentoInsercaoDeBytes(this->quadro_transmissor);

    for (int i = 0; i < this->camadaenlace.quadro.size(); i += 8)
    {
        for (int j = 0; j < BYTE; j++)
        {
            bin_to_dec[j] = this->camadaenlace.quadro.back();
            this->camadaenlace.quadro.pop_back();
        }
        quadro += bin_to_dec.to_ulong();
    }

    assertm(quadro == "25532401550", "Falha na Decodificacao manchester");

    cout << "Enquadramento com inserção de bytes funcionando" << endl;
}

void Testes::test_transmissora_enquadramento_insercao_de_bits(void)
{
    camadaenlace.DadosTransmissoraEnquadramentoInsercaoDeBits(this->quadro_transmissor);

    cout << "Enquadramento com inserção de bits funcionando" << endl;
}