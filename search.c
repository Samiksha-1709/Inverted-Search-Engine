//search.c
#include "main.h"
#include <strings.h> // for strcasecmp

// Search the database for a specific word
status Search_Database(HASH_T* H_TABLE, char* word)
{
    // Check if database is empty
    int is_empty = 1;
    for (int i = 0; i < 27; i++)
    {
        if (H_TABLE[i].next != NULL)
        {
            is_empty = 0;
            break;
        }
    }

    if (is_empty)
    {
        
        printf("First Create The Database And Then Search 🔴\n");
        return FAILURE;
    }

    // Find the index in the hash table
    int idx = Find_index(word[0]);
    MAIN_NODE *main_node = H_TABLE[idx].next;

    while (main_node != NULL)
    {
        // Case-insensitive comparison
        if (strcasecmp(main_node->word, word) == 0)
        {
            printf("\n===================================================================\n");
            printf(" Word: %-20s | Found in %ld file%s\n",
                main_node->word,
                main_node->file_count,
                (main_node->file_count > 1 ? "s" : "")
            );
            printf("\n===================================================================\n");

            SUB_NODE *sub_node = main_node->next_sub_node;
            No_of_Files file_no = 1;

            while (sub_node != NULL)
            {
                printf(" [%02ld] %-25s → %3ld Occurrence%s\n",
                    file_no++,
                    sub_node->file_name,
                    sub_node->word_count,
                    (sub_node->word_count > 1 ? "s" : "")
                );
                sub_node = sub_node->next;
            }

            printf("\n===================================================================\n");
            printf("\nSearching Operation Successful ✅\n");
            return SUCCESS;
        }

        main_node = main_node->next_main_node;
    }

    // Word not found in database
    printf("\nWord '%s' Is NOT Found In The Database ❌\n", word);
    return FAILURE;
}
