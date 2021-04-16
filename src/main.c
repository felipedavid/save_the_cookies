#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "ranking.h"
#include "entrada.h"

int main(void) {

    ranking_t *ranking = criar_ranking();
    load_ranking(ranking);

    char entrada[256] = "info";
    while (executar_entrada(entrada, ranking) &&
           obter_entrada(entrada, sizeof(entrada)));

    salvar_ranking(ranking);
    free_ranking(ranking);

    return EXIT_SUCCESS;
}
