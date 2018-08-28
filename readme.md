# Engenharia de software
## Disciplina de Análise de Algoritmos
* * *

Trabalho de análise empírica do comportamento assintótico de algoritmos de ordenação
==============================================
Este repositório apresenta as instruções para a relização do trabalho e também um exemplo com o algoritmo Bubblesort

1\. Instruções
--------------
Fazer um estudo de tempo de execução empírico dos seguintes algoritmos de ordenação:
* Insertion Sort
* Selection Sort
* Quick Sort
* Heap Sort
* Radix sort
* Bucket sort

Observando as seguintes questões:
* Devem ser utilizados os algoritmos estudados em sala de aula como fonte de referência para a codificação.
* Para  cada  classificador,  devem  ser  considerados  três  tipos  de  entrada  de arranjo:  já  ordenado,  ordem  aleatória  e  ordem  inversa,  e  no mínimo 10 tamanhos de entradas distintas.
* O trabalho poderá ser realizado individualmente ou em dupla de alunos.

O  resultado  do  estudo  empírico  realizado  deverá  ser  registrado  em  trabalho  escrito, observando as seguintes questões:
* Observar as regras metodológicas para apresentação de trabalhos (Mnnual de normas UEPG).
* O trabalho escrito consistirá em um relatório do experimento. Deverá conter introdução e objetivos, isto é, deverá descrever do se trata o trabalho e quais os objetivos pretendidos.
* Deverão ser descritos os materiais e métodos utilizados. Os materiais se referem ao  equipamento  (hardware)  utilizado  e  ao  ambiente  (sistema  operacional, compilador, etc.). Os métodos devem descrever como se deu a execução do experimento,  de  forma  a  permitir  que  outros  indivíduos  possam  repetir  o experimento ou utilizá-lo como referência para outros experimentos.
* Os resultados obtidos na execução dos classificadores devem ser exibidos de diferentes  formas:  texto  explicativo,  tabelas,  gráficos,  etc.  Cabem  aqui discussões sobre os resultados obtidos. 
* No final, a conclusão deverá fazer o fechamento do trabalho realizado. 
* Todo trabalho possui fontes de referência, as quais devem ser enumeradas ao final do trabalho. 
***
A seguir será apresentado um exemplo de como poderia ser impĺementado a análise empírica do comportamento de um algoritmo de ordenação
Os passos a seguir são opcionais e dirigidos à implementação em um ambiente Linux na linguagem C ansi.

O **Bubblesort** é um dos algoritmos mais triviais de ordenação. A complexidade é de **O(n²)**.

Segue abaixo o exemplo de implementação

* * *

2\. Bubblesort
--------------
```
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
```
***
3\. Aquisição de dados
--------------
A aquisição dos dados poderá ser realizada utilizando os arquivos pré-definidos de dados. Os arquivos estão na pasta amostra e estão dispostos da seguinte forma:
* 3 padrões de entrada
    * Entrada com dados aleatórios (prefixo rnd)
    * Entrada com dados ordenados (prefixo ord)
    * Entrada com dados inversamente ordenados (prefixo inv)
* Para cada padrão haverá 11 tamanhos de entrada, sendo eles
    * 10, 50, 100, 500, 1.000, 2.000, 5.000, 10.000, 20.000, 50.000 e 100.000 (identificados por suas respectivas quantidades como pósfixos)
* Os arquivos contém as seguintes informações
    * A primeira linha contém o número de elementos que o arquivo contém.
    * A partir da segunda linha estão os elementos, um por linha. 
    
A operação de leitura pode ser realizada diretamente para dentro de um vetor alocado já de início com o tamanho certo. A primeira linha de cada arquivo de dados contem o valor do numero de elementos que o arquivo contem. Basta ler a primeira linha para saber quantos dados devem ser lidos, alocar um vetor com este tamanho e depois ler os dados um a um com **fscanf()** colocando-os diretamente dentro do vetor:
```
void leia( char *nome )
{
  int *a, *ptr;
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
  ftime( &tempoInicial );
  bubble( a, tamanho - 1);
  ftime( &tempoFinal );
  /*-------------------*/
  free(a);
  int tempo = (int) (1000.0 *(tempoFinal.time - tempoInicial.time)+(tempoFinal.millitm - tempoInicial.millitm));
  fprintf( gnuplot," %d \n", tempo );
  printf(" %d \n", tempo );
  fclose(arquivo);
}
```
O tempo de execução é obtido pela função **ftime()** e leva em consideração apenas a execução do algoritmo de ordenação, e não o tempo de leitura de dados.
* * *

