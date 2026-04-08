//display.c
#include "main.h"
#include <stdio.h>

DISPLAY Display_Database(HASH_T* H_Table)
{
    printf("\n```````````````````````````````````````````````````````````````````````````````````````\n");
    printf("\t\t\t\t   \033[1mDATABASE\033[0m\n");
    printf("\n```````````````````````````````````````````````````````````````````````````````````````\n");
    printf("| %-3s | %-15s | %-8s | %-20s | %-15s |\n", "Idx","Word","Files","File Name","Word Count");
    printf("|-----|-----------------|----------|----------------------|-----------------|\n");

    int is_null = 1;

    for(int i = 0; i < 27; i++)
    {
        MAIN_NODE *main_node = H_Table[i].next;
        while(main_node)
        {
            is_null = 0;
            SUB_NODE *sub_node = main_node->next_sub_node;

            // Print first sub-node with word info
            if(sub_node)
            {
                printf("| %-3d | %-15s | %-8ld | %-20s | %-15ld |\n",
                    i,
                    main_node->word,
                    main_node->file_count,
                    sub_node->file_name,
                    sub_node->word_count
                );

                sub_node = sub_node->next;
            }

            // Print remaining sub-nodes without repeating the word
            while(sub_node)
            {
                printf("| %-3s | %-15s | %-8s | %-20s | %-15ld |\n",
                    "",
                    "",
                    "",
                    sub_node->file_name,
                    sub_node->word_count
                );
                sub_node = sub_node->next;
            }

            main_node = main_node->next_main_node;
        }
    }

    if(is_null)
    {
        printf("| %-68s |\n", " DATABASE IS EMPTY.");
        printf("| %-68s |\n"," FIRST CREATE DATABASE.");
    }

    printf("|-----|-----------------|----------|----------------------|-----------------|\n");
    printf("\n``````````````````````````````````````````````````````````````````````````````````````````\n");
}


//function to display menu
void Display_Menu()
{
    printf("\n");
printf("┌───────────────────────────────────────────────────────────────┐\n");
printf("│                     INVERTED SEARCH MENU                      │\n");
printf("├───────────────────────────────────────────────────────────────┤\n");
printf("│  1) Create Database                                           │\n");
printf("│  2) Display Database                                          │\n");
printf("│  3) Search Database                                           │\n");
printf("│  4) Save Database                                             │\n");
printf("│  5) Update Database                                           │\n");
printf("│  6) Exit                                                      │\n");
printf("└───────────────────────────────────────────────────────────────┘\n");


    
}
