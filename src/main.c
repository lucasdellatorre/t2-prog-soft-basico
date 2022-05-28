#include <stdio.h>
#include <unistd.h>

int main 
(int argc, char **argv) 
{
    char ch;
    while ( (ch = getopt(argc, argv, "h")) != EOF)
    {
        switch (ch)
        {
            case 'h':
                help();
                break;
        }
    }

    argc -= optind;
    argv += optind;
}

void help()
{
    printf("essa eh a saida para flag help")
}