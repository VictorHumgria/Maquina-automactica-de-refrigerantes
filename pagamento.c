#include <stdio.h>
#include "pagamento.h"
#include "algoritmos.h"
#include "interface.h"
float pagamento = 0;
void efetuarPagamento(Refrigerante refrigerantes[], int escolha, float moedas[], int tamanho_moedas)
{
    float troco, pagamento2;
    printf("\nVocê escolheu: %s, insira o valor (em reais): ", refrigerantes[escolha - 1].nome);
    scanf("%f", &pagamento2);
    pagamento += pagamento2;

    if (pagamento < refrigerantes[escolha - 1].preco)
    {
        printf("\nValor insuficiente.\n");
        efetuarPagamento(refrigerantes, escolha, moedas, tamanho_moedas);
        return;
    }
    troco = pagamento - refrigerantes[escolha - 1].preco;
    printf("Troco a ser devolvido: R$ %.2f\n", troco);

    int metodo,num_moedas;
    printf("Escolha o método para calcular o troco:\n");
    printf("1. Algoritmo Guloso\n");
    printf("2. Programação Dinâmica\n");
    printf("Opção: ");
    scanf("%d", &metodo);
    switch (metodo)
    {
    case 1:
        calculaTrocoGuloso(moedas, tamanho_moedas, troco);
        break;
    case 2:
        num_moedas = calculaTrocoDP(moedas, tamanho_moedas, troco);
        if (num_moedas != -1)
        {
            printf("Número mínimo de moedas para o troco: %d\n", num_moedas);
        }
        break;
    default:
        printf("Método inválido.\n");
        break;
    }
    refrigerantes[escolha - 1].quantidade_estoque--;
}

void efetuarCompra(Refrigerante refrigerantes[], int n, float moedas[], int tamanho_moedas)
{
    int escolha;
    exibirRefrigerantes(refrigerantes, n);
    printf("\nDigite o refrigerante que deseja comprar (1-%d): ", n);
    scanf("%d", &escolha);
    if (escolha < 1 || escolha > n)
    {
        printf("\nOpção inválida\n");
        return;
    }
    if (refrigerantes[escolha - 1].quantidade_estoque <= 0)
    {
        printf("\nDesculpe, o produto selecionado está esgotado.\n");
        return;
    }
    efetuarPagamento(refrigerantes, escolha, moedas, tamanho_moedas);
    pagamento = 0;
}
