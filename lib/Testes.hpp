/*##########################################################################################################*/
// INCLUDE

#include "../lib/CamadaFisica.hpp"
#include "../lib/CamadaEnlace.hpp"
#include <iostream>
#include <string>
#include <assert.h>

/*##########################################################################################################*/
// DEFINE

#define DEBUG_CAMADA_FISICA
#define DEBUG_CAMADA_ENLACE
#define DEBUG_CAMADA_APLICACAO

/*##########################################################################################################*/
// CLASS

using namespace std;

class Testes
{
public:
    CamadaFisica camadafisica;
    CamadaEnlace camadaenlace;
    vector<int> quadro_transmissor;
    vector<int> quadro_receptor;
    vector<int> quadro_meio_comunicacao;

    void init(void);
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
};