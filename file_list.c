#include "inverted_Search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1 , empty; 
    while(argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        
        if(empty == FILE_NOTAVAILABLE)
        {
            printf("File : %s is not available\n" , argv[i]);
            printf("Hence we are not adding that file to file linked list\n");
            i++;
            continue;
        }

        else if(empty == FILE_EMPTY)
        {
            printf("File : %s is not having any content \n", argv[i]);
            printf("Hence we are not adding that file to file linked list\n");
            i++;
            continue;
        }

        else
        {
            int ret_val = to_create_list_of_files(f_head , argv[i]);
            if(ret_val == SUCCESS)
            {
                printf("Successfully inserted the file %s into file linked list\n" , argv[i]);
            }
            else if(ret_val == REPEATATION)
            {
                printf("This file name : %s is repeated\n", argv[i]);
                printf("Hence we are not adding it to file linked list\n");
            }
            else
            {
                printf("Failure\n");
            }
            i++;
            continue;
        }
    
    }
}

//fun() will check for file availability and for file contents 
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename , "r");
    if(fptr == NULL)
    {
        if(errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
    }

    //check for file content 
    fseek(fptr , 0, SEEK_END);
    if(ftell(fptr) == 0)
    {
        return FILE_EMPTY;
    }
    fclose(fptr);
    return SUCCESS;
}

int to_create_list_of_files(Flist **f_head, char *name)
{
    //create new file node
    Flist *new = malloc(sizeof(Flist));
    if(new == NULL)
        return FAILURE;

    strcpy(new->file_name, name);
    new->link = NULL;
    
    //if list is empty
    if(*f_head == NULL)
    {
        *f_head = new;
        return SUCCESS;
    }

    //Check for duplicate
    Flist *temp = *f_head;
    while(temp->link)
    {
        if(!strcmp(temp->file_name, name))
        {
            free(new);
            return REPEATATION;
        }
        temp = temp->link;
    }

    //check last node
    if(!strcmp(temp->file_name, name))
    {
        free(new);
        return REPEATATION;
    }

    //Add new node at last
    temp->link = new;
    return SUCCESS;
}

int hash_function(const char *word)
{
    if (!isalpha(word[0]))
        return 26;
    return tolower(word[0]) % 97;
}

// int isfileexist(char *filename)
// {
    
// }