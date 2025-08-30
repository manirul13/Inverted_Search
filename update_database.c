#include "inverted_Search.h"

int update_database(Wlist *head[], Flist **f_head)
{
  char filename[FNAME_SIZE];
  // prompt the user for the new file
  printf("Enter the file name\n");
  scanf("%s", filename);

  // Check if fileexists and is not empty
  int empty = isFileEmpty(filename);
  if (empty == FILE_NOTAVAILABLE)
  {
    printf("File: %s is not available\n", filename);
    return FAILURE;
  }
  else if (empty == FILE_EMPTY)
  {
    printf("File: %s is empty\n", filename);
    return FAILURE;
  }
  else
  {
    printf("Database updated successfully with file %s\n", filename);
  }

  // Check if file already exists in the list
  Flist *temp = *f_head;
  while (temp)
  {
    if (!(strcmp((temp)->file_name, filename)))
    {
      // create_database(*f_head, head, filename);
      return FAILURE;
    }
    temp = (temp)->link;
  }

  // Add file to file list
  int ret_val = to_create_list_of_files(f_head, filename);
  if (ret_val != SUCCESS)
  {
    printf("Failed to add file %s to database\n", filename);
    return FAILURE;
  }

  // Find the last added file
  temp = *f_head;
  while (temp->link != NULL)
    temp = temp->link;

  // Update database with the new file
  read_datafile(temp, head, filename);
  printf("Database updated successfully with file %s\n", filename);
  return SUCCESS;
}