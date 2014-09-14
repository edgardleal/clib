#include <time.h>


char* formate(char* pattern)
{
// TODO: modificar para receber o buffer de saida
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

        return outstr;
}
