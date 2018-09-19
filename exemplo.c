#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

FILE *gnuplot;
int *a, *ptr;
  

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}
void bubble(int a[], int N)
{
  int i, j;
  for (i=N; i >= 0; i--)
    for (j = 1; j <= i; j++)
      if (a[j-1] > a[j]) swap(&a[j-1], &a[j]); 
}


void insertionSort(int a[], int n){
   // int n;
    int atual;
    for(int i = 0; i<n; i++){
        atual = a[i];
        int j = i-1;
        while(j>=0 && a[j] >= atual){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = atual;
    }
}


void selectionSort(int vetor[], int n){
  int menor, aux;
  int i, j;

  for(i = 0; i<n; i++){
          menor =i;
    for(j=i+1; j<n; j++){
        if(vetor[menor] > vetor[j])
            menor = j;
    }
        if(i != menor){
            aux=vetor[i];
            vetor[i]=vetor[menor];
            vetor[menor]=aux;
        }
    }
}


int particionar(int esquerda, int direita, int *vetor){
    int i, aux;
    int cont = esquerda;
    for(i = esquerda+1; i <= direita; i++){
        if(vetor[i] < vetor[esquerda]){
            cont++;
            aux=vetor[i];
            vetor[i]=vetor[cont];
            vetor[cont]=aux;
        }
    }
    aux=vetor[esquerda];
    vetor[esquerda]=vetor[cont];
    vetor[cont]=aux;
    return cont;
}

int quicksort(int esquerda, int direita, int *vetor){
    int temp;

    if(esquerda < direita){
        temp = particionar(esquerda, direita, vetor);
        quicksort(esquerda, temp-1, vetor);
        quicksort(temp+1, direita, vetor);
    }

}

void troca(int j, int aposJ){
    int aux = a[j];
    a[j] = a[aposJ];
    a[aposJ] = aux;
}

int maxheapify(int pos, int tamanhoDoVetor){
   // int vetor[a];
    int maxh = 2 * pos + 1;
    int direita = maxh + 1;
    if(maxh < tamanhoDoVetor){
        if(direita< tamanhoDoVetor && a[maxh] < a[direita]){
            maxh = direita;
        }
        if(a[maxh] > a[pos]){
            troca(maxh, pos);
            maxheapify(maxh, tamanhoDoVetor);
        }
    }
}

int criaheap(int n){
    int i;
    int j = n;
    for(i = n / 2 - 1; i >= 0; i--){

        maxheapify(i, j);
    }
}


int heapSort(int i[], int tam){
    criaheap(tam);
    int j = tam;
//VERIFICAR A REGRA TAM - 1
    for(int i = tam; i > 0; i--){
        troca(i, 0);
        maxheapify(0, --j);
    }
}



void leia( char *nome )
{
  struct timeb tempoInicial, tempoFinal;
  int i, tamanho;
  FILE   *arquivo;
  arquivo = fopen(nome, "r");
  fscanf(arquivo, "%d", &tamanho);
  a = malloc(tamanho * sizeof(int));
  printf("%d\t\t", tamanho);
  fprintf( gnuplot, "%d\t\t", tamanho);
  for (i=1; i <= tamanho; i++)
    {
      fscanf(arquivo, "%d", &a[i-1]);
    }

  /*-------------------*/
  /*ftime( &tempoInicial );
  bubble( a, tamanho - 1);
  ftime( &tempoFinal );
  *//*-------------------*/

  /*------------*/
  /*ftime( &tempoInicial );
  insertionSort( a, tamanho - 1);
  ftime( &tempoFinal );
  *//*-----------*/

  /*ftime( &tempoInicial );
  selectionSort( a, tamanho - 1);
  ftime( &tempoFinal );*/
  /*-----------*/

  /*-----------*/
  /*ftime( &tempoInicial );
  quicksort(0, tamanho - 1, a);
  ftime( &tempoFinal );
  *//*-----------*/
  
  /*-----------*/
  ftime( &tempoInicial );
  heapSort(a, tamanho - 1);
  ftime( &tempoFinal );
  /*-----------*/
  
  free(a);
  int tempo = (int) (1000.0 *(tempoFinal.time - tempoInicial.time)+(tempoFinal.millitm - tempoInicial.millitm));
  fprintf( gnuplot," %d \n", tempo );
  printf(" %d \n", tempo );
  fclose(arquivo);
}
int main()
{

  system("clear");

  gnuplot = fopen(".resultados/bubb-rnd.dat", "w");
  printf("RANDOMICOS\nTamanho \t Tempo\n");
  fprintf(gnuplot, "#RANDOMICOS\n#Tamanho \t Tempo\n");
  leia ("amostra/rnd10.dat");
  leia ("amostra/rnd50.dat");
  leia ("amostra/rnd100.dat");
  leia ("amostra/rnd500.dat");
  leia ("amostra/rnd1000.dat");
  leia ("amostra/rnd2000.dat");
  leia ("amostra/rnd5000.dat");
  leia ("amostra/rnd10000.dat");
  leia ("amostra/rnd20000.dat");
  leia ("amostra/rnd50000.dat");
  leia ("amostra/rnd100000.dat");
  fclose(gnuplot); 

  gnuplot = fopen(".resultados/bubb-ord.dat", "w");
  printf("\nORDENADOS\nTamanho \t Tempo\n");
  fprintf(gnuplot, "#ORDENADOS\n#Tamanho \t Tempo\n");
  leia ("amostra/ord10.dat");
  leia ("amostra/ord50.dat");
  leia ("amostra/ord100.dat");
  leia ("amostra/ord500.dat");
  leia ("amostra/ord1000.dat");
  leia ("amostra/ord2000.dat");
  leia ("amostra/ord5000.dat");
  leia ("amostra/ord10000.dat");
  leia ("amostra/ord20000.dat");
  leia ("amostra/ord50000.dat");
  leia ("amostra/ord100000.dat");
  fclose(gnuplot); 

  gnuplot = fopen(".resultados/bubb-inv.dat", "w");
  printf("\nINVERSAMENTE ORDENADOS\nTamanho \t Tempo\n");
  fprintf(gnuplot, "#INVERSAMENTE ORDENADOS\n#Tamanho \t Tempo\n");
  leia ("amostra/inv10.dat");
  leia ("amostra/inv50.dat");
  leia ("amostra/inv100.dat");
  leia ("amostra/inv500.dat");
  leia ("amostra/inv1000.dat");
  leia ("amostra/inv2000.dat");
  leia ("amostra/inv5000.dat");
  leia ("amostra/inv10000.dat");
  leia ("amostra/inv20000.dat");
  leia ("amostra/inv50000.dat");
  leia ("amostra/inv100000.dat");
  
  fclose(gnuplot); 
  system("gnuplot -bg gray90 plota.gnu");
}