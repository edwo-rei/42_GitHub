#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int		number;
	struct node	*next;
}			node;

int	main(int argc, char *argv[])
{
	int	i;
	int	number;
	node	*list;
	node	*ptr;
	node	*n;

	list = NULL;
	i = 1;
	//do the following for each command line arg
	while (i < argc)
	{
		number = atoi(argv[i]);
		n = malloc(sizeof(node));
		if (!n)
		{
			//free memory used thus far?
			return (1);
		}
		n->number = number;
		n->next = NULL;
		ptr = list;
		// If list is empty
		if (list == NULL)
			// This node is the whole list
			list = n;
		else
		{
			// Loop thru list until next is NULL
			while (ptr->next)
				ptr=ptr->next;
			// Then append newly created node
			ptr->next = n;
		}
		i++;
	}
	ptr = list;
	while (ptr)
	{
		printf("%i\n", ptr->number);
		ptr = ptr->next;
	}
}
