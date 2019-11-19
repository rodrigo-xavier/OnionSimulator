#include "../lib/Testes.hpp"
#define assertm(exp, msg) assert(((void)msg, exp))

void Testes::init(void)
{
    // Define o número 5
    this->quadro_transmissor.push_back(1);
    this->quadro_transmissor.push_back(0);
    this->quadro_transmissor.push_back(1);
    // Define o número 5
    run();
}

void Testes::run(void)
{
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
#endif
#ifdef DEBUG_CAMADA_APLICACAO
#endif
}

/*##########################################################################################################*/
// CAMADA FÍSICA
void Testes::test_transmissora_binaria(void)
{
    this->quadro_receptor = camadafisica.TransmissoraCodificacaoBinaria(quadro_transmissor);

    assertm(int(this->quadro_receptor[0]) == 1, "Falha na Codificacao binária");
    assertm(int(this->quadro_receptor[1]) == 0, "Falha na Codificacao binária");
    assertm(int(this->quadro_receptor[2]) == 1, "Falha na Codificacao binária");

    cout << "Codificacao binária funcionando" << endl;
}

void Testes::test_transmissora_manchester(void)
{
    this->quadro_receptor = camadafisica.TransmissoraCodificacaoManchester(quadro_transmissor);

    assertm(int(this->quadro_receptor[0]) == 1, "Falha na Codificacao manchester");
    assertm(int(this->quadro_receptor[1]) == 0, "Falha na Codificacao manchester");
    assertm(int(this->quadro_receptor[2]) == 0, "Falha na Codificacao manchester");
    assertm(int(this->quadro_receptor[3]) == 1, "Falha na Codificacao manchester");
    assertm(int(this->quadro_receptor[4]) == 1, "Falha na Codificacao manchester");
    assertm(int(this->quadro_receptor[5]) == 0, "Falha na Codificacao manchester");

    cout << "Codificacao manchester funcionando" << endl;
}

void Testes::test_transmissora_manchester_diferencial(void)
{
    this->quadro_receptor = camadafisica.TransmissoraCodificacaoManchesterDiferencial(quadro_transmissor);

    assertm(int(this->quadro_receptor[0]) == 1, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->quadro_receptor[1]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->quadro_receptor[2]) == 1, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->quadro_receptor[3]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->quadro_receptor[4]) == 0, "Falha na Codificacao Manchester Diferencial");
    assertm(int(this->quadro_receptor[5]) == 1, "Falha na Codificacao Manchester Diferencial");

    cout << "Codificacao manchester Diferencial funcionando" << endl;
}

void Testes::test_meio_de_comunicacao(void)
{
    camadafisica.MeioDeComunicacao(quadro_transmissor);
}

void Testes::test_binaria_receptora(void)
{
    this->quadro_receptor = camadafisica.ReceptoraCodificacaoBinaria(quadro_transmissor);

    assertm(int(this->quadro_receptor[0]) == 1, "Falha na Decodificacao binária");
    assertm(int(this->quadro_receptor[1]) == 0, "Falha na Decodificacao binária");
    assertm(int(this->quadro_receptor[2]) == 1, "Falha na Decodificacao binária");

    cout << "Decodificacao Binária Funcionando" << endl;
}

void Testes::test_manchester_receptora(void)
{
    this->quadro_meio_comunicacao = camadafisica.TransmissoraCodificacaoManchester(quadro_transmissor);
    this->quadro_receptor = camadafisica.ReceptoraCodificacaoManchester(quadro_meio_comunicacao);

    assertm(int(this->quadro_receptor[0]) == 1, "Falha na Decodificacao manchester");
    assertm(int(this->quadro_receptor[1]) == 0, "Falha na Decodificacao manchester");
    assertm(int(this->quadro_receptor[2]) == 1, "Falha na Decodificacao manchester");

    cout << "Decodificacao Manchester Funcionando" << endl;
}

void Testes::test_manchester_receptora_diferencial(void)
{
    this->quadro_meio_comunicacao = camadafisica.TransmissoraCodificacaoManchesterDiferencial(quadro_transmissor);
    this->quadro_receptor = camadafisica.ReceptoraCodificacaoManchesterDiferencial(quadro_meio_comunicacao);

    assertm(int(this->quadro_receptor[0]) == 1, "Falha na Decodificacao manchester");
    assertm(int(this->quadro_receptor[1]) == 0, "Falha na Decodificacao manchester");
    assertm(int(this->quadro_receptor[2]) == 1, "Falha na Decodificacao manchester");

    cout << "Decodificacao Manchester Diferencial Funcionando" << endl;
}

/*##########################################################################################################*/
// CAMADA ENLACE