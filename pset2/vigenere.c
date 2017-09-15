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
    printf("missing key - string needed\n");
    return 1;
  }

  //save key as string
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
  printf("plaintext: ");
  string plain_text = get_string();

  printf("ciphertext: ");


  // iterating over i'th char of plain_text
  for (int i = 0, j = 0, text_len = strlen(plain_text); i < text_len; i++)
  {

    int key_length = strlen(key);
    char letter = plain_text[i];

    //this will keep track of index_key to walkaround
    j = j % key_length;
    char index_key = key[j];

    // getting value of index
    if (islower(index_key))
    {
      index_key -= 97;
    }
    else if (isupper(index_key))
    {
      index_key -= 65;
    }

    //encoding each element of plain_text with received index_key from above
    if (islower(letter))
    {
      letter = (((letter - 97) + index_key) % 26) + 97;
      j++;
      printf("%c", letter);
    }
    else if (isupper(letter))
    {
      letter = (((letter - 65 ) + index_key ) % 26) + 65;

      j++;
      printf("%c", letter);
    }
    //if not A-Z or a-z
    else
    {
      printf("%c", letter);
    }
  }

  printf("\n");
  return 0;
}
