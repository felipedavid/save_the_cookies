// por questões de simplicidade decidi fazer de tudo um 'objeto'
// ex: colocar item no 'inventário' do jogador? 
//     só dizer que o item está 'localizado' no jogador.
//      1  objeto_t biscoito;
//      2  biscoito.localizacao = &jogador;
typedef struct objeto {
    char *info;
    char *nome;
    struct objeto *localizacao;
} objeto_t;

extern objeto_t objetos[];
#define casa           (objetos+0)
#define vilarejo       (objetos+1)
#define vizinho        (objetos+2)
#define jogador        (objetos+3)
#define final_do_array (objetos+4)
