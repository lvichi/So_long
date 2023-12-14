#include <stdio.h>
#include <stdlib.h>

/*int array_len(void *array)
{
    char	*array_char;
	char	c;
	int  array_check;
    
    array_char = (char *)array;
	c = *array_char;
	array_check = c >> 8;
    
    if (array_check)
        printf("bit work\n");
    else
        printf("bit not\n");
    return (1);
}*/

int	array_len(void *array)
{
	int	array_check;
	int	i;

	i = 0;
	array_check = *((char *)array) >> 8;
	if (array_check)
	{
		while (*((char **)array))
		{
			array = (char **)array + 1;
			i++;
		}
	}
	else
	{
		while(*((char *)array))
		{
			array = (char *)array + 1;
			i++;
		}
	}
	return (i);
}

int main(void)
{
    char **map1;
    char *map2[9] = { "ar", "sss", "sjd", NULL };
	int i, j;

    map1 = (char **)calloc(6, sizeof(char *));
    i = -1;
    while (++i < 5)
    {
        map1[i] = (char *)calloc(7, sizeof(char));
        j = -1;
        while (++j < 6)
            map1[i][j] = 'a';
        map1[i][j] = '\0';
    }

    printf("%d\n", array_len(map1));
    //printf("%d\n", array_len(map2));
    printf("%d\n", array_len(map1[0]));
    //printf("%d\n", array_len(map2[0]));
    //printf("%d\n", array_len(map2));    // Counting strings in array
    //printf("%d\n", array_len(map1));    // Counting strings in array
    //printf("%d\n", array_len(map2[0]));     // Counting characters in string
    //printf("%d\n", array_len(map1[0]));     // Counting characters in string
	printf("sizeof void *: %ld sizeof size_t: %ld sizeof char *: %ld \n", sizeof(void *), sizeof(size_t), sizeof(char *));
    i = -1;
    while (++i < 6)
    {
        free(map1[i]);
    }
    free(map1);

    return 0;
}
