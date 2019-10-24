#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    short n;
    char **prop;
    FILE *f;

    printf("N: ");
    scanf("%hd", &n);
    prop = (char**)malloc(n * sizeof(char*));
    getc(stdin);    // consuma '\n' din stdin

    for (int i = 0; i < n; i++)
    {
        printf("Prop. %d: ", i);
        prop[i] = (char*)malloc(32 * sizeof(char));
        fgets(prop[i], 32, stdin);
        prop[i][strlen(prop[i]) - 1] = 0;   // elimina '\n' din buffer
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(prop[i]); j++)
        {
            if (prop[i][j] == ' ')
            {
                memmove(&prop[i][j], &prop[i][j + 1], strlen(prop[i]) - j);
				j--;
            }
        }
    }

    f = fopen("out.txt", "w");
    for (int i=0; i < n; i++)
    {
        if (strlen(prop[i]) > 3)
        {
            fwrite(prop[i], strlen(prop[i]), 1, f);
			fwrite("\n", 1, 1, f);
        }
    }
	for(int i = 0; i<n; i++){
		free(prop[i]);
	}
    free(prop);
	return 0;
}
