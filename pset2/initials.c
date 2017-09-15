#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{

  printf("What is your name?\n");
  string name = get_string();

  //this will capitalize first letter
  printf("%c", toupper(name[0]));

  //this will look for other letters after space and capitalize them
  for (int i = 0, n = strlen(name); i < n; i++)
  {
    if (name[i] == ' ')
    {
      printf("%c", toupper(name[i + 1]));
    }
  }

  //will add new empty line at the end
  printf("\n");
}