#include "inverted_Search.h"

int search( Wlist *head, char *word)
{
    //check list is empty or not

    if(head == NULL)
    {
        printf("Search is not possible , as list is empty\n");
        return 0;
    }
    // if list non empty 
    while(head)
    {
        //traverse and compare each node word with search word 
        if(!strcmp(head->word , word))
        {
           printf("Word '%s' is present in %d file/s\n", word , head->file_count);
            Ltable *Thead = head->Tlink;

            while(Thead)
            {
                printf("In file : %s  %d time/s\n", Thead->file_name , Thead->word_count);
                Thead = Thead->table_link;
            }
            return 1;
        }
        head = head->link;
    }

    printf("Search key '%s' not found\n", word);
    return FAILURE;
}