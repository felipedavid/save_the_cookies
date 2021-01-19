Save the Cookies
----
Um simples text-based rpg game para demonstar as principais funcionalidades dos clássicos rpgs
de texto famosos nos anos 70.
A premissa do game é bem simples, monstros atacaram o seu vilerejo durante a
noite e acabaram roubando todo o seu estoque de alimentos, entre os alimentos 
roubados estavam os biscoitos que sua vovó fez para você. Seu objetivo é atacar
o labirinto de onde esses monstros saíram e tentar recuperar o máximo de 
biscoitos possível.

Building
----
    $ sudo apt install build-essential -y
    $ git clone https://github.com/felipedavid/save_the_cookies
    $ cd save_the_cookies
    $ make game
    $ ./game

TODO
----
* Implementar um simples parser que aceite comandos formados por verbo e 
substantivo, ex: "> atacar goblin"
* Adicionar uma estrutura object que sera a base de tudo, jogador, monstro,
items, lugares.
* Implementar locais
* Implementar mecânicas e status do jogador
* Criar sistema de inventário
* Adicionar items e sistema de buff para aumentar status do jogador
* Implementar inimigos e mecânica de combate
* Implementar sistemas de drop após combate

TALVEZ
----
* Implementar NPCS e dialogo
* Implementar algo para salvar o jogo em um arquivo ou banco de dados