4\. Função principal
--------------
A função principal foi definida de forma bem simples e pouco estruturada.
```
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
```

Note que para cada **Padrão de entrada** é aberto um arquivo com o nome bubb-<padrao>.dat. Este arquivo será utilizado para gravar os dados de _tamnaho da entrada vs tempo de execução_. Este arquivo será posteriormente utilizado pelo utilitário de plotagem de gráfico chamado GNUPLOT
* * *

5\. Saída dos dados
--------------
Os dados serão armazenados no arquivo no arquivo **bubb-<padrao>.dat** na pasta **.resultados** onde:
*   um arquivo para cada conjunto de dados (rnd, ord, inv)
*   um valor de tempo de ordenação por linha, com:
    *   a abcissa na primeira coluna e
    *   a ordenada na segunda.
*   O separador pode ser um espaço ou um tab. Não pode ser uma linha.

**Exemplo:** 
arquivo bubb-ord.dat produzido pelo Bubble. Comentários são iniciados por um # 
```
#ORDENADOS 
#Tamanho Tempo 
11       0
51       0
101      0 
501      1 
1001     1 
2001     5 
5001     32 
10001    135
```
* * *

6\. Exibição com o GNUPLOT
--------------
Para exibir os dados com o utilitário GNUPLOT, pode ser utilizado o arquivo de configuração **plota.gnu**, que segue abaixo:
```
# ----------------------------------------------------------
# Arquivo de comandos GnuPlot para a plotagem da curva de 
# Complexidade de Tempo do Algoritmo Bubblesort (Ordenacao
# Por Bolha). 
#
# Este programa GnuPlot seta uma janela grafica e le varios
# arquivos de dados.
# ----------------------------------------------------------
set title "Plot de Complexidade de Tempo para Bubblesort"
#
#Seta tamanho da janela automaticamente de acordo com os dados
set autoscale

set style data lines

set xlabel "Tamanho do Conjunto de Dados"
set ylabel "Tempo"
#
#Seta posicao em coordenadas dos dados, onde vao aparecer os titulos
#Ist voce DEVE adaptar aos seus dados
set key at 40000, 40000
#
#Seta grade
set grid
#
# Le arquivos e plota dados
plot \
        ".resultados/bubb-rnd.dat" title "Randomicos" with  linespoint lw 2 pt 11,\
        ".resultados/bubb-ord.dat" title "Ordenados" with  linespoint lw 2 pt 11, \
        ".resultados/bubb-inv.dat" title "Invertidos" with  linespoint lw 2 pt 11
#
# Para que voce possa chamar o gnuplot diretamente de dentro de seu 
# programa em C usando o comando system(). Se voce nao colocar uma
# pausa no final de seu plot, a janela fecha imediatamente apos 
# ter sido desenhada.
pause -1 "Tecle enter para sair..."
```
* * *

7\. Algumnas dicas
--------------

*   Lembre-se que o gnuplot é um cliente do X-windows e que você não pode utilizá-lo a não ser que você esteja em um terminal gráfico com X-windows rodando. Não tente chama-lo a partir de um telnet rodando em MS-Windows.
*   Lembre-se que, como para todo cliente do X-windows, gnuplot precisa saber qual o endereço do vídeo onde vai jogar a saída gráfica. Para isso você precisa setar a variável $DISPLAY do seu ambiente antes de poder chamar o gnuplot.
*   Um bom exemplo de como chamar o gnuplot está na função main do programa exemplo acima.  
      
    
### *   O exemplo acima é apenas um auxílio. Você está livre para implementar os algoritmos como for de sua preferência, lembrando sempre de seguir as instruções contidas no **tópico 1**