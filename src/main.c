#include <stdio.h>
#include "./fileutils.c"
#include "./dateutils.c"



int main(int arg_count, char* args[])
{
    printf("%s\n", formate("%d/%m/%Y"));
    int i = 0;
    for(i = 0; i < arg_count; i = i+1)
    {
        printf("Argumento [%d] = '%s'\n", i, args[i]);
    }
    printf("Done");
    append_to_file("executions.txt", "A");
    return 0;
}
