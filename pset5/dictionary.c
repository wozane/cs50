/**
 * Implements a dictionary's functionality.
 **/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

#define SIZE 143091

int word_count = 0;

node* hashtable[SIZE];

// hash funciton from http://stackoverflow.com/questions/98153/#98179
int hash_func(const char* word)
{
    /* magic numbers from http://www.isthe.com/chongo/tech/comp/fnv/ */
    size_t InitialFNV = 2166136261U;
    size_t FNVMultiple = 16777619;

    size_t hash = InitialFNV;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash ^= (tolower(word[i]));

        hash *= FNVMultiple;
    }
    return (hash % SIZE);
}

/**
* Returns true if word is in dictionary else false.
*/
bool check(const char* word)
{
    // place for the word in hash table
    node* place = hashtable[hash_func(word)];

    //checking for the word
    for (node* entry = place; entry != NULL; entry = entry->next)
    {
        if (strcasecmp(entry->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

/**
* Loads dictionary into memory.  Returns true if successful else false.
*/

bool load(const char* dictionary)
{
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    while(true)
    {
        node* new_word = malloc(sizeof(node));

        if (new_word == NULL)
        {
            unload();
            fclose(file);
            return false;
        }

        if (fscanf(file, "%45s", new_word->word) != 1)
        {
            free(new_word);
            break;
        }

        int index = hash_func(new_word->word);

        new_word->next = hashtable[index];
        hashtable[index] = new_word;

        word_count++;
    }

    fclose(file);
    return true;
}

/**
* Returns number of words in dictionary if loaded else 0 if not yet loaded.
*/
unsigned int size(void)
{
    return word_count;
}

/**
* Unloads dictionary from memory. Returns true if successful else false.
*/
bool unload(void)
{
    for(int i = 0; i < SIZE; i++)
    {
        node* entry = hashtable[i];
        while(entry != NULL)
        {
            node* next = entry->next;
            free(entry);
            entry = next;
        }
    }
    return true;
}
