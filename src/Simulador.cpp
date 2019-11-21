#include "../lib/CamadaFisica.hpp"
#include "../lib/CamadaEnlace.hpp"
#include "../lib/CamadaAplicacao.hpp"
#include "../lib/Testes.hpp"
#include <iostream>
#include <string>

int main(int argc, char *args[])
{
    Testes teste;
    teste.run();

    CamadaAplicacao maquinaA;
    CamadaAplicacao maquinaB;

    return 0;
}
