/*mikeias.cpp
No início deste ano
18 de abr

Você compartilhou 1 item
C++
mikeias.cpp

Pode editar
Breno Teodoro
Ano passado
17 de set de 2017Computador

Você editou 1 item
C++
mikeias.cpp
6 de jul de 2017Computador

Você fez o upload de 1 item
C++
mikeias.cpp*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 90000
//             Mikeias Silva Gomes de Azevedo RA: 15058923

int vetor[n];


 void criaVetor(){
    srand(time(NULL));
    int i;
    for(i = 0; i<n; i++){
        vetor[i]= rand()%n-1;
    }
}


void bubblesort(){
    int cont =1;
    int i, j;
    int aux;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(vetor[j] > vetor[j+1]){
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
        }
       cont++;
    }
}

void selectionSort(){
    int menor, aux;
    int i, j;

    for(i = 0; i<n-1; i++){
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

int particionar(int esquerda, int direita){
    int i, aux;
    int cont = esquerda;
    for(i = esquerda+1; i<=direita; i++){
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

void quicksort(int esquerda, int direita){
    int temp;

    if(esquerda<direita){
        temp = particionar(esquerda, direita);
        quicksort(esquerda, temp-1);
        quicksort(temp+1, direita);
    }

}

void insertionSort(){
    int i;
    int atual;
    for(i = 0; i<n; i++){
        atual = vetor[i];
        int j = i-1;
        while(j>=0 && vetor[j] >= atual){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = atual;
    }
}

void merges(int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2;
    tamanho = fim-inicio+1;

    p1 = inicio;
    p2 = meio + 1;
    temp = (int *) malloc(tamanho*sizeof(int));
    if(temp != NULL){
        for(int i=0; i<tamanho; i++){
            if(!fim1 && !fim2){
                if(vetor[p1] < vetor[p2])
                    temp[i]=vetor[p1++];
                else
                    temp[i]=vetor[p2++];

                if(p1>meio)
                    fim1=1;
                if(p2>fim)
                    fim2=1;
          }else{
              if(!fim1)
                temp[i]=vetor[p1++];
              else
                temp[i]=vetor[p2++];
                }
        }
        for(int j = 0, k=inicio; j<tamanho; j++, k++)
            vetor[k]=temp[j];
    }
    free(temp);
}

void mergeSort(int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = ((inicio+fim)/2);
        mergeSort(inicio, meio);
        mergeSort(meio+1, fim);
        merges(inicio, meio, fim);
    }
}
void troca(int j, int aposJ){
int aux = vetor[j];
vetor[j]= vetor[aposJ];
vetor[aposJ]=aux;
}


void maxheapify(int pos, int tamanhoDoVetor){
    int maxh = 2 * pos + 1, direita = maxh + 1;
    if(maxh < tamanhoDoVetor){
        if(direita< tamanhoDoVetor && vetor[maxh] < vetor [direita]){
            maxh = direita;
        }
        if(vetor[maxh] > vetor[pos]){
            troca(maxh, pos);
            maxheapify(maxh, tamanhoDoVetor);
        }
    }
}

void criaheap(){
    int i;
    int j = n;
    for(i = n / 2 - 1; i >= 0; i--){

        maxheapify(i, j);
    }
}

void heapSort(){
    criaheap();
    int j = n;

    for(int i = n -1; i> 0; i--){
        troca(i, 0);
        maxheapify(0, --j);
    }
}


/*imprime(){
int i;
    for(i = 0; i<n; i++){
        if(i%10 == 0){
            printf("\n");
        }
        printf(" %3d", vetor[i]);
    }
}*/


int main(){
clock_t tempo1, tempo2;
//BUBBLESORT
criaVetor();
tempo1 = clock();
bubblesort();
tempo2 = clock()- tempo1;
printf("Ordenado pelo bubble sort | tempo gasto: %f .", (float) tempo2/CLOCKS_PER_SEC);
printf("\n\n\n");

//insertion sort
criaVetor();
tempo1 = clock();
insertionSort();
tempo2 = clock()-tempo1;
printf("\nOrdenado pelo Insertion Sort | tempo gasto: %f .", (float) tempo2/CLOCKS_PER_SEC);
printf("\n\n\n");

//Selection Sort
criaVetor();
tempo1 = clock();
selectionSort();
tempo2 = clock()-tempo1;
printf("\nOrdenado pelo Selection Sort | tempo gasto: %f .", (float) tempo2/CLOCKS_PER_SEC);
printf("\n\n\n");

//HEAPSORT
criaVetor();
tempo1 = clock();
heapSort();
tempo2 = clock()-tempo1;
printf("\nOrdenado pelo Heap Sort | tempo gasto: %f .", (float) tempo2/CLOCKS_PER_SEC);
printf("\n\n\n");

//merge sort
criaVetor();
tempo1 = clock();
mergeSort(0, n);
tempo2 = clock()-tempo1;
printf("\nOrdenado pelo Merge Sort | tempo gasto: %f .", (float) tempo2/CLOCKS_PER_SEC);
printf("\n\n\n");

//Quick Sort
criaVetor();
tempo1 = clock();
quicksort(0, n);
tempo2 = clock()-tempo1;
printf("\nOrdenado pelo Quick Sort | tempo gasto: %f .", (float) tempo2/CLOCKS_PER_SEC);
printf("\n\n\n");


return 0;
}
