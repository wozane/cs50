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

  int key_length = strlen(key);
  int j = 0;


  // iterating over i'th char of plain_text
  for (int i = 0, text_len = strlen(plain_text); i < text_len; i++)
  {
    char letter = plain_text[i];
    char index = key[i];
    char temp;

    for (int a = 0, str_len = strlen(key); a < str_len; i++)
      {
        index = key[a];
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
        return index;
      }


    //checking if char is an alpha
    if (isalpha(letter))
    {
      if (j == key_length)
      {
        j = 0;
      }

      temp = letter + index;

      printf("%c letter\n %c\n",letter, temp);
      /*
        if (islower(letter))
          {
            letter = (((letter + index) - 97 ) % 26) + 97;
            printf("%c encoded letter\n", letter);
          }
          else
          {
            letter = (((letter + index) - 65 ) % 26) + 65;
            printf("%c encoded letter\n", letter);
          }
        */
      j++;
    }
    else
    {
      printf("%c", plain_text[i]);
    }
  }

  printf("\n");
  return 0;
}
