#include <stdio.h>
#include "./fileutils.c"
#include "./dateutils.c"



int main(int arg_count, char* args[])
{
    char* date;
    date = (char*)malloc(50 * sizeof(char) + 1);
    formate("%d/%m/%Y", date);
    printf("%s\n", date);
    int i = 0;
    for(i = 0; i < arg_count; i = i+1)
    {
        printf("Argumento [%d] = '%s'\n", i, args[i]);
    }
    printf("Done");
    append_to_file("executions.txt", "A");

    return 0;
}
