#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define MIN 20
#define MAX 50
#define min 1
#define max 3

int main()
{
    srand(time(NULL));

    int numeroGenerato = MIN + rand() % (MAX - MIN + 1);                                //generazione numero di partenza
    int input1;

    while (numeroGenerato != 0)                                   //mentre numeroGenerato diverso da zero
    {
        bool input1_caricato = false;                             //input dell'utente viene messo falso ogni volta che inizia il ciclo
        while (input1_caricato == false)
        {
            puts("L'utente inserisca 1, 2 o 3: ");
            scanf("%d", &input1);

            if (input1 == 1 || input1 == 2 || input1 == 3)        //verifica che l'input dell'utente sia 1, 2 o 3
            {
                printf("L'utente sceglie: %d \n", input1);  //stampa scelta dell'utente
                input1_caricato = true;                           //segnala il caricamento del valore dell'utente
                numeroGenerato -= input1;                         //sottrae dal numero generato l'input dell utente
            }else
                puts("Valore inserito non valido, riprova."); //chiede all'utente di reinserire il valore

        if (numeroGenerato == 0)                                  //se l'utente rende il numero generato 0 vince
        {
            puts("Utente1 vince.");
            break;                                                //termina il programma
        }

        if (numeroGenerato < 0)                                   //se l'utente rende il numero generato minore di 0
        {
            puts("L'utente e' andato sotto lo 0, il turno passa al computer");
            numeroGenerato += input1;                             //l'inpu dell' utente viene riaggiunto al numero generato
        }

        int input2 = min + rand() % (max - min + 1);              //generazione input del computer

            if (input1_caricato == true)                          //solo se l'input dell'utente è valido
            {
                printf("Il computer sceglie: %d \n", input2);
                numeroGenerato -= input2;                         //viene sottratto l'input del computer dal numero generato
            }

            if (numeroGenerato == 0)                              //vincita computer
            {
                puts("Il computer vince.");
                break;                                            //termina il programma
            }

            if (numeroGenerato < 0)                               //se il computer rende il numero generato minore di 0
            {
                puts("Il computer e' andato sotto lo 0, il turno passa all' utente");
                numeroGenerato += input2;
            }
        }
    }
    return 0;
}