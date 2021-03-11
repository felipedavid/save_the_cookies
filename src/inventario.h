objeto_t pegar_ob_item(char *verbo, char *substantivo, objeto_t *loc_atual);
void abrir_inventario(void);
void pegar_item(char *);
void dar_item(char *);
void largar_item(char *);
objeto_t *procurar_objeto(char *substantivo);
objeto_t *campo_de_visao(char *proposito, char *substantivo);
bool objeto_tem_nome(objeto_t *objeto, char *substantivo);
