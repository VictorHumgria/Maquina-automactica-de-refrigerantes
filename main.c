/*
    Trabalho de Estrutura de Dados 2, 2024.1, 3a Unidade
    Alunos: 
        - JOAO VICTOR MENESES SOUZA          - 202300133617
        - JOAO VICTOR SILVA DE HUNGRIA       - 202000060933
        - RENNE BISPO DOS SANTOS             - 202100056227
        - TALYSSON FELIPE VASCONCELOS SANTOS - 202100007438
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "interface.h"
#include "estoque.h"
#include "pagamento.h"
#include "algoritmos.h"
#include "persistencia.h"

void menuInterativo(Refrigerante *refrigerantes, int *n, float moedas[], int tamanho_moedas) {
    int opcao = -1;
    while (opcao != 0) {
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                efetuarCompra(refrigerantes, *n, moedas, tamanho_moedas);
                break;
            case 2:
                refrigerantes = adicionarRefrigerante(refrigerantes, n);
                break;
            case 3:
                refrigerantes = reabastecerEstoque(refrigerantes, n);
                break;
            case 4:
                escolherRefrigeranteBacktracking(refrigerantes, *n);
                break;
            case 5:
                exibirRefrigerantes(refrigerantes, *n);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, " ");
    int n = 4;
    Refrigerante *refrigerantes = carregarEstoque(&n, "estoque.json");

    if (!refrigerantes) {
        printf("Estoque não encontrado, inicializando estoque padrão.\n");
        refrigerantes = malloc(n * sizeof(Refrigerante));
        refrigerantes[0] = (Refrigerante){"Coca", 2.50, 5};
        refrigerantes[1] = (Refrigerante){"Fanta", 1.50, 5};
        refrigerantes[2] = (Refrigerante){"Guaraná", 3.00, 5};
        refrigerantes[3] = (Refrigerante){"Tubaína", 3.50, 5};
    }

    float moedas[] = {0.05, 0.10, 0.25, 0.50, 1.00};
    int tamanho_moedas = sizeof(moedas) / sizeof(moedas[0]);

    menuInterativo(refrigerantes, &n, moedas, tamanho_moedas);
    salvarEstoque(refrigerantes, n, "estoque.json");

    free(refrigerantes);
    return 0;
}
