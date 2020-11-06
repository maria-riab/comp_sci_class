// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"
#include <math.h>
#include <ctype.h>
#include<strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 150000;

unsigned int words_in_dictionary = 0;


// Hash table
node *table[N];


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int n = strlen(word);

    char lower_word[LENGTH + 1];

    strcpy(lower_word, word);

    for (int i = 0; i < n; i++)
    {
        lower_word[i] = tolower(lower_word[i]);
    }

    lower_word[n] = '\0';
   
    int index = hash(lower_word);

    node* temp = table[index];

    if (temp == NULL)
    {
        return false;
    }

    while (temp != NULL)
    {
        if (strcasecmp(temp->word, lower_word) == 0)
        {
            return true;
        }

        temp = temp->next;
    }

    return false;
}


// Hashes word to a number
//found this hash function at: https://stackoverflow.com/questions/14409466/simple-hash-functions
//http://www.cse.yorku.ca/~oz/hash.html
//this function is called sdbm, i dont know why it works

unsigned int hash(const char *word)
{
    unsigned int count;

    unsigned int hash_value = 0;

    for (count = 0; word[count]!='\0'; count++)
    {
        hash_value = word[count] + (hash_value << 6) + (hash_value << 16) - hash_value;
    }

    return hash_value % N;
}







bool load(const char *dictionary)
{
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(file, "%s", word) != EOF)
    {
        node* result = malloc(sizeof(node));
        if (result != NULL)
        {
            strcpy(result->word, word);
            result->next = NULL;
        }
        int hash_value = hash(result->word);

        result->next = table[hash_value];

        table[hash_value] = result;

        words_in_dictionary++;
    }
    fclose(file);

    return true;
}



// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (words_in_dictionary > 0)
    {
        return words_in_dictionary;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            node* temp = table[i];
            node* prev;

            while (temp != NULL)
            {
               prev = temp;
               temp = temp->next;
               free(prev);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (table[i] == NULL)
        {
            return true;
        }
    }
    return false;
}






char* lowercase(const char* word)
{
    char* lower_word = malloc(strlen(word + 1));
    if (lower_word != NULL)
    {
        strcpy(lower_word, word);

        for (int i = 0, n = strlen(word); i < n; i++)
        {
            lower_word[i] = tolower(lower_word[i]);
        }

    }
    
    
    return lower_word;
    free(lower_word);
}






