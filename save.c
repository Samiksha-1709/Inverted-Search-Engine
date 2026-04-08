//save.c
#include "main.h"

//function to save database to a file
status save_database(HASH_T *H_Table)
{
    //filename to save database
    char filename[256] = "Saved_DataBase.txt";
    //open file in read mode 
    FILE* check = fopen(filename, "r");

    //check if file already exists
    if(check)
    {
        fclose(check);
        printf("\nSave File '%s' Already Exists.\n", filename);
    }
    else
    {
        printf("\nFile '%s' Not Found❌.\n", filename);
    }

    FILE* fptr = fopen(filename, "w");  // Always overwrite
    if(fptr == NULL)
    {
        perror("Could Not Open File To Save Database");
        return FAILURE;
    }
    
    //flag to check if database is empty
    int is_empty = 1;

    for(int i = 0; i < 27; i++)
    {
        MAIN_NODE* main_node = H_Table[i].next;

        while(main_node)
        {
            is_empty = 0;
            fprintf(fptr, "#%d; %s; %ld;", i,
                    main_node->word,
                    main_node->file_count);

            SUB_NODE* sub_node = main_node->next_sub_node;
            while(sub_node)
            {
                fprintf(fptr, " %s; %ld;", sub_node->file_name, sub_node->word_count);
                sub_node = sub_node->next;
            }
            fprintf(fptr, " #\n");

            main_node = main_node->next_main_node;
        }
    }

    if(is_empty)
        printf("No Database Data To Save❌.\n");

    fclose(fptr);

    printf("\nDatabase Successfully Saved To '%s' ✅\n", filename);

    return SUCCESS;
}
