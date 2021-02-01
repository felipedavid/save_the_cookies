#include <stdio.h>
#include <string.h>

#include "objeto.h"
#include "utils.h"

void moverObjeto(char *substantivo, objeto_t *locAtual, objeto_t *destino) {
    objeto_t *objeto = procurarObjeto(substantivo);
    if (objeto == NULL) {
        printf("Objeto não encontrado.\n");
    } else if (locAtual != objeto->localizacao) {
        printf("Você não pode fazer isso.\n");
    } else if (destino == NULL) {
        printf("Item não pode ser entregue a 'NULL'.\n");
    } else {
        objeto->localizacao = destino;
    }
}

void darItem(char *subs) {
    printf(">>> Não implementado <<<\n");
}

void pegarItem(char *subs) {
    // implementar alguns checks pra o jogador não poder colocar npcs e 
    // monstros no inventário.
    moverObjeto(subs, jogador->localizacao, jogador);
}

void largarItem(char *subs) {
    moverObjeto(subs, jogador, jogador->localizacao);
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

    int nItems = 0;
    for (objeto_t *obj_p = objetos; obj_p != finalDoArray; obj_p++) {
        if (obj_p->localizacao == jogador) {
            nItems++;
            printf("///\t\t\t\t[%d] %s", nItems, obj_p->nome);

            // alinhar a borda do quadro
            int nEspacos = 38 - strlen(obj_p->nome);
            for (int j = 0; j < nEspacos; j++) {
                printf(" ");
            }
            printf("///\n");
        }
    }
    if (nItems == 0) {
        printf("///                        INVENTARIO VAZIO                               ///\n");
    }

    printf("///                                                                       ///\n"
        "/////////////////////////////////////////////////////////////////////////////\n\n");
}
