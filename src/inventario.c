#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "objeto.h"
#include "utils.h"
#include "paineis.h"

void abrir_inventario(void) {
    puts(painel_inventario_top);

    int n_items = 0;
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (obj_p->localizacao == jogador && obj_p->visivel) {
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
        puts(painel_inventario_mid_vazio);
    }
    
    puts(painel_inventario_bottom);
}

bool objeto_tem_nome(objeto_t *objeto, char *substantivo) {
    if (substantivo != NULL && *substantivo != '\0' && 
        !strcmp(substantivo, objeto->nome)) {
        return true;
    }
    return false;
}

objeto_t *procurar_objeto(char *substantivo, objeto_t *origem, distancia_t distt) {
    objeto_t *obj_ptr, *objeto_encontrado = NULL;
    for (obj_ptr = objetos; obj_ptr < final_array; obj_ptr++) {
        if (objeto_tem_nome(obj_ptr, substantivo) && checar_distancia(origem, obj_ptr) <= distt) {
            objeto_encontrado = obj_ptr;
        }
    }
    return objeto_encontrado;
}

objeto_t *campo_de_visao(char *proposito, char *substantivo) {
    objeto_t *obj_ptr = procurar_objeto(substantivo, jogador, distancia_proximo_a_jogador);
    if (!obj_ptr) {
        if (procurar_objeto(substantivo, jogador, distancia_diferente_jogador) == NULL) {
            printf("eu não entendo '%s'.\n", proposito);
        } else {
            printf("Você não vê nenhum '%s'.\n", substantivo);
        }
    }
    return obj_ptr;;
}

void mover_objeto(objeto_t *objeto, objeto_t *destino) {
    if (objeto == vovo) return;

    if (objeto == NULL) {
        printf("Objeto não encontrado.\n");
    } else if (objeto->localizacao == NULL) {
        printf("Vocês não pode fazer isso.\n");
    } else if (destino == NULL) {
        printf("Você não pode fazer isso.\n");
    } else if (destino == NULL) {
        printf("Item não pode ser entregue a 'NULL'.\n");
    //} else if (objeto->peso > destino->espaco) {
    //    printf("Muito pesado.");
    } else {
        if (destino == jogador->localizacao) {
            printf("Você jogou fora o item: %s.\n", objeto->nome);
        } else if (destino != jogador) {
            if (destino == vovo) {
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

objeto_t *procurar_inventario(objeto_t *loc_atual, char *verbo, char *substantivo) {
    objeto_t *obj_ptr = NULL;
    if (!loc_atual) {
    } else if (!(obj_ptr = procurar_objeto(substantivo, loc_atual, distancia_inventario))) {
        if (!procurar_objeto(substantivo, jogador, distancia_diferente_jogador)) {
            printf("Não entendo '%s'.\n", verbo);
        } else if (loc_atual == jogador) {
            printf("Você não está segurando '%s'.\n", substantivo);
        } else {
            printf("Você não pode pegar '%s' de '%s'.\n", substantivo, loc_atual->info);
        }
    } else if (obj_ptr == loc_atual) {
        printf("Você não pode fazer isso com'%s'.\n", obj_ptr->info);
    }
    return obj_ptr;
}

void dar_item(char *subs) {
    mover_objeto(procurar_inventario(jogador, "dar", subs), testar_NPC());
}

void pedir_item(char *subs) {
    mover_objeto(procurar_inventario(testar_NPC(), "pedir", subs), jogador);
}

void largar_item(char *subs) {
    mover_objeto(procurar_inventario(jogador, "largar", subs), jogador->localizacao);
}

void pegar_item(char *subs) {
    objeto_t *objeto = campo_de_visao("oque você quer pegar", subs);
    switch (checar_distancia(jogador, objeto)) {
        case distancia_jogador:
            printf("Você não pode fazer isso.\n");
            break;
        case distancia_no_jogador:
            printf("Você ja tem %s.\n", objeto->info);
            break;
        case distancia_proximo_a_jogador:
            printf("O item está muito longe.\n");
            break;
        default:
            if (objeto->localizacao == vovo) {
                printf("Você não pode pegar %s.\n", objeto->localizacao->info);
            } else {
                mover_objeto(objeto, jogador);
                jogador->ataque += objeto->ataque;
            }
    }
}

int peso_inventario(objeto_t *inventario) {
    int peso = 0;
    for (objeto_t *obj_p = objetos; obj_p != final_array; obj_p++) {
        if (esta_segurando(inventario, obj_p)) {
            peso = peso + obj_p->peso;
        }
    }
    return peso;
}
