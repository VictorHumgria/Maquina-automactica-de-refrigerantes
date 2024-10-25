#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "algoritmos.h"

void calculaTrocoGuloso(float moedas[], int n, float troco) { 
    int quantidade_moedas[n];
    memset(quantidade_moedas, 0, sizeof(quantidade_moedas));    // define todos os valores de quantidade_moedas para 0
    printf("Moedas usadas para o troco de R$ %.2f: ", troco);   // exibe o valor do troco
    for (int i = n - 1; i >= 0; i--) {                          // percorre as moedas de maior valor para menor valor
        while (troco >= moedas[i] - 0.001) {                    // enquanto o troco for maior ou igual ao valor da moeda
            troco -= moedas[i];                                 // subtrai o valor da moeda do troco
            quantidade_moedas[i]++;
            troco = ((int)(troco * 100 + 0.5)) / 100.0;
        }
    }
    for (int i = n - 1; i >= 0; i--) {                          // for que percorre as moedas do troco e exibe a quantidade de cada moeda
        if (quantidade_moedas[i] > 0) {                         // se a quantidade de moedas for maior que 0
            printf("%d x R$ %.2f ", quantidade_moedas[i], moedas[i]);   // exibe a quantidade de moedas e o valor da moeda
        }
    }
    printf("\n");
}
int calculaTrocoDP(float moedas[], int n, float troco) {
    int valor = (int)(troco * 100 + 0.5);                  
    int tabela[valor + 1];
    int usado[valor + 1];                                       

    tabela[0] = 0;
    for (int i = 1; i <= valor; i++) {                      
        tabela[i] = INT_MAX;
        usado[i] = -1;
    }

    for (int i = 1; i <= valor; i++) {                          
        for (int j = 0; j < n; j++) {                           
            int moeda_valor = (int)(moedas[j] * 100 + 0.5);     
            if (moeda_valor <= i) {                            
                int sub_res = tabela[i - moeda_valor];         
                if (sub_res != INT_MAX && sub_res + 1 < tabela[i]) {
                    tabela[i] = sub_res + 1;
                    usado[i] = j;
                }
            }
        }
    }
    // verificar se restou algum valor na tabela
    if (tabela[valor] == INT_MAX) {
        printf("Não é possível dar o troco exato.\n");
        return -1;
    }
    printf("Moedas usadas para o troco de R$ %.2f: ", troco);
    int t = valor;
    while (t > 0) {
        int j = usado[t];
        printf("R$ %.2f ", moedas[j]);
        t -= (int)(moedas[j] * 100 + 0.5);
    }
    printf("\n");
    return tabela[valor];
    if (valor > 0 && tabela[valor] == 0) {
       printf("Não é possível dar o troco exato. Sobrou :%.2f\n", (float)valor/100);
    }
}
void encontrarCombinacao(Refrigerante refrigerantes[], int n, float valor_alvo, int idR, float soma_atual, int *solucao) {
    if (soma_atual > valor_alvo)    // Se a soma atual for maior que o valor alvo, não há necessidade de continuar
        return;
    if (soma_atual == valor_alvo) { // Se a soma atual for igual ao valor alvo, exibe a combinação
        printf("Combinação encontrada: ");
        for (int i = 0; i < n; i++) {
            if (solucao[i] > 0) {
                printf("%d x %s ", solucao[i], refrigerantes[i].nome);
            }
        }
        printf("\n");
        return;
    }
    for (int i = idR; i < n; i++) { // Para cada refrigerante, tenta adicionar um refrigerante ao troco  
        if (refrigerantes[i].quantidade_estoque > 0) { // Se o refrigerante está disponível
            solucao[i]++;                               // Adiciona o refrigerante à solução
            encontrarCombinacao(refrigerantes, n, valor_alvo, i, soma_atual + refrigerantes[i].preco, solucao);    //   Chama a função recursivamente
            solucao[i]--;                                                                                          //   Remove o refrigerante da solução
        }
    }
}

void escolherRefrigeranteBacktracking(Refrigerante refrigerantes[], int n) {
    float valor_alvo;
    printf("\nDigite o valor que deseja gastar: ");
    scanf("%f", &valor_alvo);
    int *solucao = calloc(n, sizeof(int));
    printf("Buscando combinações de refrigerantes que somam R$ %.2f...\n", valor_alvo);
    encontrarCombinacao(refrigerantes, n, valor_alvo, 0, 0.0, solucao);
    free(solucao);
}
