#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string agrv[])
{
  //asking user for key
  if (argc != 2)
  {
    printf("missing key\n");
    return 1;
  }

  string key = agrv[1];

  //checking that each char of 'key' is alpha
  for (int i = 0, l = strlen(key); i < l; i++)
  {
    if (isalpha(key[i]))
    {
      key = agrv[1];
    }
    else
    {
      printf("Key must be an alpha\n");
      return 1;
    }
  }

  //asking user for plaintext
  printf("key: %s \n", key);

  for (int i = 0, str_len = strlen(key); i < str_len; i++)
  {
    char index = key[i];
    if (islower(index))
    {
      index -= 97;
      printf("lower capital letter %i\n", index);
    }
    else
    {
      index -= 65;
      printf("is upper letter %i\n", index);
    }
  }

  printf("\n");
  return 0;
}

