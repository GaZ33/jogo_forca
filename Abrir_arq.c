#include <stdio.h>

int main()
{
  FILE *file;
  char Linha[100];
  int i;
  // Abre o arquivo de TEXTO para LEITURA
  file = fopen("aa.txt", "r");
  if (file == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
     return;
  }
  i = 0;
  while (!feof(file))
  {
	// Lê uma linha (inclusive com o '\n')
    fgets(Linha, 100, file);  // o 'fgets' lê até 99 caracteres ou até o '\n'
	  printf("Linha %d : %s",i,Linha);
      if (i == 1)
      {
        break;
      }
      
      i++;
  }
  fclose(file);
  printf("%s", Linha);
}