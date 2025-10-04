#include "header.h"

int powerIter(int a, int b) {
    int multiplier = a;
    for (size_t i = 1; i < b; i++)
    {
        a*=multiplier;
        printf("%d: %d\n", i, a);
    }
    printf("A: %d\n", a);
    return a;
}
int powerRec(int a, int b) {
    if (b==0) return 1;
    return a * powerRec(a, b-1);
}

int main(int argc, char const *argv[])
{
    printf("Iterative: %d Recursive: %d", powerIter(2, 4), powerRec(2, 4));
    return 0;
}
