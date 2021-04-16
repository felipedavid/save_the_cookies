#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "objeto.h"
#include "utils.h"
#include "comandos.h"
#include "inventario.h"
#include "parser.h"
#include "ranking.h"

bool obter_entrada(char *entrada, size_t tamanho_entrada) {
    printf("\n>>> ");
    return fgets(entrada, tamanho_entrada, stdin);
}

bool executar_entrada(char *entrada, ranking_t *ranking) {
    char *verbo = parse_verbo(entrada);
    char *substantivo = parse_substantivo(entrada);

    if (!strlen(verbo)) return true;

    if (!strcmp(verbo, "sair")) {
        return false;
    } else if (!strcmp(verbo, "info")) {
        info();
    } else if (!strcmp(verbo, "ajuda")) {
        ajuda();
    } else if (!strcmp(verbo, "olhar")) {
        olhar(substantivo);
    } else if (!strcmp(verbo, "clear")) {
        clear();
    } else if (!strcmp(verbo, "inventario")) {
        abrir_inventario();
    } else if (!strcmp(verbo, "ir")) {
        ir(substantivo);
    } else if (!strcmp(verbo, "pegar")) {
        pegar_item(substantivo);
    } else if (!strcmp(verbo, "dar")) {
        dar_item(substantivo);
    } else if (!strcmp(verbo, "largar")) {
        largar_item(substantivo);
    } else if (!strcmp(verbo, "add")) {
        prompt_inserir_jogador(ranking, substantivo);
    } else if (!strcmp(verbo, "ranking")) {
        mostrar_ranking(ranking);
    } else {
        printf("Comando '%s' não existe.\n", verbo);
        printf("Digite 'ajuda' para ver os comandos válidos.\n");
    }

    free(verbo);
    free(substantivo);

    return true;
}
