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
set key at 25000, 6000
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