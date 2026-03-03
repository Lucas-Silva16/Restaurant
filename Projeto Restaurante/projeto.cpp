//
// Created by lucas on 07/03/2025.
//
#include <iostream>
using namespace std;
#include "projeto.h"

//Funcao para gerar nomes aleatoriamente
string GeraNomes(string nomes [], int tamanho) {
    return nomes[rand() % tamanho];
}
//Funcao para por os clientes na fila  aleatoriamente
void inicializarCliente(cliente fila[], int quantidade, string primeiros [], string ultimos [] , int tamPrimeiros, int tamUltimos) {
    string opcoesPref[]={"snack","vegetariano","vegan","peixe","carne"};
    int num_opcoes=5;

    for (int i = 0; i < quantidade; i++) {
        fila[i].id=i+1;
        fila[i].Pnome = GeraNomes(primeiros, tamPrimeiros);
        fila[i].Unome = GeraNomes(ultimos, tamUltimos);
        fila[i].Preferencia = opcoesPref[rand() % num_opcoes];
        fila[i].Reserva = (rand() % 100<15);
        fila[i].Temporefeicao=3+(rand () %6 );
    }
}
//Funcao para gerar aleitoraimente mesa
void inicializarMesas(Mesa mesas [], int quantidade){
    string opcoesPref[]={"vegetariano","vegan","peixe","carne"};
    int num_opcoes=4;
    for (int i = 0; i < quantidade; i++) {
        mesas[i].ID= 'A' + i;
        mesas[i].Capacidade= 2 + rand() % 5;
        mesas[i].Reserva= mesas[i].Capacidade/2;
        mesas[i].Preferencia= opcoesPref[rand() % num_opcoes];
        mesas[i].Clientes_sentados= 0;
    }
}

void fila_de_espera(cliente* fila, int& inicio, int& fim, int& capacidade, cliente novo_cliente){
    if (fim==capacidade) {
        int novacapacidade=capacidade*2;
        cliente * novafila = new cliente[novacapacidade];

        for (int i=inicio ; i<fim ; i++) {
            novafila[i-inicio] = fila[i];
        }
        delete [] fila;
        fila=novafila;
        fila -= inicio;
        inicio=0;
        capacidade=novacapacidade;
    }
    fila[fim]=novo_cliente;
    fim++;

}

cliente removerCliente(cliente* fila, int& inicio, int& fim){
    if (inicio==fim) {
        cout<<"Fila vazia"<<endl;
        return cliente();

    }
    cliente removido = fila[inicio];
    inicio++;
}

void imprimeFila(cliente filaEntrada[], int inicio, int fim) {
    for (int i = inicio; i < fim; i++) {
        cout << filaEntrada[i].id << ". " << filaEntrada[i].Pnome << " " << filaEntrada[i].Unome
             << " | Preferencia: " << filaEntrada[i].Preferencia
             << (filaEntrada[i].Reserva ? " (com reserva)" : "") << endl;
    }
}

void alocarClientesNasMesas(cliente fila[], int &inicio, int &fim, Mesa mesas[], int numMesas) {
    int clientesAlocados = 0;
    int target = 8; // Número máximo de clientes alocados por ciclo

    // Percorre a fila de espera (de "inicio" até "fim")
    int currentIndex = inicio;
    while (currentIndex < fim && clientesAlocados < target) {
        cliente c = fila[currentIndex];

        // Ignorar clientes com preferência "snack" (eles não podem ser alocados em mesas)
        if (c.Preferencia == "snack") {
            currentIndex++;
            continue;
        }

        bool alocado = false;

        // Tenta alocar o cliente em mesas compatíveis
        for (int i = 0; i < numMesas; i++) {
            if (mesas[i].Preferencia == c.Preferencia) {
                // Verificar se há espaço disponível nesta mesa
                if (mesas[i].Clientes_sentados < mesas[i].Capacidade) {
                    // Adicionar o cliente à mesa
                    mesas[i].Clientes[mesas[i].Clientes_sentados] = c;
                    mesas[i].Clientes_sentados++; // Incrementa o número de clientes sentados na mesa
                    alocado = true;
                    break;
                }
            }
        }

        if (alocado) {
            // Remove cliente da fila, deslocando os demais para frente
            for (int j = currentIndex; j < fim - 1; j++) {
                fila[j] = fila[j + 1];
            }
            fim--; // Reduz o índice do final da fila
            clientesAlocados++; // Incrementa o número de clientes alocados
        } else {
            // Cliente não pode ser alocado, então avança para o próximo na fila
            currentIndex++;
        }
    }
}




