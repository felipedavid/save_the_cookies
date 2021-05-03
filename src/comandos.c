#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "ranking.h"
#include "comandos.h"
#include "objeto.h"
#include "validacao.h"
#include "paineis.h"
#include "inventario.h"
#include "utils.h"
#include "jogador.h"

void clear(void) {
#if defined _WIN32 || defined _WIN64
    system("cls");
#else
    system("clear");
#endif
}

void info(void) {
    puts(painel_info);
}

void ajuda(void) {
    puts(painel_ajuda);
}

void olhar(char *substantivo) {
    if (substantivo != NULL && (!strcmp(substantivo, "redor") || 
                                !strcmp(substantivo, "volta"))  ) {
        printf("Você está em %s.\n\n", jogador->localizacao->info);
        objetos_em_localizacao(jogador->localizacao);
    } else {
        objeto_t *obj_p = campo_de_visao("oque você quer ver?", substantivo);
        distancia_t distancia = checar_distancia(jogador, obj_p);
        if (distancia == distancia_mao_jogador) {
            printf("Muito longe.\n");
        } else if (distancia == distancia_proximo_a_jogador) {
            printf("Muito longe.\n");
        } else if (distancia == distancia_diferente_jogador) {
            printf("Você não vê '%s'.\n", substantivo);
        } else if (distancia == distancia_indefinida) {
            printf("Não entendo.\n");
        } else {
            printf("%s\n", obj_p->info2);
        }
    }
}

void ir(char *substantivo) {
    objeto_t *objeto = campo_de_visao("pra onde você quer ir", substantivo);

    switch (checar_distancia(jogador, objeto)) {
        case distancia_proximo_a_jogador:
            mover_jogador(checar_passagem(jogador->localizacao, objeto));
            break;
        case distancia_diferente_jogador:
            printf("Você não vê nenhum '%s'.\n", substantivo);
            break;
        default:
            mover_jogador(objeto);
    }
}










/*******************************/
/* IMPROVISAÇÂO DE ÚLTIMA HORA */
/*******************************/

void atacar(char *substantivo) {
    objeto_t *mob = achar_mob(substantivo);
    if (!mob) return;

    if (!(mob->visivel)) return;

    if (bengala->localizacao != jogador) {
        printf("Você não tem nenhuma arma.\n");
        return;
    }

    mob->vida -= jogador->ataque;
    jogador->vida -= esqueleto->ataque;

    printf("Você inferiu %d de dano ao %s. %s tem %d de vida restante\n", 
        jogador->ataque, mob->nome, mob->nome, mob->vida);
    printf("Você recebeu %d de dano. Você tem %d de vida restante\n", 
        esqueleto->ataque, jogador->vida);

    if (mob->vida <= 0) {
        printf("Você derrotou '%s'\n", mob->nome);
        printf("Você ganhou '%s'.\n", espada->info);
        espada->localizacao = jogador;
        mob->vida = 0;
        mob->visivel = false;
        jogador->ataque += espada->ataque;
    }
}

void finalizar_borda_status(int str_len, int n) {
    static const char *borda = "///";
    int space = 47;
    while ((n /= 10) > 0) {
        space--;
    }
    for (int i = 0; i < (space-str_len); i++) {
        printf(" ");
    }
    puts(borda);
}

void status() {
    static const char *jogador_vida       = "///     Vida: %d";
    static const char *jogador_ataque     = "///     Pontos de ataque: %d";
    static const char *jogador_capacidade = "///     Capacidade inv.: %d";

    int jogador_vida_len       = strlen(jogador_vida);
    int jogador_ataque_len     = strlen(jogador_ataque);
    int jogador_capacidade_len = strlen(jogador_capacidade);

    puts(painel_status_top);
    printf(jogador_vida, jogador->vida);   
    finalizar_borda_status(jogador_vida_len, jogador->vida);
    printf(jogador_ataque, jogador->ataque); 
    finalizar_borda_status(jogador_ataque_len, jogador->ataque);
    printf(jogador_capacidade, jogador->espaco); 
    finalizar_borda_status(jogador_capacidade_len, jogador->espaco);
    puts(painel_status_bottom);
}

void usar(char *substantivo) {
    objeto_t *biscoito_ptr = achar_mob(substantivo);
    if (biscoito == biscoito_ptr && biscoito->localizacao == jogador) {
        biscoito->visivel = false;
        jogador->vida = 100;
        printf("Você consumiu biscoito, sua vida foi restaurada.\n");
    } else {
        printf("Você não pode usar esse item.\n");
    }
}

void salvar() {
    FILE *save_file = fopen("savefile.dat", "w");
    if (!save_file) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    fwrite(objetos, sizeof(objeto_t)*17, 1, save_file);
    fclose(save_file);
}

void load() {
    FILE *save_file = fopen("savefile.dat", "r");
    if (!save_file) {
        printf("Não foi possível abrir o arquivo.\n");
        return;
    }

    fread(objetos, sizeof(objeto_t)*17, 1, save_file);
    fclose(save_file);
}
