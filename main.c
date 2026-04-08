/*
Name = Samiksha Mane
Batch = 25023
Project Name = Inverted Search
Description = 
1.->This project is an Inverted Search Engine implemented using Hash Table and Linked List in the C programming language.
2.->The system allows users to create a searchable database from multiple text files by extracting each unique word and 
storing the information about the files in which it appears and how many times.
3.->A hash table is used to index words efficiently, while linked lists are used to maintain file names and occurrence counts.
4.->The application is completely menu-driven and supports various operations including Create Database, Display Database, 
Search Word in Database, Save Database to a File, and Update Database from a Saved File.
5.->The project demonstrates strong usage of file handling, dynamic data structures, string manipulation, and efficient search techniques.
6.->It is useful for retrieving information quickly from large file collections and provides a structured methodology for maintaining and
updating stored textual data. 
7.->This makes the project a great example of practical implementation of data indexing concepts used in real-world search engines.

*/


// main.c
#include "main.h"
//command line arguments to accept multiple files
int main(int argc, char *argv[])
{
    List *head;
    HASH_T H_Table[27];
    int Created_db = 0;
    int Updated_db = 0;
//initializing hash table
    Initialize_Hash_table(H_Table);
//reading and validating files
    if(Read_and_Validate(argc, argv, &head) == SUCCESS)
    {
        printf("\nFiles Are Accepted ✅.");
        print_list(head);
    }
//menu driven program
    while(1)
    {
        //display menu
        Display_Menu();
        printf("\n");
//accepting user choice
        int choice;
        printf("\nEnter Your Choice : ");
        scanf("%d",&choice);
//switch case for different operations
        switch(choice)
        {
            //case 1 for creating database
            case 1:
            if(Created_db != 0)
            {
                printf("\nDatabase Already Exists🔴.\n");
                break;
            }

             Create_Database(H_Table,&head);
             printf("\nDataBase Created Successfully✅.\n");
             Created_db = 1;
             Updated_db = 1;
             break;

            //case 2 for displaying database
             case 2:
             Display_Database(H_Table);
             break;

            //case 3 for searching a word
             case 3:
             char WORD[50];
             printf("\nEnter The Word That You Want To Search 👉: ");
             scanf("%s",WORD);

             Search_Database(H_Table, WORD);
             break;

            //case 4 for saving database
             case 4:
    if (Created_db == 0 && Updated_db == 0)
    {
        printf("\n⚠️ First Create the Database Before Saving!\n");
        break;
    }

    char choice;
    printf("\nDo you want to save the current database to a backup file? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        if (save_database(H_Table) == SUCCESS)
        {
            printf("\n📌 Database Successfully Saved to File.\n");
        }
        else
        {
            printf("\n❌ Failed to Save Database!\n");
        }
    }
    else
    {
        printf("\nSave Cancelled. Returning to Menu...\n");
    }

    break;

            //case 5 for updating database
             case 5:
            if(update_database(H_Table, &head) == SUCCESS)
           {
               Updated_db = 1;
               Created_db = 0;
          }
             break;


    
            //case 6 for exiting program
             case 6:
             {
                List *temp = head;
                while(temp!=NULL)
                {
                    if(temp->ptr != NULL)
                    fclose(temp->ptr);
                    temp = temp->next;
                }

                printf("\nExiting.....!!!.\n");
                exit(0);
             }
             

             //default case for invalid option
             default:
             printf("\n❌ Invalid Options Are Entered ❌");

        }
    }
}