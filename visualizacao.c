#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char* getfield(char* line, int num)
{
  const char* tok;
  for (tok = strtok(line, ";"); tok && *tok; tok = strtok(NULL, ";\n")) {
    if (!--num)
      return tok;
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  
  FILE* exit = fopen("exit.csv", "r");
  FILE *txt_output_2 = fopen("palavras.html", "w");
  char line2[100000];
  //printf("%s", txt_output_2);

  fprintf(txt_output_2, "<!DOCTYPE html> \
  <html> \
  <style> \
  table, th, td { \
    border: 1px solid black; \
    font-size: 14pt; \
    background: #ffc; \
  } \
  </style> \
  <body> \
  <h2>Saida do arquivo CSV</h2> \
  <table> \
  <tr> \
  <th> Palavra </th> \
  <th> Parágrafos </th> \
  </tr> \
  <tr>");

  while (fgets(line2, 100000, exit) != NULL) {
    printf("oi");
    char* tmp = strdup(line2);
    printf("%s", line2);
    fprintf(txt_output_2,"<tr><td>%s</td><td>%s</td></tr>", getfield(tmp, 1), getfield(tmp, 2));
    // NOTE strtok clobbers tmp
    free(tmp);
  }
  
  fprintf(txt_output_2, "</tr> \
  </table> \
  </body> \
  </html>");
}