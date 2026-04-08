// update.c
#include "main.h"

// Function to update the database with a new file
status update_database(HASH_T *H_Table, List **head)
{
    char filename[256];
    printf("\nEnter the filename to update from : ");
    scanf("%255s", filename);

    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL)
    {
        printf("\nError: '%s' file not found or cannot be opened ❌\n", filename);
        return FAILURE;
    }

    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        printf("\nError: '%s' is empty ❌\n", filename);
        fclose(fptr);
        return FAILURE;
    }
    rewind(fptr);

    // Check if file already indexed
    if (File_Already_Indexed(filename, H_Table) == Exists)
    {
        printf("\nNo new data found in '%s'. Database remains unchanged.\n", filename);
        fclose(fptr);
        return SUCCESS;
    }

    // Read words from the file and insert into hash table
    INDEX index;
    WORD word;

    while (fscanf(fptr, "%s", word) != EOF)
    {
        index = Find_index(word[0]);
        Insert_to_hash_table(index, word, filename, H_Table);
    }

    fclose(fptr);

    printf("\nDatabase Successfully Updated from '%s' ✅\n", filename);
    return SUCCESS;
}
