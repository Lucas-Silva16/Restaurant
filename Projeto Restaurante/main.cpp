#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "projeto.h"
#include <fstream>

using namespace std;


int main() {
    srand(time(NULL));

    string Pnomes[15];
    string Unomes[15];

    // Abrir os ficheiros para leitura
    ifstream primeiro("primeiro.txt");
    ifstream ultimo("ultimo.txt");

    if (!primeiro.is_open() || !ultimo.is_open()) {
        cout << "Erro ao abrir os ficheiros." << endl;
        return 1;
    }

    string linhaPnome, linhaUnome;
    int i = 0;

    // Ler as linhas dos dois ficheiros e armazenar nos arrays
    while (getline(primeiro, linhaPnome) && getline(ultimo, linhaUnome) && i < 15) {
        Pnomes[i] = linhaPnome; // Armazena o primeiro nome
        Unomes[i] = linhaUnome; // Armazena o sobrenome
        i++;
    }

    // Fechar os ficheiros
    primeiro.close();
    ultimo.close();

    int numMesas = 5 + rand() % 6; // Número entre 5 e 10
    Mesa mesas[numMesas];
    inicializarMesas(mesas, numMesas); // Inicializa as mesas (verifique se a função está corretamente implementada)

    cliente filaEntrada[15];
    inicializarCliente(filaEntrada, 15, Pnomes, Unomes, 13, 13); // Inicializa os clientes (verifique se a função está corretamente implementada)

    int inicio = 0;  // Controla o início da fila
    int fim = 15;    // Controla o final da fila (15 clientes inicialmente na fila)

    cout << "================ ESTADO INICIAL DO RESTAURANTE ================\n";

    // Imprimir mesas
    cout << "Mesas disponíveis:" << endl;
    for (int i = 0; i < numMesas; i++) {
        cout << "Mesa " << mesas[i].ID
             << " | Capacidade: " << mesas[i].Capacidade
             << " | Preferencia: " << mesas[i].Preferencia << endl;
    }

    // Imprimir clientes na fila
    cout << "\nClientes na fila de espera:" << endl;
    imprimeFila(filaEntrada, inicio, fim);

    cout << "\nEscolha uma opcao: (s) Seguinte, (o) Opcoes: ";
    char opcao;
    while (cin >> opcao) {
        if (opcao == 's') {
            // Alocar os clientes nas mesas
            alocarClientesNasMesas(filaEntrada, inicio, fim, mesas, numMesas); // Função modificar a fila e as mesas

            // Exibir estado das mesas após a alocação
            cout << "\nEstado das mesas apos alocar clientes:\n" << endl;
            for (int i = 0; i < numMesas; i++) {
                cout << "Mesa " << mesas[i].ID
                     << " | Refeicao: " << mesas[i].Preferencia
                     << " | Ocupacao: " << mesas[i].Clientes_sentados << " / " << mesas[i].Capacidade << endl;

                // Exibir os clientes sentados na mesa
                if (mesas[i].Clientes_sentados > 0) {
                    for (int j = 0; j < mesas[i].Clientes_sentados; j++) {
                        cliente c = mesas[i].Clientes[j];
                        cout << "    - ID: " << c.id << " | Nome: " << c.Pnome << " " << c.Unome << endl; // ID e nome completo
                    }
                } else {
                    cout << "    Nenhum cliente sentado nesta mesa." << endl;
                }
            }

            // Exibir fila de espera atualizada (fora do loop das mesas)
            cout << "\nFila de espera atualizada:" << endl;
            if (inicio == fim) {
                cout << "Fila vazia" << endl;
            } else {
                imprimeFila(filaEntrada, inicio, fim);
            }

        } else if (opcao == 'o') {
            cout << "Função 'opções' ainda não implementada." << endl;
        } else {
            cout << "Opção inválida. Escolha (s) Seguinte ou (o) Opções: ";
        }

        cout << "\nEscolha uma opcao: (s) Seguinte, (o) Opcoes: ";
    }

    return 0;
}