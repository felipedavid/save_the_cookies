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
#define finalDoArray   (objetos+6)

int objetosEmLocalizacao(objeto_t *localizacao);
objeto_t *procurarObjeto(char *subs);
