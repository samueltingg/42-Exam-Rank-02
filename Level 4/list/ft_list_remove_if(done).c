/*
Allowed functions: free

Write a function called ft_list_remove_if that 
removes from the passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.
*/

#include <stdlib.h>
#include "ft_list.h"

// ITERATIVE METHOD

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *current;
    t_list  *prev;
    t_list  *next;

    current = *begin_list;
    prev = NULL;
    while (current)
    {
        next = current->next;
        if (cmp(current->data, data_ref) == 0)
        {
            if (prev == NULL) // if 1st node
                *begin_list = next;
            else 
                prev->next = next;
            // free(current->data); // if data dynamically allocated
            free(current); 
        }
        else 
            prev = current;
        current = next;
    }
}
/*
- there could be multiple element that are equal to data_ref

- Reason for declaring "next"
    - current->next can't be accessed at end of while, as current has been freed
*/

// #include <stdio.h>
// #include <string.h>

// void	print_list(t_list **begin_list)
// {
// 	t_list *cur = *begin_list;
// 	while (cur != 0)
// 	{
// 		printf("%s\n", cur->data);
// 		cur = cur->next;
// 	}
// }

// int		main(void)
// {
// 	char straa[] = "String aa";
// 	t_list *aa = malloc(sizeof(t_list));
// 	aa->next = 0;
// 	aa->data = straa;

// 	char strbb[] = "String bb";
// 	t_list *bb = malloc(sizeof(t_list));
// 	bb->next = 0;
// 	bb->data = strbb;

// 	char strcc[] = "String cc";
// 	t_list *cc = malloc(sizeof(t_list));
// 	cc->next = 0;
// 	cc->data = strcc;

// 	char strdd[] = "String dd";
// 	t_list *dd = malloc(sizeof(t_list));
// 	dd->next = 0;
// 	dd->data = strdd;

// 	aa->next = bb;
// 	bb->next = cc;
// 	cc->next = dd;

// 	t_list **begin_list = &aa;

// 	print_list(begin_list);
// 	printf("----------\n");
// 	ft_list_remove_if(begin_list, straa, strcmp);
// 	print_list(begin_list);
// }