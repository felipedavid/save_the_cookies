#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool get_input(void);
bool parse_input(char *input);
void print_info(void);

static char player_input[256];

int main(void) {
    // game loop
    // get input -> parse it and execute -> repeat
    while (true) {
        if (parse_input(player_input) && get_input())
            break;
    }

    return EXIT_SUCCESS;
}

static bool get_input(void) {
    // TODO
    return true;
}

bool parse_input(char *input) {
    // TODO
    return true;
}
