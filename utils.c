#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

void menu_sobre(void) {
    #if defined _WIN32 || defined _WIN64
        system("cls");
    #else
        system("clear");
    #endif

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
        "\t>>> Digite 'info' para mostrar informações do game...\n"
        "\t>>> Digite 'ajuda' para visualizar os comandos suportados...\n"
        "\t>>> Digite 'sair' para fechar o game...\n");
}
