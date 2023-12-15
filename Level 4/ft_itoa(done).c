/*
Allowed functions: malloc

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.
*/

#include <stdlib.h>

long count_digit(long nbr)
{
    int count;

    count = 0;
    if (nbr == 0)
        return (1);
    else if (nbr < 0)
    {
        count++;
        nbr = -nbr;
    }
    while (nbr > 0)
    {
        count++;
        nbr = nbr / 10;
    }
    return (count);
}

char	*ft_itoa(int nbr)
{
    char    *str;
    long i;
    long digit_count;
    long nb;

    nb = (long)nbr;
    digit_count = count_digit(nb);
    str = (char *)malloc(sizeof(char) * (digit_count + 1));
    if (nb < 0)
    {
        str[0] = '-';
        nb = -nb; 
    }
    else if(nb == 0)
        str[0] = '0';
    i = digit_count - 1;
    while (nb > 0) // take note
    {
        str[i] = (nb % 10) + '0';
        nb = nb / 10;
        i--;
    }
    str[digit_count] = '\0'; // take note
    return (str);
}
#include <stdio.h>

// int main(void)
// {
//     int num = 2147483647;
//     char    *ptr = ft_itoa(num);
//     printf ("%li\n", count_digit(num));
//     printf ("|%s|\n", ptr);

//     free (ptr);
//     return (0);
// }

/*
count_digit
    - inclusive of -ve sign
    - if 0, count == 1

STRUCTURE
- malloc based on digit_count
- if -ve nb
    - malloc +1 for '-'
    - nb = -nb
    - str[0] = '-'
- if nb == 0??
- transfer 
    i = digit_count - 1
    while (i >= 0)
        str[i] = nb % 10
        nb / 10
        i--;
*/

