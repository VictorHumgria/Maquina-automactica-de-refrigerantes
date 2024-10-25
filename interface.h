#include "refrigerante.h"
#ifndef INTERFACE_H
#define INTERFACE_H

#define LARGURA 60

void desenharBorda(char c);
void desenharTitulo(char *titulo);
void desenharLinha(char *esquerda, char *direita);
void exibirMenu();
void exibirRefrigerantesGraficos(Refrigerante refrigerantes[], int n);
void exibirRefrigerantes(Refrigerante refrigerantes[], int n);

#endif
