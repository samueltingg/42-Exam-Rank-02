#include <stdio.h>
#include <stdlib.h>

// is_prime func is OPTIONAL
// int is_prime(int nb) 
// {
//     int i;

//     if (nb == 2 || nb == 3 || nb == 5)
//         return (1);
//     if (nb % 2 == 0 || nb % 3== 0 || nb % 5==0)
//         return (0);
//     i = 5;
//     while (i <= 46430 && i * i <= nb) // TAKE NOTE: include "i <= 46430"
//     {
//         if (nb % i == 0) 
//             return (0);
//         i++;    
//     }
//     return (1);
// }

int main (int argc, char **argv)
{
    int i; 
    int not_first;

    if (argc != 2)
    {
        printf("\n");
        return (-1);
    }
    int nb = atoi(argv[1]);
    if (/*is_prime(nb) ||*/ nb == 1)
    {
        printf ("%i", nb);
        printf("\n");
        return (0);
    }
    not_first = 0;
    i = 2;
    while ((i <= nb)) // efficient as nb gets smaller as i gets bigger 
    {
        // if (is_prime(nb))
        // {
        //     printf("*");
        //     printf("%i", nb);
        //     printf ("\n");
        //     return (0);
        // }
        if (nb % i == 0)
        {
            if (not_first) // if not 1st nb 
                printf ("*");
            printf("%i", i);
            not_first = 1;
            nb /= i;
            i = 1;
        }
        i++;
    }
    printf ("\n");
}

// /*
// Error:
// - 20 (order)

// */f

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char *argv[])
// {
// 	int	i;
// 	int	number;

// 	if (argc == 2)
// 	{
// 		i = 1;
// 		number = atoi(argv[1]);
// 		if (number == 1)
// 			printf("1");
// 		while (number >= ++i)
// 		{
// 			if (number % i == 0)
// 			{
// 				printf("%d", i);
// 				if (number == i)
// 					break ;
// 				printf("*");
// 				number /= i;
// 				i = 1;
// 			}
// 		}
// 	}
// 	printf("\n");
// 	return (0);
// }