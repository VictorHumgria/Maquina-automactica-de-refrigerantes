#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include "refrigerante.h"

void efetuarPagamento(Refrigerante refrigerantes[], int escolha, float moedas[], int tamanho_moedas);
void efetuarCompra(Refrigerante refrigerantes[], int n, float moedas[], int tamanho_moedas);

#endif // PAGAMENTO_H
