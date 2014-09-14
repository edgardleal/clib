#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 255

int print_line(char* value)
{
    printf("%s", value);
    return 0;
}

// ========================================
int read_file(char* filename)
{
   int (*func)(char*);
   func = &print_line;

   read_file_with_callback(filename, func);
   return 0;
}

int read_file_with_callback(char* filename, void (*callback(char*)))
{
   FILE *fp;
   char buff[MAX_STRING_SIZE];

   fp = fopen(filename, "r");
   if( fp != NULL ){
      while ( !feof(fp ) ){
         memset(buff, '\0', sizeof( buff) );
         fgets(buff, MAX_STRING_SIZE, (FILE*)fp);
         (*callback)(buff);
      }
      fclose(fp);
   }
    return 0;
}

void append_to_file(const char *filepath, const char *data)
{
    FILE *fp = fopen(filepath, "ab");
    if (fp != NULL)
    {
        fputs(data, fp);
        fclose(fp);
    }
}
