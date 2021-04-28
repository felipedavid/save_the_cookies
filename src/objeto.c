#include <stdio.h>
#include <string.h>

#include "objeto.h"

objeto_t objetos[] = {
    {"sua avó",               "vovo",     casa,     NULL},
    {"bengala de sua avó",    "bengala",  casa,     NULL},
    {"você",                  "jogador",  casa,     NULL},

    {"floresta",              "floresta", NULL,     NULL},

    {"casa da sua vovó",      "casa",     NULL,     NULL},
    {"saída da casa",         "saida",    casa,     floresta},
    {"entrada da casa",       "entrada",  floresta, casa},

    {"seu quarto",            "quarto",   NULL,     NULL},
    {"saída do seu quarto",   "saida",    quarto,   casa},
    {"entrada do seu quarto", "entrada",  casa,     quarto},

    {"caverna",               "caverna",   NULL,     NULL},
    {"saída da caverna",      "saida",     caverna,  floresta},
    {"entrada da caverna",    "entrada",   floresta, caverna},
};

int objetos_em_localizacao(objeto_t *localizacao) {
    int n_objetos = 0;
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p->localizacao == localizacao && obj_p != jogador) {
            if (n_objetos == 0) {
                printf("Você encherga:\n");
            }
            n_objetos++;
            printf("%s\n", obj_p->info);
        }
    }
    return n_objetos;;
}
