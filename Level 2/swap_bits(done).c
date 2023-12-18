/*
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.

Example:

  1 byte
_____________
 0100 | 0001
     \ /
     / \
 0001 | 0100

*/

unsigned char	swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}

/*
TAKE NOTE: include Brackets () !!
*/