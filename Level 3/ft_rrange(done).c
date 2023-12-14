#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int nbr_count;
    int *array;
    int i;

    i = 0;
    if (start > end)
    {
        nbr_count = start - end + 1;
        array = (int *)malloc(sizeof(int) * nbr_count);
        while (i < nbr_count)
        {
            array[i] = end;
            end++;
            i++;
        }
    }
    else
    {
        nbr_count = end - start + 1;
        array = (int *)malloc(sizeof(int) * nbr_count);
        while (i < nbr_count)
        {
            array[i] = end;
            end--;
            i++;
        }
    }
    return (array);
}


// #include <stdio.h>
// int main(void)
// {
//     int arrsize = 1;
//     int *array;
//     array = ft_rrange(0, 0);

//     int i = 0;
//     while (i < arrsize)
//     {
//         printf("%i\n", array[i]);
//         i++;
//     }
// }


/*
2 Cases
    1. start > end - output-> ascending order
    2. start < end - output-> descending order

malloc
    [] count how many nbrs to malloc

Structure
if ()
    - count nbrs
    - malloc
    - transfer 
        while (end >= start))
else()

*/