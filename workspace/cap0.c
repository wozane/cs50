#include <cs50.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    string s = get_string();

    if (s != NULL)
    {
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                // this can be written as well as -> printf("%c", s[i] - 32);
                printf("%c", s[i] - ('a' - 'A'));
            }
            else
            {
                printf("%c\n", s[i]);
            }
        }
    }
}