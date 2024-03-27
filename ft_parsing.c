#include "push_swap.h"


// int ft_isspace(char c)
// {
//     if (*c == ' ')
//         return (1);
//     else
//         return 0;
// }
int count_spaces(char *argv[])
{
    int size;
    int i;
    int count;
    int j;
    
    j = 0;
    count = 0;
    i = 1;
    while (argv[i])
    {
        size = ft_strlen(argv[i]);
        printf("size == %d\n", size);
        while (argv[i][j] == ' ')
        {
            count++;
            j++;
        }
        if (size == count)
            return (0);
        i++;
    }
    return (1);
}
// int found_alphas(char *argv[])
// {
//     int i;

//     i = 0;
//     while ()
// }
void ft_error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}