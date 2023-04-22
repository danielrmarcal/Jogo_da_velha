#include <stdio.h>
#include "main.h"


int main(int argc, char const *argv[])
{

    intro();


    int opcao;

    do{
        inicializando();
        jogar();

        printf("\nDigite 1 para jogar Novamente:\n");
        scanf("%d", &opcao);
    }
    while (opcao == 1); 

}
