#include <stdio.h>
#include <stdlib.h>

int comando_ec(int argc, char *argv[])
{
    int i;

    if (argc == 1)
        printf("Sem texto. Digite algo depois do comando.\n");

    else
    {
        for (i = 1; i < argc; i++)
        {
            if (i > 1)
                printf(" ");

        printf("%s", argv[i]);
        }

        printf("\n");

        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
}