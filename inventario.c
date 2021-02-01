#include <stdio.h>
#include <string.h>

#include "objeto.h"
#include "utils.h"

void mover_objeto(char *substantivo, objeto_t *loc_atual, objeto_t *dst) {
    objeto_t *objeto = procurar_objeto(substantivo);
    if (objeto == NULL) {
        printf("Objeto não encontrado.\n");
    } else if (loc_atual != objeto->localizacao) {
        printf("Você não pode fazer isso.\n");
    } else if (dst == NULL) {
        printf("Item não pode ser entregue a 'NULL'.\n");
    } else {
        objeto->localizacao = dst;
    }
}

void dar_item(char *subs) {
    printf(">>> Não implementado <<<\n");
}

void pegar_item(char *subs) {
    // implementar alguns checks pra o jogador não poder colocar npcs e 
    // monstros no inventário.
    mover_objeto(subs, jogador->localizacao, jogador);
}

void largar_item(char *subs) {
    mover_objeto(subs, jogador, jogador->localizacao);
}

void inventario(void) {
    printf("/////////////////////////////////////////////////////////////////////////////\n"
        "///                                                                       ///\n"
        "///          ===================================================          ///\n"
        "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
        "///          = = = =            Seu Inventario           = = = =          ///\n"
        "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
        "///          ===================================================          ///\n"
        "///                                                                       ///\n");

    unsigned char item_counter = 0;
    for (objeto_t *obj_p = objetos; obj_p != final_do_array ; obj_p++) {
        if (obj_p->localizacao == jogador) {
            item_counter++;
            printf("///\t\t\t\t[%d] %s", item_counter, obj_p->nome);

            // alinhar a borda do quadro
            int n_espacos = 38 - strlen(obj_p->nome);
            for (int j = 0; j < n_espacos; j++) {
                printf(" ");
            }
            printf("///\n");
        }
    }
    if (item_counter == 0) {
        printf("///                        INVENTARIO VAZIO                               ///\n");
    }

    printf("///                                                                       ///\n"
        "/////////////////////////////////////////////////////////////////////////////\n\n");
}
