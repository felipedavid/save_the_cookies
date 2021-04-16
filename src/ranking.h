typedef struct jogador_t {
    char nome[256];
    int pontos;
    struct jogador_t *next;
} jogador_t;

typedef struct ranking_t {
    jogador_t *head;
} ranking_t;

ranking_t *criar_ranking(void);
void free_ranking(ranking_t *ranking);
bool inserir_jogador(ranking_t *ranking, char *nome, int pontos);
void mostrar_ranking(ranking_t *ranking);
bool salvar_ranking(ranking_t *ranking);
void prompt_inserir_jogador(ranking_t *ranking, char *substantivo);
bool load_ranking(ranking_t *ranking);
