#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void print_project_info(void);
static bool get_input(void);
bool parse_input(char *input);

static char player_input[256] = "exit";

int main(void) {
    print_project_info();

    // game loop
    // get input -> parse it and execute -> repeat
    while (true) {
        if (parse_input(player_input) && get_input())
            break;
    }

    return EXIT_SUCCESS;
}

void print_project_info(void) {
    puts("/////////////////////////////////////////////////////////////////////////////\n"
    "///                                                                       ///\n"
    "///              Universidade Federal do Rio Grande do Norte              ///\n"
    "///                  Centro de Ensino Superior do Seridó                  ///\n"
    "///                Departamento de Computação e Tecnologia                ///\n"
    "///                   Disciplina DCT1106 -- Programação                   ///\n"
    "///                 Developed by  @felipedavid - Jan, 2021                ///\n"
    "///                                                                       ///\n"
    "/////////////////////////////////////////////////////////////////////////////\n"
    "///                                                                       ///\n"
    "///          ===================================================          ///\n"
    "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
    "///          = = = =           Save The Cookies          = = = =          ///\n"
    "///          = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n"
    "///          ===================================================          ///\n"
    "///                                                                       ///\n"
    "/// Um simples text-based rpg game para demonstar as principais           ///\n"
    "/// funcionalidades dos clássicos rpgs de texto famosos nos anos 70. A    ///\n"
    "/// premissa do game é bem simples, monstros atacaram o seu vilareijo     ///\n"
    "/// durante a noite e acabaram roubando todo o seu estoque de alimentos,  ///\n"
    "/// entre os alimentos roubados estavam os biscoitos que sua vovó fez     ///\n"
    "/// para você. Seu objetivo é atacar o labirinto de onde esses monstros   ///\n"
    "/// saíram e tentar recuperar o máximo de biscoitos possível.             ///\n"
    "///                                                                       ///\n"
    "/////////////////////////////////////////////////////////////////////////////\n\n"
    "\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

static bool get_input(void) {
    // TODO
    return true;
}

bool parse_input(char *input) {
    // TODO
    return true;
}
