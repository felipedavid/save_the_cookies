#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "entrada.h"

int main(void) {
    char entrada[256] = "info";
    while (executar_entrada(entrada) && obter_entrada(entrada, sizeof(entrada)));

    return EXIT_SUCCESS;
}
