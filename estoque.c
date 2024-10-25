#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"
#include "interface.h"

Refrigerante *adicionarRefrigerante(Refrigerante *refrigerantes, int *n)
{
    refrigerantes = realloc(refrigerantes, (*n + 1) * sizeof(Refrigerante));
    if (refrigerantes == NULL)
    {
        printf("\nErro ao adicionar o refrigerante.\n");
        return NULL;
    }
    else
    {
        printf("\nDigite o nome do refrigerante: ");
        getchar(); // Limpar o buffer de entrada
        fgets(refrigerantes[*n].nome, sizeof(refrigerantes[*n].nome), stdin);

        size_t len = strlen(refrigerantes[*n].nome);
        if (len > 0 && refrigerantes[*n].nome[len - 1] == '\n')
        {
            refrigerantes[*n].nome[len - 1] = '\0';
        }

        printf("Digite o preço do refrigerante (em reais): ");
        scanf("%f", &refrigerantes[*n].preco);
        printf("Digite a quantidade a ser adicionada: ");
        scanf("%d", &refrigerantes[*n].quantidade_estoque);

        (*n)++;

        printf("Refrigerante adicionado com sucesso!\n");
        return refrigerantes;
    }
}

Refrigerante *reabastecerEstoque(Refrigerante *refrigerantes, int *n)
{
    int escolha, quantidade;
    printf("\nReabastecer Estoque\n");
    exibirRefrigerantes(refrigerantes, *n);
    printf("\nDigite o número do refrigerante que deseja reabastecer (1-%d): ", *n);
    scanf("%d", &escolha);
    if (escolha < 1 || escolha > *n)
    {
        printf("\nOpção inválida\n");
        return refrigerantes;
    }
    printf("Digite a quantidade a ser adicionada ao estoque de %s: ", refrigerantes[escolha - 1].nome);
    scanf("%d", &quantidade);
    if (quantidade < 0)
    {
        printf("\nQuantidade inválida\n");
        return refrigerantes;
    }
    refrigerantes[escolha - 1].quantidade_estoque += quantidade;
    printf("\nEstoque de %s atualizado para %d unidades.\n", refrigerantes[escolha - 1].nome, refrigerantes[escolha - 1].quantidade_estoque);
    return refrigerantes;
}
