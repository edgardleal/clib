
#include <stdio.h>


/**
 * Usage: 
 *   char **array;
 *   array = string_aplit("word1 test program", " " , array);
 *   printf("%s\n", array[0]); // word1
 *   printf("%s\n", array[1]); // test
 *   printf("%s\n", array[2]); // program
 *
 * **result : is a pointer to a bi dimensional array 
 */
char ** string_split(char *origin,char *delimiter, char **result)
{
  char *p;
  int delimiter_count = 1;

  p = strtok(origin, delimiter);
  while(p != NULL)
  {
    if(delimiter_count == 1)
    {
      result = (char **)malloc(1 * sizeof(char *));
      if(result == NULL)
      {
        perror("Error allocating meory\n");
        exit(1);
      }
    }
    else
    {
      result = (char **)realloc(result, sizeof(char *) * delimiter_count);
    }
    result[delimiter_count - 1] = p;
    delimiter_count = delimiter_count + 1;
    p = strtok(NULL, delimiter);
  }
  return result;
}


