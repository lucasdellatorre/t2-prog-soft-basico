#include <stdio.h>
#include <unistd.h>

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
        }
    }

    argc -= optind;
    argv += optind;
}

void help()
{
    printf("essa eh a saida para flag help");
}

void version()
{
    printf("essa eh a saida para flag help");
}