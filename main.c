#include "inverted_Search.h"

int main(int argc, char *argv[])
{
    system("clear");

    Wlist *head[27] = {NULL};
    // Validation of CLA
    if (argc <= 1)
    {
        printf("Enter the valid no. arguments\n");
        printf("./Slist.exe file1.txt file2.txt ....\n");
        return 0;
    }

    // create file LL
    Flist *f_head = NULL;

    // file validation
    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf("No files are added to file linked list\n");
        printf("Hence the process got terminated\n");
        return 1;
    }
    int choice;
    char options;
    char word[WORD_SIZE];
    do
    {
        // Select your choice among following options:
        printf("\nSelect your choice among following options:\n");
        printf("1. Create Database\n");
        printf("2. Display Database\n");
        printf("3. Update Database\n");
        printf("4. Search\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {

        case 1:
            create_database(f_head, head, f_head->file_name);
            break;
        case 2:
            display_database(head);
            break;
        case 3:
            update_database(head, &f_head);
            break;
        case 4:
            printf("Enter the word to search\n");
            scanf("%s", word);

            int index = tolower(word[0]) % 97;
            if (index < 0 || index > 25)
                index = 26;
            search(head[index], word);
            break;
        case 5:
            save_database(head);
            break;
        case 6:
            exit(0);
        default:
            printf("Enter the valid choice\n");
        }

        printf("Do you want to continue(y/n) : ");
        scanf(" %c", &options);

    } while (options == 'Y' || options == 'y');

    return 0;
}
