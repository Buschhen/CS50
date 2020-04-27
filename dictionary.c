// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;



// Number of buckets in hash table
const unsigned int N = 26;
unsigned int words = 0;
// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //copy string to make it lowercase
    char copy[strlen(word) + 1];
    strcpy(copy, word);
    char *lcword = copy;
    for (int i = 0; i < strlen(copy); i++)
    {
        lcword[i] = tolower(lcword[i]);
    }
    // get a cursor from where to start serching
    node *cursor = table[hash(lcword)];
    // search for string
    while (cursor != NULL)
    {
        if (strcmp(copy, cursor->word) == 0)
        {
            return true;
            break;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //hash with first letter
    unsigned int index = word[0] - 97;
    return index;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //open file if empty return
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    //make table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char buffer[LENGTH + 1];
    // scan till end of file
    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *new_node = malloc(sizeof(node));

        if (new_node == NULL)
        {
            unload();
            return false;
        }
        //get hash val of string
        unsigned int hash_index = hash(buffer);
        //save word in list
        strcpy(new_node->word, buffer);
        //linke the list to table 
        new_node->next = table[hash_index];
        table[hash_index] = new_node;
        // count up the words in dictionary
        words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // return words
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // loop through hash table
    for (int i = 0; i < N; i++)
    {
        //init first in linked list and free from here
        node *ul = table[i];
        while (ul != NULL)
        {
            node *temp = ul;
            ul = ul->next;
            free(temp);
        }
        free(ul);
    }
    return true;
}

