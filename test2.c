#include <stdio.h>
#include <stdlib.h>

int array_len(void *array, int size)
{
    int i = 0;
    
    while (*((char **)array) != NULL)
    {
        array = (char **)array + 1; // Increment by the size of a pointer
        i++;
    }
    return i;
}

int main(void)
{
    char **map1;
    char *map2[6] = { "arr", "sss", "sjd", "asd", "dfg", NULL };
    int i;
    int j;

    map1 = (char **)calloc(6, sizeof(char *));
    i = -1;
    while (++i < 5)
    {
        map1[i] = (char *)calloc(4, sizeof(char));
        j = -1;
        while (++j < 2)
            map1[i][j] = 'a';
        map1[i][j] = '\0';
    }

    printf("%d\n", array_len(map2, sizeof(char *)));
    printf("%d\n", array_len(map1, sizeof(char **)));
	printf("%d\n", array_len(map2[0], sizeof(char)));
	printf("%d\n", array_len(map1[0], sizeof(char)));
    i = -1;
    while (++i < 6)
    {
        free(map1[i]);
    }
    free(map1);

    return 0;
}