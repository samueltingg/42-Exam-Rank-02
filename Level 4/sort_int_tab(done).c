/*
Write the following function:

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent.
*/

// BUBBLE SORT

void sort_int_tab(int *tab, unsigned int size)
{
    int i;
    int j;
    int tmp;

    i = 0;
    while (i < (size - 1))
    {
        j = i;

        while (j < (size - 1 - i))
        {
            if (tab[j] > tab[j + 1])
            {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }   
}

/*
- 2 ptrs

while (tab[i])
{
    j = i
    while tab[j] > tab[j + 1]
    {
        swap
        j++;
    }
    i++;
}

*/

