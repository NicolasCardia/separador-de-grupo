#define _GNU_SOURCE // necessário porque getline() é extensão GNU
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogador {
    int nivel;
    char nome[30];
} jogadores[50], aux;

int j = 0;

void bubble_sort()
{
    for (int i = 0; i <j; i++)
    {
        for (int j = 0;j < j -1; j++)
        {
            if (jogadores[j].nivel > jogadores[j+1].nivel){
                aux = jogadores[j];
                jogadores[j] = jogadores[j+1];
                jogadores[j+1] = aux;}
        }
    }
}


void carregaJogadores()

{
  FILE *pont_arq;
  size_t len= 100;
  char *linha =malloc(len);
  
  pont_arq = fopen("arquivo.txt", "r") ;


  char delim[] = ",";

  while (getline(&linha, &len, pont_arq) > 0)  {
    char *ptr = strtok(linha, delim);
    if ((ptr != NULL) && (!strcmp(ptr,"1")) )

    {
        ptr = strtok(NULL, delim);
        jogadores[j].nivel = atoi(ptr);
        ptr = strtok(NULL, delim);
        strcpy(jogadores[j].nome, ptr);
        j++;
    }
  }
  if (linha)
    free(linha);

  bubble_sort();

  for (int i=0; i<j; i++)
  {
      printf("%d) %s",jogadores[i].nivel,jogadores[i].nome);
  }

  fclose(pont_arq);
}


void teams(int nTimes)
{
    char vTimes[nTimes][300];
    for (int i = 0; i<nTimes; i++)
    {
        strcpy(vTimes[i],jogadores[i].nome);
    }

    for (int i = nTimes; i < j; i++)
    {
        strcat(vTimes[(nTimes-1)-(i%nTimes)],jogadores[i].nome);
    }



    printf("\nTimes Selecionados:\n\n");
    for (int i=0; i<nTimes; i++)
    {
        printf("Time %d)\n%s\n",i+1,vTimes[i]);
    }
}



int main(void){
  	int n;
  carregaJogadores();
  printf("Quantos Times? ");
  scanf("%d",&n);
  teams(n);
  return(0);}