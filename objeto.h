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
#define biscoito       (objetos+4)
#define estilingue     (objetos+5)
#define final_array    (objetos+6)

int objetos_em_localizacao(objeto_t *localizacao);
objeto_t *procurar_objeto(char *subs);
