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

objeto_t *procurar_objeto(char *substantivo) {
    objeto_t *obj_ptr, *objeto_encontrado = NULL;
    for (obj_ptr = objetos; obj_ptr < final_array; obj_ptr++) {
        if (objeto_tem_nome(obj_ptr, substantivo)) {
            objeto_encontrado = obj_ptr;
        }
    }
    return objeto_encontrado;
}

objeto_t *campo_de_visao(char *proposito, char *substantivo) {
    objeto_t *obj_ptr = procurar_objeto(substantivo);
    if (obj_ptr == NULL) {
        printf("Eu não entendo %s.\n", proposito);
    } else if (!(obj_ptr == jogador ||
               obj_ptr == jogador->localizacao ||
               obj_ptr->localizacao == jogador ||
               obj_ptr->localizacao == jogador->localizacao ||
               checar_passagem(jogador->localizacao, obj_ptr) != NULL ||
               (obj_ptr->localizacao != NULL && 
               (obj_ptr->localizacao->localizacao == jogador ||
                obj_ptr->localizacao->localizacao == jogador->localizacao)))) {
        printf("Você não vê nenhum '%s'.\n", substantivo);
        obj_ptr = NULL;
    }
    return obj_ptr;;
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
    if (objeto == NULL) {
    } else if (objeto == jogador) {
        printf("Comando não permitido.\n");
    } else if (objeto->localizacao == jogador) {
        printf("O objeto \"%s\" já está no seu inventário.\n", objeto->nome);
    } else if (objeto == vovo) {
        printf("Você não pode guardar \"%s\" no seu inventário.\n", objeto->nome);
    } else {
        mover_objeto(objeto, jogador);
    }
}
