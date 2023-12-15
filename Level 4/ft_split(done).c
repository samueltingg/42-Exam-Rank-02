/*
Allowed functions: malloc

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.
*/

#include <stdlib.h>

int	if_sep(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	count_words(char *str)
{
	int	flag;
	int	count;

	flag = 0;
	count = 0;
	while (*str)
	{
		if (!flag && !if_sep(*str))
		{
			flag = 1;
			count++;
		}
		if (if_sep(*str))
			flag = 0;
		str++;
	}
	return (count);
}

// assume str given has not space infront
int	strlen_sep(char *str)
{
	int	count;

	count = 0;
	while (!if_sep(str[count]) && str[count])
		count++;
	return (count);
}

char	**ft_split(char *str)
{
	int		i;
	int		j;
	char	**array;
    int word_count;

    if (!str)
        return (NULL);
    word_count = count_words(str);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (array == NULL)
		return (NULL);
	array[word_count] = NULL;
	i = 0;
	while (array[i]) // changed
	{
		while (*str && if_sep(*str))
			str++;
		array[i] = (char *)malloc(sizeof(char) * (strlen_sep(str) + 1));
        if (array[i] == NULL)
            return (NULL);
		j = 0;
		while (*str && !if_sep(*str))
		{
			array[i][j++] = *str; // not sure about j
			str++;
		}
        array[i][j] = '\0';
		i++;
	}
    return (array);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	**str_arr;
// 	int		i;

// 	str_arr = ft_split("hi hii hii ");
// 	i = 0;
// 	while (str_arr[i])
// 	{
// 		printf("str: %s\n", str_arr[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (str_arr[i] != NULL)
// 	{
// 		free(str_arr[i]);
// 		i++;
// 	}
// 	free(str_arr);
// }

/*
Functions needed:
1. count_words
	- flag method
	while
		*if character is met right after sp
		if(str[i] != sp && flag == 0)
			flag = 1
			count++;
		if (sp)
			str++;
2. strlen_sep

STRUCTURE
- malloc outer array based on (word_count + 1)
while ()
{
	- while -> skip all spaces
	- malloc array for each word (based on strlen_sep)
	while (loop till sp or \0 is found)
	{
		- array[j][k] = str[i]
	}
	- null-terminate
}
- set last array as null
*/