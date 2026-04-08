//create Database.c
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//function to initialize hash table
void Initialize_Hash_table(HASH_T *hash_t)
{
    //initializing each index of hash table
    for (int i = 0; i < 27; i++)
    {
        //initializing index and next pointer
        hash_t[i].index = i;
        hash_t[i].next = NULL;
    }
}

//function to find index based on first character
INDEX Find_index(char ch)
{
    //converting character to lowercase
    ch = tolower(ch);
    return (ch >= 'a' && ch <= 'z') ? (ch - 'a') : 26;
}

//function to create sub node
SUB_NODE* Create_sub_node(char *filename)
{
    //allocating memory for sub node
    SUB_NODE *new_sub_node = malloc(sizeof(SUB_NODE));
    if (!new_sub_node)
    {
        perror("Failed to allocate memory for sub-node");
        return NULL;
    }

//initializing sub node fields
    strcpy(new_sub_node->file_name, filename);
    new_sub_node->word_count = 1;
    new_sub_node->next = NULL;

    return new_sub_node;
}

//function to create main node
MAIN_NODE* Create_main_node(char *word, char *filename)
{
    //allocating memory for main node
    MAIN_NODE *new_main_node = malloc(sizeof(MAIN_NODE));
    if (!new_main_node)
    {
        perror("Failed to allocate memory for main-node");
        return NULL;
    }

    //initializing main node fields
    strcpy(new_main_node->word, word);
    new_main_node->file_count = 1;
    new_main_node->next_main_node = NULL;
      
    //creating sub node for the main node
    SUB_NODE *sub = Create_sub_node(filename);
    //checking if sub node creation was successful
    if (!sub)
    {
        //freeing main node memory if sub node creation failed
        free(new_main_node);
        return NULL;
    }
    //linking sub node to main node
    new_main_node->next_sub_node = sub;
    return new_main_node;
}


status Insert_to_hash_table(int index, char *word, char *filename, HASH_T *Hash_t)
{
    // Convert word to lowercase
    for (int i = 0; word[i]; i++)
        word[i] = tolower(word[i]);

    MAIN_NODE *M_temp = Hash_t[index].next;
    MAIN_NODE *prev_main = NULL;

    // Find if word exists in hash table
    while (M_temp)
    {
        if (strcmp(M_temp->word, word) == 0)
            break;
        prev_main = M_temp;
        M_temp = M_temp->next_main_node;
    }

    // Word not present, create new main node
    if (!M_temp)
    {
        MAIN_NODE *new_main = Create_main_node(word, filename);
        if (!new_main) return FAILURE;
        if (!prev_main)
            Hash_t[index].next = new_main;
        else
            prev_main->next_main_node = new_main;
        return SUCCESS;
    }

    // Word exists, check if file exists
    SUB_NODE *S_temp = M_temp->next_sub_node;
    SUB_NODE *last_sub = NULL;
    while (S_temp)
    {
        if (strcmp(S_temp->file_name, filename) == 0)
        {
            // Increment word count in same file
            S_temp->word_count++;
            return SUCCESS;
        }
        last_sub = S_temp;
        S_temp = S_temp->next;
    }

    // File not present for this word, create new sub-node
    SUB_NODE *new_sub = Create_sub_node(filename);
    if (!new_sub) return FAILURE;

    if (!last_sub)
        M_temp->next_sub_node = new_sub;
    else
        last_sub->next = new_sub;

    M_temp->file_count++;
    return SUCCESS;
}




//function to check if file is already indexed
status File_Already_Indexed(const char *fname, HASH_T *hash_t)
{
    for (int i = 0; i < 27; i++)
    {
        //creating main node pointer
        MAIN_NODE *main = hash_t[i].next;
        while (main)
        {
            SUB_NODE *sub = main->next_sub_node;
            while (sub)
            {
                if (strcmp(sub->file_name, fname) == 0)
                    return Exists;

                sub = sub->next;
            }
            main = main->next_main_node;
        }
    }
    return Not_Exists;
}

//function to create database
status Create_Database(HASH_T *hash_t, List **head)
{
    //checking if hash table and head pointer are valid
    if (!hash_t || !head || !*head)
    {
        printf("\nNo files are provided to add into the database.\n");
        return FAILURE;
    }

    //traversing the linked list of files
    List *temp1 = *head;

    while (temp1)
    {
        //checking if file is already indexed
        if (File_Already_Indexed(temp1->FILE_NAME, hash_t) == Exists)
        {
            printf("\nThe File %s is already present in the database.\n", temp1->FILE_NAME);
            temp1 = temp1->next;
            continue;
        }

        //creating a buffer for reading words
        char string[WORD_LENGTH];
        rewind(temp1->ptr); // Ensure reading from the start

        //reading words from the file
        while (fscanf(temp1->ptr, "%s", string) != EOF)
        {
            //finding index for the word
            int idx = Find_index(string[0]);
            //inserting word into hash table
            Insert_to_hash_table(idx, string, temp1->FILE_NAME, hash_t);
        }

        //moving to the next file in the list
        temp1 = temp1->next;
    }

    return SUCCESS;
}
