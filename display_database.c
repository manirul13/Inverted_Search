#include "inverted_Search.h"

void display_database(Wlist *head[])
{
    printf("%-14s  %-22s  %-16s    %s \n", "[index]", "[ word ]     ", "file_count", "    file_names              word_count");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}

int print_word_count(Wlist *head)
{
    while (head)
    {
        printf("[%d]           \t%-16s       \t%d %-11s\t", tolower(head->word[0]) % 97, head->word, (head->file_count),"file/s");
        // Build and print space-separated file names in a buffer
        Ltable *Thead = head->Tlink;
        char file_names[256] = "";
        while (Thead)
        {
            strcat(file_names, Thead->file_name);
            if (Thead->table_link != NULL)
                strcat(file_names, " ");
            Thead = Thead->table_link;
        }
        printf("\t%-15s   ", file_names); // Align file names in 30-char column

        // Now print total word count at the end
        int total_word_count = 0;
        Thead = head->Tlink;
        while (Thead)
        {
            total_word_count += Thead->word_count;
            Thead = Thead->table_link;
        }
        printf(" \t-> %d \n", total_word_count);
        head = head->link;
    }
    return SUCCESS;
}
