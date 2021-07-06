#include <stdio.h>
#include <stdlib.h>

void firingSquad(int**, int);
void countPrisoners(int**, int);

int main()
{
        // несортированные заключенные
        int gulagPrisonersLength = 10;
        int gulagPrisonersTemp[10] = {54,102,39,40,31,27,54,10,12,13};

        int** gulagPrisoners = (int**)malloc(sizeof(int*)*10);
        int i;
        for(i=0; i<gulagPrisonersLength; i++)
        {
                gulagPrisoners[i] = (int*)malloc(sizeof(int));
                *gulagPrisoners[i] = gulagPrisonersTemp[i];
        }

        // подсчитать заключенных
        countPrisoners(gulagPrisoners, gulagPrisonersLength);

        // заключенный отрезанный
        int cutoff = *gulagPrisoners[0];

        // на каждого заключенного
        for(i=0; i<gulagPrisonersLength; i++)
        {
                // если заключенный не попадает в срок
                if(*gulagPrisoners[i] > cutoff)
                {
                        // Уничтожьте недостойных
                        firingSquad(gulagPrisoners, i);
                }
                else{
                        cutoff = *gulagPrisoners[i];
                }
        }

        // подсчитать заключенных
        countPrisoners(gulagPrisoners, gulagPrisonersLength);

}

void countPrisoners(int** gulagPrisoners, int length)
{
        int i;
        for(i=0; i<length; i++)
        {       
                if(gulagPrisoners[i] != NULL)
                {       
                        printf("%d, ",*gulagPrisoners[i]);
                }
        }
        printf("\n");
}

void firingSquad(int** gulagPrisoners, int prisonerNumber)
{
        // убийство
        gulagPrisoners[prisonerNumber] = NULL;
}
