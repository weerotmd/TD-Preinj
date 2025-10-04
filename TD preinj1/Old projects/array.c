#include "header.h"

void fillArray(int tab[], int size) {
   for (size_t i = 0; i < size; i++)
   {
    srand(time(NULL)*i);
    tab[i] = rand()%100;
   }
}
void displayArray(int tab[], int size) {
    if (size==1) {
        printf("%d;\n", tab[size-1]);
    }
    else {
        printf("%d; ", tab[size-1]);
        displayArray(tab, size-1);
    }
}
/*void displayArrayVanilla(int tab[], int size) {
    for (size_t i = 0; i < size; i++)
    {
        printf("%d; ", tab[size-1-i]);
    }
}*/
int maximum(int tab[], int size) {
    if (size==1) {
        return (tab[size-1] % 3 == 0);
    }
    else {
        return maximum(tab, size-1) + (tab[size-1] % 3 == 0);
    }
}

int main(int argc, char const *argv[])
{
    int tab[10];
    fillArray(tab, 10);
    displayArray(tab, 10);
    printf("Maximum: %d", maximum(tab, 10));
    //displayArrayVanilla(tab, 10);
    return 0;
}
