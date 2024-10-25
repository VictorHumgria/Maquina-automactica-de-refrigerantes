#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H

#include "refrigerante.h"

void salvarEstoque(Refrigerante *refrigerantes, int n, const char *filename);
Refrigerante* carregarEstoque(int *n, const char *filename);

#endif
