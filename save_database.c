#include "inverted_Search.h"

int save_database(Wlist *head[])
{
    char file_name[FNAME_SIZE];
    printf("Enter the filename\n");
    scanf("%s", file_name);

    FILE *fptr = fopen(file_name, "w");
    if (fptr == NULL)
    {
        printf("Error opening file to save database.\n");
        return FAILURE;
    }
    for (int i = 0; i < 27; i++)
    {
        if (head[i] != NULL)
        {
            write_databasefile(head[i], &fptr);
        }
    }

    fclose(fptr);
    printf("Database saved to disk.\n");
    return SUCCESS;
}
void write_databasefile(Wlist *head, FILE **databasefile)
{
     // #[index]  :  word is : [word] :  file_count : [%d] : file_name : [%s] : word_count : %d
    while (head)
    {
        fprintf(*databasefile, "#[%d] : word is : [%s] : file_count : [%d] : ",
                tolower(head->word[0]) % 97, head->word, head->file_count);
        Ltable *Thead = head->Tlink;
        while (Thead)
        {
            fprintf(*databasefile, "file_name : [%s] : word_count : %d",
                    Thead->file_name, Thead->word_count);
            Thead = Thead->table_link;
            if (Thead != NULL)
                fprintf(*databasefile, " : ");
        }
        fprintf(*databasefile, "\n");
        head = head->link;
    }
}