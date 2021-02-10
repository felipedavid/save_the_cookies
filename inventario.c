#include <stdio.h>
#include <string.h>

#include "objeto.h"
#include "utils.h"

void abrir_inventario(void) {
    printf("/////////////////////////////////////////////////\n"
        "///                                           ///\n"
        "///    ===================================    ///\n"
        "///    = = = =    Seu Inventario   = = = =    ///\n"
        "///    ===================================    ///\n"
        "///                                           ///\n");

    int n_items = 0;
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p->localizacao == jogador) {
            n_items++;
            printf("///\t\t[%d] %s", n_items, obj_p->nome);

            // alinhar a borda do quadro
            int n_espacos = 26 - strlen(obj_p->nome);
            for (int j = 0; j < n_espacos; j++) {
                printf(" ");
            }
            printf("///\n");
        }
    }
    if (n_items == 0) {
        printf("///             INVENTARIO VAZIO              ///\n");
    }

    printf("///                                           ///\n"
        "/////////////////////////////////////////////////\n\n");
}

void mover_objeto(objeto_t *objeto, objeto_t *destino) {
    if (objeto == NULL) {
        printf("Objeto não encontrado.\n");
    } else if (objeto->localizacao == NULL) {
        printf("Vocês não pode fazer isso.\n");
    } else if (destino == NULL) {
        printf("Você não pode fazer isso.\n");
    } else if (destino == NULL) {
        printf("Item não pode ser entregue a 'NULL'.\n");
    } else {
        if (destino == jogador->localizacao) {
            printf("Você jogou fora o item: %s.\n", objeto->nome);
        } else if (destino != jogador) {
            if (destino == vizinho) {
                printf("Você deu o item \"%s\" para %s.\n", objeto->nome,
                        destino->nome);
            } else {
                printf("Você colocou o item \"%s\" no(a) %s.\n", objeto->nome,
                        destino->nome);
            }
        } else if (objeto->localizacao == jogador->localizacao) {
            printf("Você pegou o item: %s.\n", objeto->nome);
        } else {
            printf("Você pegou o item \"%s\" de \"%s\".\n", objeto->nome,
                    objeto->localizacao->info);
        }
        objeto->localizacao = destino;
    }
}

objeto_t *pegar_ob_item(char *verbo, char *substantivo, objeto_t *loc_atual) {
    objeto_t *objeto = procurar_objeto(substantivo);
    if (loc_atual == NULL) {
        printf("Oque você quer \"%s\"?\n", verbo);
    } else if (objeto == NULL) {
        printf("Oque você quer \"%s\"?\n", verbo);
    } else if (objeto == loc_atual) {
        objeto = NULL;
        printf("Você não pode fazer isso.\n");
    } else if (objeto->localizacao != loc_atual) {
        if (loc_atual == jogador) {
            printf("Você não está com \"%s\".\n", substantivo);
        } else {
            printf("Você não pode pegar \"%s\" de \"%s\".\n", substantivo,
                    loc_atual->nome);
        }
        objeto = NULL;
    }
    return objeto;
}

void dar_item(char *subs) {
    printf(">>> Não implementado <<<\n");
}

void pegar_item(char *subs) {
    objeto_t *objeto = procurar_objeto(subs);
    if (objeto == jogador) {
        printf("Comando não permitido.\n");
    } else if (objeto->localizacao == jogador) {
        printf("O objeto \"%s\" já está no seu inventário.\n", objeto->nome);
    } else if (objeto == vizinho) {
        printf("Você não pode guardar \"%s\" no seu inventário.\n", objeto->nome);
    } else {
        mover_objeto(objeto, jogador);
    }
}

void largar_item(char *subs) {
    mover_objeto(jogador, jogador->localizacao);
}
