#ifndef PROJETO_H
#define PROJETO_H
#include <string>  // Para o tipo string

// Estrutura para os clientes
struct cliente {
    int id;
    std::string Pnome;
    std::string Unome;
    std::string Preferencia;
    bool Reserva;
    int Temporefeicao;
};

// Estrutura para as mesas
struct Mesa {
    char ID;                       // ID da mesa (ex.: 'A', 'B', ...)
    int Capacidade;                // Número total de lugares
    int Reserva;                   // Lugares reservados
    std::string Preferencia;       // Tipo de refeição aceito pela mesa
    int Clientes_sentados;         // Número de lugares ocupados atualmente
    cliente Clientes[6];          // Array estático para os clientes da mesa (máximo fixo: 10)
};

// Estrutura para o balcão – não foi necessário mudar aqui
struct Balcao {
    int capacidade;
    int clientesAtuais;
};


// Declaração das funções
void inicializarMesas(Mesa mesas[], int quantidade);
void inicializarCliente(cliente fila[], int quantidade, std::string primeiros[], std::string ultimos[], int tamPrimeiros, int tamUltimos);
std::string GeraNomes(std::string nomes[], int tamanho);
void fila_de_espera(cliente* fila, int& inicio, int& fim, int& capacidade, cliente novo_cliente);
cliente removerCliente(cliente* fila, int& inicio, int& fim);
void imprimeFila(cliente*fila, int inicio, int fim);
void alocarClientesNasMesas(cliente fila[], int &inicio, int &fim, Mesa mesas[], int numMesas);


#endif // PROJETO_H PROJETO_H