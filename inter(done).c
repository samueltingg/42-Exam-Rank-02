/*
Write a program that takes two strings and 
displays, without doubles, the characters that appear in BOTH strings, 
in the order they appear in the first one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/

#include <unistd.h>

void print_chars(char *s1, char *s2)
{
    int tab[126] = {0};
    int i;

    i = 0;
    while (s2[i]) // set all chars present in s2 to "1"
        tab[(int)s2[i++]] = 1;
    i = 0;
    while (s1[i])
    {
        if (tab[(int)s1[i]] == 1)
        {
            write(1, &s1[i], 1);
            tab[(int)s1[i]] = 2;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        write(1, "\n", 1);
        return (-1);
    }
    print_chars(argv[1], argv[2]);
}

/*

while loop - iterate through each char of 1st string

if (ft_strchr(2nd string, current char))
    write(1, &c, 1);

- How to handle doubles

map[126]

1. mark all chars present in s2 as 1 at index corresponding to ascii value of that char
2. if tab[(int)s1[i]] == 1, print! & increment value to 2

*/