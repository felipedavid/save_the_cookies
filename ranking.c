#include <stdio.h>
#include <stdlib.h>

#include "ranking.h"
#include "comandos.h"

// TODO: Implementar 'rankingJogadores' como uma linked list
JOGADOR ranking_jogadores[] = {
    {"Felipe David", "asdkjfaskdjf@gmail.com", 40, {17,2,2001}, NULL},
    {"asfdkj ajsdfkj", "sadfkljasdfj@gmail.com", 30, {2,5,2000}, NULL},
};

// 3/15
void cadastrar_ranking(void) {
    char nome[256], email[256], c;
    int dia, mes, ano;

    printf("Deseja fazer cadastro? [S/n] ");
    if ((c = getchar()) == 'n' || c == 'N') {
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", nome);

    printf("Email: ");
    scanf(" %s", email);

    printf("Data de nascimento (dd/mm/aaaa): ");
    scanf(" %d/%d/%d", &dia, &mes, &ano);

    getchar();
    getchar();
}

void mostrar_ranking(void) {
    JOGADOR *jogador = NULL;
    int i = 1;
    for (jogador = ranking_jogadores; jogador != fim_jogadores; jogador++) {
        printf("%d°) %s\t%d pontos.\n", i, jogador->nome, jogador->pontos);
        i++;
    }
}
