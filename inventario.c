#include <stdio.h>
#include <string.h>

#include "objeto.h"
#include "utils.h"

void abrirInventario(void) {
    printf("/////////////////////////////////////////////////\n"
        "///                                           ///\n"
        "///    ===================================    ///\n"
        "///    = = = =    Seu Inventario   = = = =    ///\n"
        "///    ===================================    ///\n"
        "///                                           ///\n");

    int nItems = 0;
    for (objeto_t *obj_p = objetos; obj_p != finalDoArray; obj_p++) {
        if (obj_p->localizacao == jogador) {
            nItems++;
            printf("///\t\t[%d] %s", nItems, obj_p->nome);

            // alinhar a borda do quadro
            int nEspacos = 26 - strlen(obj_p->nome);
            for (int j = 0; j < nEspacos; j++) {
                printf(" ");
            }
            printf("///\n");
        }
    }
    if (nItems == 0) {
        printf("///             INVENTARIO VAZIO              ///\n");
    }

    printf("///                                           ///\n"
        "/////////////////////////////////////////////////\n\n");
}

void moverObjeto(objeto_t *objeto, objeto_t *destino) {
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

objeto_t *pegarObItem(char *verbo, char *substantivo, objeto_t *locAtual) {
    objeto_t *objeto = procurarObjeto(substantivo);
    if (locAtual == NULL) {
        printf("Oque você quer \"%s\"?\n", verbo);
    } else if (objeto == NULL) {
        printf("Oque você quer \"%s\"?\n", verbo);
    } else if (objeto == locAtual) {
        objeto = NULL;
        printf("Você não pode fazer isso.\n");
    } else if (objeto->localizacao != locAtual) {
        if (locAtual == jogador) {
            printf("Você não está com \"%s\".\n", substantivo);
        } else {
            printf("Você não pode pegar \"%s\" de \"%s\".\n", substantivo,
                    locAtual->nome);
        }
        objeto = NULL;
    }
    return objeto;
}

void darItem(char *subs) {
    printf(">>> Não implementado <<<\n");
}

void pegarItem(char *subs) {
    objeto_t *objeto = procurarObjeto(subs);
    if (objeto == jogador) {
        printf("Comando não permitido.\n");
    } else if (objeto->localizacao == jogador) {
        printf("O objeto \"%s\" já está no seu inventário.\n", objeto->nome);
    } else if (objeto == vizinho) {
        printf("Você não pode guardar \"%s\" no seu inventário.\n", objeto->nome);
    } else {
        moverObjeto(objeto, jogador);
    }
}

void largarItem(char *subs) {
    moverObjeto(jogador, jogador->localizacao);
}
