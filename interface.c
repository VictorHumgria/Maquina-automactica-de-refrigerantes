#include <stdio.h>
#include <string.h>
#include "interface.h"
#include "refrigerante.h"

void desenharBorda(char c) {
    for (int i = 0; i < LARGURA; i++) {
        printf("%c", c);
    }
    printf("\n");
}

void desenharTitulo(char *titulo) {
    desenharBorda('=');
    int espacos = (LARGURA - strlen(titulo)) / 2;
    printf("%*s%s\n", espacos, "", titulo);
    desenharBorda('=');
}

void desenharLinha(char *esquerda, char *direita) {
    int espacos = LARGURA - strlen(esquerda) - strlen(direita) - 3;
    if (espacos < 0) {
        espacos = 1;
    }
    printf("| %s%*s|\n", esquerda, espacos, direita);
}

void exibirMenu() {
    desenharTitulo("Menu Interativo");
    desenharLinha("1. Efetuar Compra", "");
    desenharLinha("2. Adicionar Refrigerante", "");
    desenharLinha("3. Repor Estoque", "");
    desenharLinha("4. Encontrar Combinacao", "");
    desenharLinha("5. Exibir Estoque", "");
    desenharLinha("0. Sair", "");
    desenharBorda('=');
}

void exibirRefrigerantesGraficos(Refrigerante refrigerantes[], int n) {
    desenharTitulo("Refrigerantes Disponíveis");
    for (int i = 0; i < n; i++) {
        char nome_com_indice[50], preco_estoque[40];
        sprintf(nome_com_indice, "%d. %s", i + 1, refrigerantes[i].nome);
        sprintf(preco_estoque, "R$ %.2f (Estoque: %d)", refrigerantes[i].preco, refrigerantes[i].quantidade_estoque);
        desenharLinha(nome_com_indice, preco_estoque);
    }
    desenharBorda('=');
}
void exibirRefrigerantes(Refrigerante refrigerantes[], int n) {
    exibirRefrigerantesGraficos(refrigerantes, n);
}
