/* Essa implementação não segue as práticas comuns de segurança/legibilidade então 
   pode esperar alguns buffers overflows e double free hahaha xD */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "ranking.h"

void free_ranking(ranking_t *ranking) {
    if (ranking == NULL || ranking->head == NULL) return;

    jogador_t *current, *tmp; 
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp->nome);
        free(tmp);
    }
    free(ranking);
}

ranking_t *criar_ranking(void)  {
    ranking_t *ranking = malloc(sizeof(ranking_t));
    if (ranking == NULL)
        return NULL;

    ranking->head = NULL;
    return ranking;
}

bool inserir_jogador(ranking_t *ranking, char *nome, int pontos) {
    if (ranking == NULL) return false;

    jogador_t *jogador = malloc(sizeof(jogador_t));
    if (jogador == NULL) return false;

    char *nome_jogador = (char *) malloc(strlen(nome) + 1);
    if (nome_jogador == NULL) return false;
    strcpy(nome_jogador, nome);
    jogador->nome = nome_jogador;
    jogador->pontos = pontos;

    if (ranking->head == NULL) {
        ranking->head = jogador;
        jogador->next = NULL;
    } else {
        jogador_t *current = ranking->head;
        while (current->next != NULL && current->next->pontos > jogador->pontos) {
            current = current->next;
        }
        jogador->next = current->next;
        current->next = jogador;
    }
    return true;
}

void mostrar_ranking(ranking_t *ranking) {
    printf("\t>>> Funcionalidade ainda não implementada <<<\n");
    printf("\tDigite 'ajuda' para ver os comandos disponíveis.\n");
    return;
}
