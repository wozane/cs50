#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float change;

    do
    {
        printf("O hai! How much change is owed?\n");
        change = get_float();
    }
    while (change < 0);

    float f = 0.1;
    printf("%.55f\n", f);

}