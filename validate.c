#include "main.h"
#include<string.h>
#include<stdlib.h>

//Read and Validate function
status Read_and_Validate(int argc, char* argv[], List **head)
{
    //initializing head pointer to NULL
    *head = NULL;
     //checking for proper arguments
    if(argc < 2)
{
    printf("-------------------------------------------------------\n");
    printf("| Please Give The Proper Arguments.                    |\n");
    printf("-------------------------------------------------------\n");
    printf("| Please Follow The Below 👇 Arguments As An Input.    |\n");
    printf("-------------------------------------------------------\n");
    printf("| Usage 👉 : ./a.out filename1.txt filename2.txt....   |\n");
    printf("-------------------------------------------------------\n");
    exit(1);
}

    //iterating through all the files
    for(int i = 1; i < argc; i++)
    {
        //opening file pointer
        FILE *ptr;
        //checking file extension
        if(Check_File_Extension(argv[i]) == SUCCESS)
        {
            //checking if file is present
            if(Check_File_Present(argv[i], &ptr) == SUCCESS)
            {
                //checking if file is empty
                if(Check_File_Content(ptr) == SUCCESS)
                {
                    //checking for duplicate file
                    if(No_Duplicate(argv[i], *head) == SUCCESS)
                    {
                        //adding file to linked list
                        if(Add_to_list(head, argv[i], ptr) == SUCCESS)
                        {
                            printf("\nThe File %s is Added to list✅.\n", argv[i]);
                        }
                        else
                        {
                            printf("\nThe File %s is Failed to Add ❌.\n", argv[i]);
                            fclose(ptr);
                        }
                    }
                    else
                    {
                        printf("\nThe File %s is Duplicate❌.\n", argv[i]);
                        fclose(ptr);
                    }
                }
                else
                {
                    printf("\nThe File %s is Empty ❌.\n", argv[i]);
                    fclose(ptr);
                }
            }
            else
            {
                printf("\nThe File %s is Not Available ❌.\n", argv[i]);
            }
        }
        else
        {
            printf("\nThe File %s Has Wrong Extension ❌.\n", argv[i]);
        }
    }

    //checking if head is still NULL
    if (*head == NULL)
    {
        printf("\nNo Valid Files Provided ❌\n");
        exit(1);
    }

    return SUCCESS;
}

//function to check file extension
status Check_File_Extension( char* filename )
{
    //using strstr to find .txt in filename
    char *e = strstr(filename,".txt");
    //if .txt not found or not at the end of filename
    if(e == NULL || strcmp(e, ".txt") != 0)
    {
        return FAILURE;
    }
    //if .txt found and at the end of filename
    return SUCCESS;
}

//function to check if file is present
status Check_File_Present( char* filename, FILE **ptr )
{
    //opening file pointer in read mode
    *ptr = fopen(filename, "r");
    //if file pointer is NULL, file not present
    if(*ptr == NULL)
    {
        return FAILURE;
    }
    //file is present
    return SUCCESS;
}

//function to check if file is empty
status Check_File_Content( FILE *ptr )
{
    //moving file pointer to end of file
    fseek(ptr,0,SEEK_END);
    //if file pointer position is not zero, file is not empty
    if(ftell(ptr) != 0)
    {
        fseek(ptr,0,SEEK_SET);
        return SUCCESS;

    }
    //file is empty
    return FAILURE;
}

//function to check duplicate file
status No_Duplicate( char* filename, List *head )
{
    //if head is NULL, no duplicates
    if(head == NULL)
    {
        return SUCCESS;
    }
    //if head is not NULL, check for duplicates
    List *temp = head;
    while(temp != NULL)
    {
        //comparing filename with each node's filename
        if(strcmp(filename, temp->FILE_NAME) == 0)
        {
            return Duplicate;
        }
        //moving to next node
        temp = temp->next;
    }
    //no duplicates found
    return SUCCESS;
}




