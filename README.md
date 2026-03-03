# 🍽️ Projeto Restaurante EDA

Este projeto simula a gestão de um restaurante, implementado em C++. O sistema gere clientes, mesas e balcão, controlando o fluxo de entrada, atendimento e saída dos clientes.

## 🎯 Objetivo

Simular o funcionamento de um restaurante com filas de espera e capacidade limitada no balcão e mesas, proporcionando um sistema de atendimento que inclui:
- Gestão de clientes em fila de entrada;
- Alocamento de clientes no balcão e mesas;
- Controle do número máximo de clientes por espaço;
- Registo das preferências e estados dos clientes.

## ⚙️ Funcionalidades Principais

- Fila de espera para clientes que aguardam entrada;
- Movimentação dos clientes do balcão para as mesas;
- Capacidade máxima configurável para balcão e mesas;
- Visualização do estado atual do restaurante (clientes, mesas e balcão);
- Simulação de atendimento baseada em regras definidas.

## 📝 Nota Importante

- A função **ler_ficheiro()** que deverá carregar os dados iniciais do sistema a partir de ficheiros ainda **não está implementada**.

## 📂 Estrutura do Projeto

- `main.cpp`: programa principal com o loop de execução;
- `restaurante.cpp` / `.h`: implementação das estruturas e funções do restaurante;
- `cliente.cpp` / `.h`: definições e manipulação dos clientes;
- Outras funções auxiliares para gestão de filas, mesas e balcão.

## 🔧 Requisitos

- Compilador C++ (ex: g++, clang++);
- Ambiente Linux, Windows ou macOS.

## 💡 Possíveis Expansões Futuras

- Implementação da função de leitura de ficheiros para carregar dados;
- Interface gráfica para visualização e controlo;
- Implementação de mais tipos de mesas e serviços;
- Registo persistente de clientes e estatísticas.

---

👨‍💻 Projeto de grupo desenvolvido para a disciplina de Estruturas de Dados e Algoritmos (EDA).
