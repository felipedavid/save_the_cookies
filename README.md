Building
----
    $ git clone https://github.com/felipedavid/save_the_cookies
    $ cd save_the_cookies
    $ sudo chmod +x build.sh
    $ ./build.sh
    $ ./bin/game

TODO
----
* Implementar mecânicas e status do jogador
* Adicionar items e sistema de buff para aumentar status do jogador
* Implementar inimigos e mecânica de combate
* Implementar sistemas de drop após combate
* Refinar todas as funcionalidades

TALVEZ
----
* Implementar NPCS e dialogo
* Implementar algo para salvar o jogo em um arquivo ou banco de dados

DONE
----
* Implementar um simples parser que aceite comandos formados por verbo e 
substantivo, ex: "> atacar goblin"
* Adicionar uma estrutura object que sera a base de tudo, jogador, monstro,
items, lugares.
* Implementar locais
* Criar sistema de inventário
