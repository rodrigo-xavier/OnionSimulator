#include "../lib/CamadaFisica.hpp"

/*##########################################################################################################*/
// TRANSMISSORA

/********************************************************************************************  
  Descrição Breve: Método transmissor de dados da Camada Física
  
  Descrição da Entrada:
  (pacote) - Unidade de dados da camada física

  Descrição da saída:
  (void)

  Descrição Detalhada: 
*********************************************************************************************/
void CamadaFisica::Transmissora(vector<int> pacote)
{
    int tipoDeCodificacao = 0;
    vector<int> fluxoBrutoDeBits;
    switch (tipoDeCodificacao)
    {
    case 0: //codificao binaria
        fluxoBrutoDeBits = TransmissoraCodificacaoBinaria(pacote);
        break;
    case 1: //codificacao manchester
        fluxoBrutoDeBits = TransmissoraCodificacaoManchester(pacote);
        break;
    case 2: //codificacao manchester diferencial
        fluxoBrutoDeBits = TransmissoraCodificacaoManchesterDiferencial(pacote);
        break;
    } //fim do switch/case
    MeioDeComunicacao(fluxoBrutoDeBits);
}

/********************************************************************************************  
  Descrição Breve: Método da Camada Física de codificação Binária
  
  Descrição da Entrada:
  (pacote) - Unidade de dados da camada física

  Descrição da saída:
  (codificacao_binaria) - 

  Descrição Detalhada: 
*********************************************************************************************/

vector<int> CamadaFisica::TransmissoraCodificacaoBinaria(vector<int> pacote)
{
    cout << "Realizando a codificação binária: ";

    vector<int> codificacao_binaria;

    for (int i = 0; i < pacote.size(); i++)
    {
        codificacao_binaria.push_back(pacote[i]);
        cout << pacote[i];
    }
    cout << endl;

    return codificacao_binaria;
}

/********************************************************************************************  
  Descrição Breve: Método da Camada Física de Codificação Manchester
  
  Descrição da Entrada:
  (pacote) - Unidade de dados da camada física

  Descrição da saída:
  (codificacao_manchester) - Pacote codificado com a codificação Manchester

  Descrição Detalhada: A codificação manchester separa os bits em clocks, 
*********************************************************************************************/
vector<int> CamadaFisica::TransmissoraCodificacaoManchester(vector<int> pacote)
{
    cout << "Realizando a codificação manchester" << endl;

    vector<int> codificacao_manchester;

    for (int i = 0; i < pacote.size(); i++)
    {
        codificacao_manchester.push_back(pacote[i] ^ 0);
        codificacao_manchester.push_back(pacote[i] ^ 1);
    }

    return codificacao_manchester;
}

/********************************************************************************************  
  Descrição Breve: Método da Camada Física de codificação Binária
  
  Descrição da Entrada:
  (pacote) - Unidade de dados da camada física

  Descrição da saída:
  (codificacao_manchester_diferencial) - 

  Descrição Detalhada: 
*********************************************************************************************/
vector<int> CamadaFisica::TransmissoraCodificacaoManchesterDiferencial(vector<int> pacote)
{
    cout << "Realizando a Codificação Manchester Diferencial" << endl;

    vector<int> codificacao_manchester_diferencial;
    int alternador = 0;

    for (int i = 0; i < pacote.size(); i++)
    {
        if (pacote[i] == 1)
            alternador = alternador ^ 1;

        codificacao_manchester_diferencial.push_back(alternador);
        codificacao_manchester_diferencial.push_back(alternador ^ 1);
    }

    return codificacao_manchester_diferencial;
}

/*##########################################################################################################*/
// RECEPTORA

/********************************************************************************************  
  Descrição Breve: Método da Camada Física de codificação Binária
  
  Descrição da Entrada:
  (pacote) - Unidade de dados da camada física

  Descrição da saída:
  (void)

  Descrição Detalhada: 
*********************************************************************************************/
void CamadaFisica::Receptora(vector<int> pacote)
{
    int tipoDeDecodificacao = 0;  //alterar de acordo o teste
    vector<int> fluxoBrutoDeBits; //ATENÇÃO: trabalhar com BITS!!!
    //CamadaAplicacao camadaaplicacao;

    switch (tipoDeDecodificacao)
    {
    case 0: //codificao binaria
        fluxoBrutoDeBits = ReceptoraCodificacaoBinaria(pacote);
        break;
    case 1: //codificacao manchester
        fluxoBrutoDeBits = ReceptoraCodificacaoManchester(pacote);
        break;
    case 2: //codificacao manchester diferencial
        fluxoBrutoDeBits = ReceptoraCodificacaoManchesterDiferencial(pacote);
        break;
    }
    //chama proxima camada
    //camadaaplicacao.Receptora(fluxoBrutoDeBits);
}

