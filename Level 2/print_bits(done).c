/*
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.

Example, if you pass 2 to print_bits, it will print "00000010"

*/
#include <unistd.h>

void	print_bits(unsigned char octet)
{
    int i;
    unsigned char bit;

    i = 8;
    while (i)
    {
        i--;
        bit = ((octet >> i) & 1) + '0';
        write(1, &bit, 1);
    }
}

// int main(void)
// {
//     print_bits('0');
// }

/*
Idea:
- print each bit from left to right
- shift each bit (starting more most left) to most right one by one,
- & 1 to print only the bit at most right, as everything on the left will result to 0

*/