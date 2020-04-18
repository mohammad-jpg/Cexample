#include <stdio.h>

int main(void)
{
    int a;          /* user input */
    int divisors;   /* total number of divisors */
    int sum;        /* count of numbers with required number of divisors */
    int i;          /* moved here for C compiler */
    int p;          /* moved here for C compiler */
    int sqrti;      /* ceil(sqrt(i)) */

    printf("Enter the target number of divisors: ");
    scanf("%d", &a);
    printf("\n");
    sum = 0;                            /* init sum */
    sqrti = 1;                          /* init sqrti */
    for (i = 1; i <= 100000; i++)
    {
        divisors = 0;                   /* init number of divisors */
        if(sqrti*sqrti < i)             /* update sqrti as needed */
            sqrti += 1;
        for(p = 1; p < sqrti; p++)
            if(i%p == 0)                /* if p is a divisor, count it and i/p */
                divisors += 2;
        if(p*p == i)                    /* if p*p == i, count it */
            divisors += 1;
        if (divisors == a)              /* if i has a divisors, increment sum */
            sum += 1;
    }
    printf("There are %d numbers from 1 to 100000 inclusive which have exactly %d divisors.\n", sum, a);
    return 0;
}