/********************************************************************************************  
  Descrição Breve: Método da Camada Física de codificação Binária
  
  Descrição da Entrada:
  (pacote) - Unidade de dados da camada física

  Descrição da saída:
  (decodificacao_binaria) - 

  Descrição Detalhada: 
*********************************************************************************************/
vector<int> CamadaFisica::ReceptoraCodificacaoBinaria(vector<int> pacote)
{
    cout << "Realizando a decodificação binária: ";

    vector<int> decodificacao_binaria;

    for (int i = 0; i < pacote.size(); i++)
    {
        decodificacao_binaria.push_back(pacote[i]);
        cout << pacote[i];
    }
    cout << endl;

    return decodificacao_binaria;
}

/********************************************************************************************  
  Descrição Breve: Método da Camada Física de codificação Binária
  
  Descrição da Entrada:
  (pacote) - Unidade de dados da camada física

  Descrição da saída:
  (decodificacao_manchester) - 

  Descrição Detalhada: 
*********************************************************************************************/
vector<int> CamadaFisica::ReceptoraCodificacaoManchester(vector<int> pacote)
{
    cout << "Realizando a decodificação manchester" << endl;

    vector<int> decodificacao_manchester;

    for (int i = 0; i < pacote.size(); i += 2)
    {
        if ((pacote[i] == 0) && (pacote[i + 1] == 1))
            decodificacao_manchester.push_back(0);
        else if ((pacote[i] == 1) && (pacote[i + 1] == 0))
            decodificacao_manchester.push_back(1);
        else
            cout << "Erro na Decodificação" << endl;
    }

    return decodificacao_manchester;
}

/********************************************************************************************  
  Descrição Breve: Método da Camada Física de codificação Binária
  
  Descrição da Entrada:
  (pacote) - Unidade de dados da camada física

  Descrição da saída:
  (decodificacao_manchester_diferencial) - 

  Descrição Detalhada: 
*********************************************************************************************/
vector<int> CamadaFisica::ReceptoraCodificacaoManchesterDiferencial(vector<int> pacote)
{
    cout << "Realizando a Decodificação Manchester Diferencial" << endl;

    int alternador = 0;
    vector<int> decodificacao_manchester;

    for (int i = 0; i < pacote.size(); i += 2)
    {
        if ((pacote[i] == (0 ^ alternador)) && (pacote[i + 1] == (1 ^ alternador)))
            decodificacao_manchester.push_back(0);
        else if ((pacote[i] == (1 ^ alternador)) && (pacote[i + 1] == (0 ^ alternador)))
        {
            alternador = alternador ^ 1;
            decodificacao_manchester.push_back(1);
        }
        else
            cout << "Erro na Decodificação" << endl;
    }

    return decodificacao_manchester;
}

/*##########################################################################################################*/
// MEIO DE COMUNICAÇÃO

/********************************************************************************************  
  Descrição Breve: Método da Camada Física de codificação Binária
  
  Descrição da Entrada:
  (fluxoBrutoDeBits) - 

  Descrição da saída:
  (void)

  Descrição Detalhada: 
*********************************************************************************************/
void CamadaFisica::MeioDeComunicacao(vector<int> fluxoBrutoDeBits)
{
    //OBS IMPORTANTE: trabalhar com BITS e nao com BYTES!!!
    vector<int> fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;
    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    for (int i = 0; i < fluxoBrutoDeBitsPontoA.size(); i++)
    {
        //BITS! Sendo transferidos
        fluxoBrutoDeBitsPontoB.push_back(fluxoBrutoDeBitsPontoA.at(i));
    } //fim do while

    cout << "Passando pelo Meio de Comunicação" << endl;
    //chama proxima camada
    Receptora(fluxoBrutoDeBitsPontoB);
}