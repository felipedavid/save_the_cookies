#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "ranking.h"
#include "validacao.h"
#include "paineis.h"

ranking_t *criar_ranking(void)  {
    ranking_t *ranking = malloc(sizeof(ranking_t));
    if (ranking == NULL)
        return NULL;

    ranking->head = NULL;
    return ranking;
}

void free_ranking(ranking_t *ranking) {
    if (ranking == NULL || ranking->head == NULL) return;

    jogador_t *tmp, *current = ranking->head; 
    while (current != NULL) {
        tmp = current;
        current = current->next;
        free(tmp);
    }
    free(ranking);
    ranking = NULL;
}

bool inserir_jogador_em_ranking(ranking_t *ranking, char *nome, int pontos) {
    if (ranking == NULL) return false;

    jogador_t *jogador = malloc(sizeof(jogador_t));
    if (jogador == NULL) return false;

    strncpy(jogador->nome, nome, 256);
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
    puts(painel_ranking_top);
    if (ranking == NULL || ranking->head == NULL) {
        puts(painel_ranking_mid_vazio);
        puts(painel_ranking_bottom);
        return;
    }

    int n_jogadores = 0;
    jogador_t *current = ranking->head;
    while (current != NULL) {
        printf("///\t\t[%d] %s %d", ++n_jogadores, current->nome, current->pontos);
        // alinhar a borda do quadro
        int n_espacos = 24 - strlen(current->nome);
        for (int j = 0; j < n_espacos; j++) {
            printf(" ");
        }
        printf("///\n");

        current = current->next;
    }
    if (n_jogadores == 0) {
    }

    puts(painel_ranking_bottom);
}

// Grava todas as estruturas jogador_t no arquivo 'ranking.dat' sobeescrevendo
// as anteriores, 'lixo' como ponteiros também são gravados e ignorados depois
bool salvar_ranking(ranking_t *ranking) {
    FILE *fp = fopen("ranking.dat", "w");
    if (!fp) return false;

    jogador_t *current = ranking->head;
    while (current != NULL) {
        fwrite(current, sizeof(jogador_t), 1, fp);
        current = current->next;
    }

    fclose(fp);
    return true;
}

// Lê todas as estruturas jogador_t do arquivo e reconstroi a lista, são apenas
// 10-20 elementos então não deve ter problema
bool load_ranking(ranking_t* ranking) {
    FILE *fp = fopen("ranking.dat", "r");
    if (!fp) return false;
    
    jogador_t jogador;

    while (fread(&jogador, sizeof(jogador_t), 1, fp)) {
        inserir_jogador_em_ranking(ranking, jogador.nome, jogador.pontos);
    }

    fclose(fp);
    return true;
}

// Pra testar a parte de manipulação de arquivos:
// 1º Adicionar alguns jogadores em ranking com o comando ">>> add ranking".
// 2º Sair do game usando 'sair' (ranking é salvo ao sair do game loop)
// 3º Entrar novamente no game e digitar ">>> ranking" (Se existir
//    um arquivo 'ranking.dat' ele será carregado no início). 
void prompt_inserir_jogador(ranking_t *ranking, char *substantivo) {
    if (!substantivo) return;

    if (strcmp(substantivo, "rank") && strcmp(substantivo, "ranking")) {
        printf("Ranking não criado.\n Tente '>>> ranking add'.\n"); 
        return;
    }

    char email[256];
    while(true) {
        printf("Email: ");
        fgets(email, 256, stdin);
        email[strcspn(email, "\n")] = 0;

        if (email_valido(email)) {
            break;
        } else {
            printf("Insira um email válido.\n\n"); 
        }
    }

    char nome[256];
    while (true) {
        printf("Nome: ");
        fgets(nome, 256, stdin);
        nome[strcspn(nome, "\n")] = 0;

        if (nome_valido(nome)) {
            break;
        } else {
            printf("Insira um nome válido.\n\n");
        }
    }

    inserir_jogador_em_ranking(ranking, nome, 0);
    printf("Jogador adicionado.");
}
