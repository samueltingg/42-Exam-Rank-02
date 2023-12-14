/*
Allowed functions: malloc

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.
*/

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
    if (nbr < 0)
    {

    }
}


/*
Functions needed: count_digit(count -ve sign) 

STRUCTURE
- malloc based on digit_count
- if -ve nb
    - malloc +1 for '-'
    - nb = -nb
    - str[0] = '-'
- transfer 
    i = digit_count - 1
    while (i)
        str[i] = nb % 10
        nb / 10
        i--;
*/

