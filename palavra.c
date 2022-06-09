#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE_WORDS 33

typedef struct typeword Palavra;

struct typeword{
  char string[SIZE_WORDS];
  int array[20]; // array que contém os parágrafos que a palavra apareceu
  int len; // contador de incidências de parágrafos
  int cont; // contador de incidências de palavras
  Palavra* next; // ponteiro para a próxima palavra
};

// coloca a string em minúsculo e limpa ela de tudo que não for letra minúcula
void limpaString(char *word){
  
  int index = strlen(word) - 1;

  int i;

  for(i=index;i>0;i--){
    word[0] = (word[0] > 64 && word[0] < 91) ? word[0]+32 : word[0];
      if(word[i]<97 || word[i]>122){
          word[i]='\0';
      }
  }
  return;
}

// verifica se adiciona uma nova palavra ou se somente adiciona o paragrafo onde esta
Palavra* inserePalavra(char *word, Palavra *list, int paragraph, int *count_words){
  Palavra *i;

  if(list == NULL){
    
    // aloca memória
    Palavra* first_word;
    first_word = (Palavra*)malloc(sizeof(Palavra));

    //Passa os valores
    strcpy(first_word->string, word);
    first_word->array[0] = paragraph; // adiciona o paragrafo em que a palavra está
    first_word->len = 1;
    first_word->cont = 1;
    first_word->next = NULL;
    list = first_word;
    return list;
  }

  i  = list;
  Palavra *list_end;

  // percorre a lista para ver se a palavra já foi adicionada
  while(i!=NULL){
    
    if(strcmp(i->string, word) == 0){
      
      i->cont++;
      
      // se a posicao anterior do array contém o mesmo numero do paragrafo, entao está 
      // repetido, logo não precisa inserir no array
      if (i->array[i->len - 1] == paragraph) {
        return list; 
        i->cont = i->cont + 1;
      }
      
      i->array[i->len] = paragraph; // adiciona o numero do paragrafo no array
      i->len = i->len + 1; // incrementa o contador de incidências de parágrafos
      return list;
    }
    
    if(i->next==NULL) {
        list_end = i;
    }
    
    i = i->next;
  }

  // se não achou a palavra na lista, aloca memória para uma nova palavra
  Palavra *new_word;
  new_word = (Palavra*)malloc(sizeof(Palavra));
  
  strcpy(new_word->string, word);
  new_word->cont = 1;
  new_word->array[0] = paragraph;
  new_word->len = 1;
  new_word->next = NULL;
  list_end->next = new_word;
  *count_words = *count_words + 1;
  return list;
}

void printa(Palavra *list, const char* arquivo) {

  FILE *output = fopen(arquivo, "w");
  Palavra* aux;
  if(list == NULL) {
    printf("Lista vazia");
  } else {
      for(aux = list; aux != NULL; aux = aux->next) {
        // printa a palavra e quantas vezes ela existe no texto
        fprintf(output, "\n%s; | ", aux->string);
        for(int i = 0; i < aux->len; i++) {
          // printa todas as ocorrencias em paragrafos
          fprintf(output, "%d | ", aux->array[i]);
        }
      }
    }
}