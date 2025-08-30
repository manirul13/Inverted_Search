#include "inverted_Search.h"

char *fname;
int create_database(Flist *f_head, Wlist *head[], char *filename)
{
    // traverse through the file linked list
    while (f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
        printf("You have successfully create the database\n");
    }
    return SUCCESS;
}

// read the content of a file
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{

    fname = filename;
    // open the file in read mode
    FILE *fptr = fopen(filename, "r");

    int flag = 1;

    // declare an array to store the word
    char word[WORD_SIZE];

    while (fscanf(fptr, "%s", word) != EOF)
    {
        // find index
        int index = tolower(word[0]) % 97;

        // other than alphabet
        if (!(index >= 0 && index <= 25))
        {
            index = 26;
        }

        // check whether words are repated or not
        if (head[index] != NULL)
        {
            Wlist *temp = head[index];
            // compare each node word with new word

            while (temp)
            {
                if (!strcmp(temp->word, word))
                {
                    update_word_count(&temp, filename);
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }
        }

        if (flag == 1)
        {
            // words are not repeated
            insert_at_last(&head[index], word);
        }
    }
    return SUCCESS;
}


int update_word_count(Wlist **head, char *file_name)
{
    Ltable *temp = (*head)->Tlink;

    // If no files have been linked yet, create the first Ltable node
    if (temp == NULL)
    {
        Ltable *new_link_table = malloc(sizeof(Ltable));
        if (new_link_table == NULL)
            return FAILURE;

        strcpy(new_link_table->file_name, file_name);
        new_link_table->word_count = 1;
        new_link_table->table_link = NULL;

        (*head)->Tlink = new_link_table;
        (*head)->file_count += 1;
        return SUCCESS;
    }

    // Check if this file already has a record for the word
    Ltable *prev = NULL;
    while (temp)
    {
        if (!strcmp(temp->file_name, file_name))
        {
            temp->word_count += 1;
            return SUCCESS;
        }
        prev = temp;
        temp = temp->table_link;
    }

    // If file not found, add a new Ltable node
    Ltable *new_link_table = malloc(sizeof(Ltable));
    if (new_link_table == NULL)
        return FAILURE;

    strcpy(new_link_table->file_name, file_name);
    new_link_table->word_count = 1;
    new_link_table->table_link = NULL;

    prev->table_link = new_link_table;
    (*head)->file_count += 1;
    return SUCCESS;
}
 