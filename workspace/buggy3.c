#include <cs50.h>
#include <stdio.h>

int get_negative_int(void);

int main(void)
{
    int i = get_negative_int();
    printf("%i is a negative int\n", i);
}

int get_negative_int(void)
{
    int n;

    do
    {
        printf("n is : ");
        n = get_int();
    }
    while (n >= 0);

    return n;
}

/*
~/workspace/ $ ./buggy3
n is : -2
-2 is a negative int
*/