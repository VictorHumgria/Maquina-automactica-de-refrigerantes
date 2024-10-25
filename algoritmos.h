#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "refrigerante.h"

void calculaTrocoGuloso(float moedas[], int n, float troco);
int calculaTrocoDP(float moedas[], int n, float troco);
void encontrarCombinacao(Refrigerante refrigerantes[], int n, float valor_alvo, int idx, float soma_atual, int *solucao);
void escolherRefrigeranteBacktracking(Refrigerante refrigerantes[], int n);

#endif // ALGORITMOS_H
