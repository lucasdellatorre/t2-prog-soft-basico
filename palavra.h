#ifndef _PALAVRAS_
#define _PALAVRAS_

typedef struct typeword *Palavra;

extern void limpaString(char *word);
extern Palavra* inserePalavra(char *word, Palavra *list, int paragraph, int *count_words);
extern void printa(Palavra *list, const char* arquivo);

#endif