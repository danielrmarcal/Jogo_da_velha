#include <stdio.h>
#include "main.h"

// Intro

void intro(){

    printf("#      JOGO DA VELHA    #\n");
}

// Variáveis Globais

char jogo[3][3];
int l, c;

//Inicializando

void inicializando(){
    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            jogo[l][c] = ' ';
        }
        
    }
    
}

// Imprimindo

void imprimir(){

    printf("\n\n\t 0   1   2\n\n");

    for ( l = 0; l < 3; l++)
    {
        for ( c = 0; c < 3; c++)
        {
            if(c == 0){
                printf("\t");
            }
            printf(" %c ", jogo[l][c]);
            if(c < 2){
                printf("|");
            }
            if (c == 2){
                printf("   %d", l);
            }
            {
                /* code */
            }
            
        }

        printf("\n");

        if(l < 2){
            printf("\t-----------\n");
        }
        
    }
    
}

//Identificando Vitoria linha

int ganhou_linha(int l, char c){
    if(jogo[l][0] == c && jogo[l][1] == c && jogo[l][2] == c){
        return 1; // Parabens voce ganhou!
    }
    else{
        return 0; // Voce perdeu
    }
}

//Identificando vitoria linhas

int ganhou_linhas(char c){

    int ganhou = 0;

    for ( l = 0; l < 3; l++)
    {
        ganhou += ganhou_linha(l, c); // Ira verificar as 3 linhas
    }

    return ganhou;
    
}

//Identificando vitoria coluna

int ganhou_coluna(int c, char j){
    if (jogo[0][c] == j && jogo[1][c] == j && jogo[2][c] == j)
    {
        return 1; // Voce ganhou!!
    }
    else{
        return 0; // Voce perdeu!
    }
    
}

//Identificando vitoria colunas

int ganhou_colunas(char j){
    int ganhou = 0;

    for (c = 0; c < 3; c++)
    {
        ganhou += ganhou_coluna(c, j);
    }

    return ganhou;
    
}

//Identificando vitoria diagonal principal

int ganhou_diagonal_prin(char c){
    if (jogo[0][0] == c && jogo[1][1] == c && jogo[2][2] == c)
    {
        return 1; // Voce ganhou!
    }
    else{
        return 0; // Voce perdeu!
    }
    
}

//Identificando vitoria diagonal secundaria

int ganhou_diagonal_sec(char c){
    if (jogo[0][2] == c && jogo[1][1] == c && jogo[2][0] == c)
    {
        return 1; // Voce ganhou!
    }
    else{
        return 0; // Voce perdeu
    }
    
}

int eh_valida(int l, int c){
    if(l >= 0 && l < 3 && c>= 0 && c < 3 && jogo[l][c] == ' '){
        return 1; // Valida!
    }
    else{
        return 0; // Não está valida
    }
}

void ler_coordenadas(char j){
    int linha, colunas;

    printf("Digite linha e coluna: ");
    scanf("%d%d", &linha, &colunas);

    while(eh_valida(linha, colunas) == 0){
        printf("Coordenadas invalidas, digite Novamente: ");
        scanf("%d%d", &linha, &colunas);
    }

    jogo[linha][colunas] = j;
}

// Empate

int vazio(){

    int quantidade = 0;

    for (l = 0; l < 3; l++)
    {
        for (c = 0; c < 3; c++)
        {
            if (jogo[l][c] == ' ')
            {
                quantidade++;
            }
        }
    }

    return quantidade;
    
}

// Jogando

void jogar(){

    int jogador = 1, vitoriaX = 0, vitoriaO = 0;

    char jogador1 = 'X', jogador2 = 'O';

    do{
        imprimir();

        if (jogador == 1)
        {

            printf("Player 1 Turn!\n");
            ler_coordenadas(jogador1); // Player 1
            jogador++;

            vitoriaX += ganhou_linhas(jogador1);
            vitoriaX += ganhou_colunas(jogador1);
            vitoriaX += ganhou_diagonal_prin(jogador1);
            vitoriaX += ganhou_diagonal_sec(jogador1);
        }
        else{

            printf("Player 2 Turn!\n");
            ler_coordenadas(jogador2); // Player 2
            jogador = 1;

            vitoriaO += ganhou_linhas(jogador2);
            vitoriaO += ganhou_colunas(jogador2);
            vitoriaO += ganhou_diagonal_prin(jogador2);
            vitoriaO += ganhou_diagonal_sec(jogador2);
        }
    }
    while(vitoriaX == 0 && vitoriaO == 0 && vazio() > 0);

    imprimir();

    if(vitoriaO == 1){
        printf("\n#      FIM DE JOGO    #\n");
        printf("\n\n Jogador 2 Wins!!\n");
    }
    else if(vitoriaX == 1){
        printf("\n#      FIM DE JOGO    #\n");
        printf("\n\n Jogador 1 Wins!!\n");
    }
    else{
        printf("\n\n EMPATE!!\n");
    }

}

