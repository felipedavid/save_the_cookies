#include <stdio.h>
#include "objeto.h"
#include "comandos.h"

void mover_jogador(objeto_t* caminho) {
    if (!caminho) return;
    if (!(caminho->destino)) return;
    printf("%s\n", caminho->info4);
    jogador->localizacao = caminho->destino;
    olhar("redor");
}
