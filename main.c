#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//#include "objeto.h"

void menu_sobre(void);
static bool obter_entrada(void);
bool analisar_entrada(char *entrada);
bool executar_comando(char *verbo, char *substantivo);

static char entrada[256] = "info";

int main(void) {
    menu_sobre(); // <- Só pra comprir os requisitos da 1/15 (vai printar o
                  // menu duas vezes pela forma que decidi fazer as coisas)

    // game loop
    // pegar entrada do usuário -> procurar por comandos válidos -> executar
    // comand se válido -> repetir 
    while (analisar_entrada(entrada) && obter_entrada());

    return EXIT_SUCCESS;
}

void menu_sobre(void) {
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
        "\t\t\t>>> Digite 'info' para mostrar informações do game...\n"
        "\t\t\t>>> Digite 'sair' para fechar o game...\n");
}

static bool obter_entrada(void) {
    printf(">>> ");
    char *tanto_faz = fgets(entrada, sizeof entrada, stdin);

    if (tanto_faz == NULL)
        return false;
    return true;
}

bool analisar_entrada(char *entrada) {
    char *verbo = strtok(entrada, " \n");
    if (verbo == NULL)
        return false;

    return executar_comando(verbo, NULL);
}

bool executar_comando(char *verbo, char *substantivo) {
    if (!strcmp(verbo, "sair"))
        return false;
    else if (!strcmp(verbo, "info"))
        menu_sobre();
    else 
        printf("Comando %s não existe.", verbo);

    return true;
}
