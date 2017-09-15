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

  int key = atoi(agrv[1]);

  //asking user for plaintext
  printf("plaintext: ");
  string plain_text = get_string();

  printf("ciphertext: ");

  //iterate over each char in string
  for (int i = 0, l = strlen(plain_text); i < l; i++)
  {

    //checking if char is an alpha
    if (isalpha(plain_text[i]))
    {
      char letter = plain_text[i];

      //checking if letter is upper case or lowercase
      if (islower(letter))
      {
        //to change letter from ascii to alph we have to - 97 then we can work the %26 and after we have to add 97 to make it ascii again
        letter = ((letter + key) - 97) % 26 + 97;
      }
      else if (isupper(letter))
      {
        letter = ((letter + key) - 65) % 26 + 65;
      }
      printf("%c", letter);
    }
    else
    {
      printf("%c", plain_text[i]);
    }
  }

  printf("\n");
  return 0;
}

