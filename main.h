
//header files.
#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//macro definitions
//define file name length
#define FILENAME 4096
//define word length
#define WORD_LENGTH 100

//structure definitions
//status enum
typedef enum
{
 SUCCESS,
 FAILURE,
 File_Not_Found,
 Duplicate,
 Empty,
 Not_Exists,
 Exists

}status;

//type definitions
typedef char WORD[WORD_LENGTH];
typedef int INDEX;
typedef void DISPLAY;
typedef char File_Name[FILENAME];
typedef long int No_of_Files;
typedef long int Word_Count;


//linked list to store file names
typedef struct node
{
   
    char FILE_NAME[FILENAME];
    FILE *ptr;
    struct node *next;
}List;

//structure for sub node
typedef struct sub_node{
    
    File_Name file_name;
    Word_Count word_count;
    struct sub_node *next;
}SUB_NODE;

//structure for main node
typedef struct main_node
{
    WORD word;
    No_of_Files file_count;
    struct sub_node *next_sub_node;
    struct main_node *next_main_node;
    
    
}MAIN_NODE;

//structure for hash table
typedef struct Hash_table{
    int index;
    struct main_node *next;

}HASH_T;



//functions prototypes

// Read and Validate
status Read_and_Validate( int argc, char* argv[], List **head );

// To check extension is .txt
status Check_File_Extension( char* filename );

// To check if file is present
status Check_File_Present( char* filename, FILE **ptr );

// To check if file empty
status Check_File_Content( FILE *ptr );

// To check duplicate file
status No_Duplicate( char* filename, List *head );


//To find index 
INDEX Find_index(char ch);

//To Create sub node
SUB_NODE* Create_sub_node(char *filename);

//To Initialize hash table
void Initialize_Hash_table(HASH_T *hash_t);

//To Create database
status Create_Database(HASH_T *hash_t, List **head);

//To Create main node
MAIN_NODE* Create_main_node(char* word, char* filename);

//To Insert to hash table
status Insert_to_hash_table(int index, char* word, char* filename, HASH_T *Hash_t);

//To display database
DISPLAY Display_Database(HASH_T* H_Table);

//To search database
status Search_Database(HASH_T* H_TABLE, char* word);

//To display menu
void Display_Menu();

//To print linked list
status print_list(List *head);

//To add to linked list
status Add_to_list(List **head, char *filename, FILE *ptr);

//To save database
status save_database(HASH_T *H_Table);

//To load database
status update_database(HASH_T* H_Table, List **head);

//To check if file already indexed
status File_Already_Indexed(const char *fname, HASH_T* hash_t);


#endif