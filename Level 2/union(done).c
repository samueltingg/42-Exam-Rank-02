/*
Write a program that takes two strings and displays, without doubles, the
characters that appear in EITHER ONE of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

*/

#include <unistd.h>

int main(int argc, char **argv)
{
    int tab[126] = {0};
    int i;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (-1);
    }
    i = 0;
    while (argv[1][i])
    {
        if (tab[(int)argv[1][i]] == 0)
        {
            write(1, &argv[1][i], 1);
            tab[(int)argv[1][i]] = 1;
        }
        i++;
    }
    i = 0;
    while (argv[2][i])
    {
        if (tab[(int)argv[2][i]] == 0)
        {
            write(1, &argv[2][i], 1);
            tab[(int)argv[2][i]] = 1;
        }
        i++;
    }
}

/*
Planning
- same concept as inter

loop through each string
if tab((int)s[i]) == 0, print
then set tab((int)s[i]) = 1
*/