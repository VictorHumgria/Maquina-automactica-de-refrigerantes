#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persistencia.h"
#include "cJSON.h"

void salvarEstoque(Refrigerante *refrigerantes, int n, const char *filename) {
    cJSON *jsonArray = cJSON_CreateArray();

    for (int i = 0; i < n; i++) {
        cJSON *jsonRefrigerante = cJSON_CreateObject();
        cJSON_AddStringToObject(jsonRefrigerante, "nome", refrigerantes[i].nome);
        cJSON_AddNumberToObject(jsonRefrigerante, "preco", refrigerantes[i].preco);
        cJSON_AddNumberToObject(jsonRefrigerante, "quantidade_estoque", refrigerantes[i].quantidade_estoque);
        cJSON_AddItemToArray(jsonArray, jsonRefrigerante);
    }

    char *jsonString = cJSON_Print(jsonArray);
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s", jsonString);
        fclose(file);
    }

    cJSON_Delete(jsonArray);
    free(jsonString);
}

Refrigerante* carregarEstoque(int *n, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = malloc(length + 1);
    fread(data, 1, length, file);
    fclose(file);
    data[length] = '\0';

    cJSON *jsonArray = cJSON_Parse(data);
    free(data);

    if (!cJSON_IsArray(jsonArray)) {
        cJSON_Delete(jsonArray);
        return NULL;
    }

    *n = cJSON_GetArraySize(jsonArray);
    Refrigerante *refrigerantes = malloc(*n * sizeof(Refrigerante));

    for (int i = 0; i < *n; i++) {
        cJSON *jsonRefrigerante = cJSON_GetArrayItem(jsonArray, i);
        strcpy(refrigerantes[i].nome, cJSON_GetObjectItem(jsonRefrigerante, "nome")->valuestring);
        refrigerantes[i].preco = (float)cJSON_GetObjectItem(jsonRefrigerante, "preco")->valuedouble;
        refrigerantes[i].quantidade_estoque = cJSON_GetObjectItem(jsonRefrigerante, "quantidade_estoque")->valueint;
    }

    cJSON_Delete(jsonArray);
    return refrigerantes;
}
