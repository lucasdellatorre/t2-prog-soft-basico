#ifndef _PALAVRAS_
#define _PALAVRAS_

typedef struct typeword *Palavra;

extern void limpaString(char *word);
extern Palavra *inserePalavra(char *word, Palavra *list, int paragraph);
extern void printa(Palavra *list, const char *arquivo);
extern const char *getfield(char *line, int num);
extern void printaHTML(const char *saida, const char *html);

#endif