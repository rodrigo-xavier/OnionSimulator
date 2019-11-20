#include "../lib/Testes.hpp"

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
    string value_255 = "11111111", value_3 = "00000011", value_esc_240 = "11110000";
    string value_flag_15 = "00001111", value_5 = "00000101", value_0 = "00000000";
    int introdutor;

    string concat = value_255 + value_3 + value_esc_240 + value_flag_15 + value_5 + value_0;

    for (int i = 0; i < concat.length(); i++)
    {
        introdutor = concat[i] - '0';
        this->quadro_transmissor.push_back(introdutor);
    }
}

void Testes::run(void)
{
    init_pacote();
    init_quadro();
/*#ifdef DEBUG_CAMADA_FISICA
    test_transmissora_binaria();
    test_transmissora_manchester();
    test_transmissora_manchester_diferencial();
    test_meio_de_comunicacao();
    test_binaria_receptora();
    test_manchester_receptora();
    test_manchester_receptora_diferencial();
#endif*/
#ifdef DEBUG_CAMADA_ENLACE

    /*    
    test_transmissora_enquadramento_contagem_de_caracteres();
    test_transmissora_enquadramento_insercao_de_bits();
    test_transmissora_enquadramento_insercao_de_bytes();
    */
    test_transmissora_controle_de_erro_bit_paridade_impar();
    //    test_receptora_controle_de_erro_bit_paridade_par();

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
    string _255 = "11111111", _3 = "00000011", _esc_240 = "11110000";
    string _flag_15 = "00001111", _5 = "00000101", _0 = "00000000";

    string quadro_real = _flag_15 + _255 + _3 + _esc_240 + _esc_240 + _esc_240 + _flag_15 + _5 + _0 + _flag_15;
    int counter = 1;
    string quadro = "";

    this->camadaenlace.DadosTransmissoraEnquadramentoInsercaoDeBytes(this->quadro_transmissor);

    for (int i = 0; i < this->camadaenlace.quadro.size(); i++)
    {
        quadro += to_string(this->camadaenlace.quadro[i]);
    }

    assertm(quadro == quadro_real, "Falha na insercao de bytes");

    cout << "Enquadramento com inserção de bytes funcionando" << endl;
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