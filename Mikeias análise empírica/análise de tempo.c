#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/timeb.h>

//#define tamanho

FILE *gnuplot;
  
/*
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

void radixSort(int vetor[], int tamanho) {
    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}

void Bucket_Sort(int a[], int tamanho)
{
    int i;
    int j;
    int *count = NULL;
    //int tamanho = 10;

    // find largest
    int mymax = a[0]+1;
    for (i = 0; i < tamanho-1; i++)
    {
        if (mymax < (a[i]+1))
            mymax = a[i]+1;
    }

    // allocate and zero-fill a proper-sized array
    count = calloc(mymax, sizeof(*count));

    for(i=0; i < tamanho; i++)
        (count[a[i]])++;

    for(i=0,j=0; i < mymax; i++)
    {
        for(; count[i]>0;(count[i])--)
            a[j++] = i;
    }
    free(count);
}
/*
void Bucket_Sort()
{
    // 1) Create n empty buckets
    vector<float> b[n];
    
    // 2) Put array elements in different buckets
    for (int i=0; i<tamanho; i++)
    {
       int bi = tamanho*a[i]; // Index in bucket
       b[bi].push_back(a[i]);
    }
 
    // 3) Sort individual buckets
    for (int i=0; i<tamanho; i++)
       sort(b[i].begin(), b[i].end());
 
    // 4) Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < tamanho; i++)
        for (int j = 0; j < b[i].size(); j++)
          a[index++] = b[i][j];
}*/

struct bucket 
{
    int count;
    int* values;
};

int compareIntegers(const void* first, const void* second)
{
    int a = *((int*)first), b =  *((int*)second);
    if (a == b)
    {
        return 0;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void Bucket_Sort(int array[],int n)
{
    struct bucket buckets[3];
    int i, j, k;
    for (i = 0; i < 3; i++)
    {
        buckets[i].count = 0;
        buckets[i].values = (int*)malloc(sizeof(int) * n);
    }
    // Divide the unsorted elements among 3 buckets
    // < 0    : first
    // 0 - 10 : second
    // > 10   : third
    for (i = 0; i < n; i++)
    {
        if (array[i] < 0)
        {
            buckets[0].values[buckets[0].count++] = array[i];
        }
        else if (array[i] > 10)
        {
            buckets[2].values[buckets[2].count++] = array[i];
        }
        else
        {
            buckets[1].values[buckets[1].count++] = array[i];
        }
    }
    for (k = 0, i = 0; i < 3; i++)
    {
        // Use Quicksort to sort each bucket individually
        qsort(buckets[i].values, buckets[i].count, sizeof(int), &compareIntegers);
        for (j = 0; j < buckets[i].count; j++)
        {
            array[k + j] = buckets[i].values[j];
        }
        k += buckets[i].count;
        free(buckets[i].values);
    }
}

void leia( char *nome )
{
    int *a, *ptr, tamanho;

  struct timeb tempoInicial, tempoFinal;
  int i;
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
  insertionSort( a, tamanho);
  ftime( &tempoFinal );
  /*-----------*/

  /*ftime( &tempoInicial );
  selectionSort( a, tamanho);
  ftime( &tempoFinal );
  /*-----------*/

  /*-----------*/
  /*ftime( &tempoInicial );
  quicksort(0, tamanho - 1, a);
  ftime( &tempoFinal );
  /*-----------*/
  
  /*-----------*/
  /*ftime( &tempoInicial );
  heapSort(a, tamanho - 1);
  ftime( &tempoFinal );
  /*-----------*/
  
  /*-----------*/
  /*ftime( &tempoInicial );
  radixSort(a, tamanho - 1);
  ftime( &tempoFinal );
  /*-----------*/
  
  /*-----------*/
      //printf("teste");

  ftime( &tempoInicial );
  Bucket_Sort(a, tamanho);
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


  //system("clear");
    //printf("teste");

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