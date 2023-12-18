#include <unistd.h>

int main(int argc, char **argv) // COPIED FROM GITHUB
{
    int i;
    int start;
    int end;
    int flag;

    flag = 0;
    if (argc > 1 && argv[1][0])
    {
        i = 0;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++; // iterate to find first char of 1st word
        start = i; 
        while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++; // iterate to find end of 1st word
        end = i;
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++; // iterate to 2nd word
        while(argv[1][i]) 
        {
            while ((argv[1][i] == ' ' && argv[1][i + 1] == ' ') || (argv[1][i] == '\t' && argv[1][i + 1] == '\t'))
                i++; 
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1; // flag = 0 if input only 1 word
            write(1, &argv[1][i], 1);
            i++;
        }
        if (flag)
            write(1, " ", 1);
        while (start < end)
        {
            write(1, &argv[1][start], 1);
            start++;
        }
    }
    write(1, "\n", 1);
    return(0);
}