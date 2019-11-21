/*##########################################################################################################*/
// INCLUDE

#include "CamadaFisica.hpp"
#include "CamadaEnlace.hpp"
#include "CamadaAplicacao.hpp"
#include <iostream>
#include <string>
#include <assert.h>

/*##########################################################################################################*/
// DEFINE

// #define DEBUG_CAMADA_FISICA
// #define DEBUG_CAMADA_ENLACE
#define DEBUG_CAMADA_APLICACAO
#define assertm(exp, msg) assert(((void)msg, exp))
#define BYTE 8

/*##########################################################################################################*/
// CLASS

using namespace std;

class Testes
{
public:
    vector<int> pacote_transmissor, pacote_receptor, pacote_meio_comunicacao;
    vector<int> quadro_transmissor;

    void init_pacote(void);
    void init_quadro(void);
    void run(void);

    /* Camada Física */
    void test_transmissora_binaria(void);
    void test_transmissora_manchester(void);
    void test_transmissora_manchester_diferencial(void);
    void test_meio_de_comunicacao(void);
    void test_binaria_receptora(void);
    void test_manchester_receptora(void);
    void test_manchester_receptora_diferencial(void);

    /* Camada Enlace */
    void test_transmissora_enquadramento_insercao_de_bytes(void);
    void test_transmissora_enquadramento_contagem_de_caracteres(void);
    void test_transmissora_enquadramento_insercao_de_bits(void);
    void test_transmissora_controle_de_erro_bit_paridade_impar(void);
    void test_transmissora_controle_de_erro_bit_paridade_par(void);
    void test_receptora_controle_de_erro_bit_paridade_par(void);
    void test_receptora_enquadramento_insercao_de_bytes(void);
    void test_receptora_camada_aplicacao(void);
    void test_transmissora_controle_de_erro_crc(void);
    void test_receptora_controle_de_erro_crc(void);
    void test_transmissora_controle_de_erro_codificacao_hamming(void);
};