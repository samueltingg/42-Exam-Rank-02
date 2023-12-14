/*
Allowed functions:

Write a function who takes two unsigned int as parameters and returns the
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the
smallest postive integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/

#include <limits.h>

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	larger_nb;
	unsigned int	n;

	if (!a || !b)
		return (0);
	if (a > b)
		larger_nb = a;
	else 
		larger_nb = b;
	n = larger_nb;
	while (1)
	{
		if (n % a == 0 && n % b == 0) // include both as not sure which will be bigger
			return (n);
		if (!(n + larger_nb > UINT_MAX))
			n += larger_nb;
	}
	
}
#include <stdio.h>
int	main(void)
{
	printf("%i", lcm(7, 3));
}

/*
1. iterate through multiples of larger number
2. if that multiple can be divided by the other number,
	that multiple is LCM


----- Prime Factorization Method -----
- multiple highest power of each prime factor involved
eg.LCM of 4 and 6:
Prime factorization of 4: 2^2
Prime factorization of 6: 2 x 3^3
LCM: 2^2 x 3 = 12

*/

