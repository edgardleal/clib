#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_STRING_SIZE 255

int print_line(int line, char* value)
{
    printf("%d %s", line, value);
    return 0;
}

int read_file_with_callback(char* filename, int (*callback)(int line, char*))
{
   FILE *fp;
   char buff[MAX_STRING_SIZE];

   fp = fopen(filename, "r");
   int i = 0;
   if( fp != NULL ){
      while ( !feof(fp ) ){
         i = i + 1;
         memset(buff, '\0', sizeof( buff) );
         fgets(buff, MAX_STRING_SIZE, (FILE*)fp);
         (*callback)(i, buff);
      }
      fclose(fp);
   }
    return 0;
}

// ========================================
int read_file_text(char* filename)
{
   int (*func)(int line, char*);
   func = &print_line;

   read_file_with_callback(filename, func);
   return 0;
}

int file_exists(char *file_name)
{
    if(access(file_name, F_OK ) != -1 ) {
        return 1;
    } else {
        return 0;
    }
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
