#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void help()
{
    printf("essa eh a saida para flag help");
}

void version()
{
    printf("essa eh a saida para flag version");
}

int main 
(int argc, char **argv) 
{
    char ch;
    while ( (ch = getopt(argc, argv, "hv")) != EOF)
    {
        switch (ch)
        {
            case 'h':
                help();
                break;
            case 'v':
                version();
                break;
            default:
                fprintf(stderr, "Opção não conhecida: %s\n", optarg);
                return 1;
        }
    }

    argc -= optind;
    argv += optind;
}
