#include "header.h"

int sum(int a, int total) {
    
    if (a==0) {
        return total;
    }
    else {
        int b = a;
        int divider = 0;
        while (b >= 1)
        {
            divider++;
            b/=10;
        }
        b = a;
        b = floor(a/pow(10, (divider-1)));
        total += b;
        /*printf("%d, %d, %d, end\n", a, b, divider);
        printf("%f, %f\n", pow(10, (divider-1)), a/pow(10, (divider-1)));
        printf("%d, %f\n", a, b*pow(10, divider-1));*/
        return sum(a-b*pow(10, divider-1), total);
    }
}

int main(int argc, char const *argv[])
{
    printf("Sum: %d", sum(85641, 0));
    //displayArrayVanilla(tab, 10);
    return 0;
}
