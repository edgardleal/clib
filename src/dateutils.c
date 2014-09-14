#include <time.h>
#include <string.h>


void formate(char* pattern, char* out)
{
	char outstr[200];
        time_t t;
        struct tm *tmp;

        t = time(NULL);
        tmp = localtime(&t);
        if (tmp == NULL) {
		perror("localtime");
        }

        if (strftime(outstr, sizeof(outstr), pattern, tmp) == 0) {
		fprintf(stderr, "strftime returned 0");
        }
        strcpy(out, outstr);
        return ;
}
